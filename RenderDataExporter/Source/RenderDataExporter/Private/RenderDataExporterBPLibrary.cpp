// Copyright Epic Games, Inc. All Rights Reserved.

#include "RenderDataExporterBPLibrary.h"
#include "RenderDataExporter.h"
#include "JsonObjectConverter.h"
#include "Camera/CameraComponent.h"
#include "RenderDataExporterSettings.h"
#include "EngineUtils.h"
#include "MaterialExporterData.h"
#include "Engine/DirectionalLight.h"
#include "Components/DirectionalLightComponent.h"

static inline uint32 MakeVertexFormat(const TArray<EVertexFormat>& Formats)
{
    uint32 ResultFormat = 0;
    for (auto& Format : Formats)
    {
        ResultFormat += 1 << (uint8)Format;
    }
    return ResultFormat;
}

static void OptionsToFormatList(const FExportStaticMeshOptions& Options, FStaticMeshLODData& Data)
{
    const bool* pOptions = reinterpret_cast<const bool*>(&Options);
    for (uint32 i = 0; i < (uint32)EVertexFormat::MAX; ++i)
    {
        if (pOptions[i])
        {
            Data.Format.Add(static_cast<EVertexFormat>(i));
        }
    }
    Data.FormatBits = MakeVertexFormat(Data.Format);
}

template<uint32 LOD>
static void ExportTexcoordLOD(const FStaticMeshLODResources& LODResource, TArray<float>& Vertices, uint32 i, float ExportUnitScale)
{
    FVector2D Texcoord0 = LODResource.VertexBuffers.StaticMeshVertexBuffer.GetVertexUV(i, LOD);
    Vertices.Append({ Texcoord0.X ,Texcoord0.Y });
}

static TArray<TFunction<void(const FStaticMeshLODResources&, TArray<float>&, uint32, float)>> GExportFunctions = {
    [](const FStaticMeshLODResources& LODResource,TArray<float>& Vertices, uint32 i, float ExportUnitScale) {
        FVector Position = LODResource.VertexBuffers.PositionVertexBuffer.VertexPosition(i);
        Position *= ExportUnitScale;
        Vertices.Append({ Position.X ,Position.Y ,Position.Z });
    },
    [](const FStaticMeshLODResources& LODResource,TArray<float>& Vertices, uint32 i, float ExportUnitScale) {
        FVector Normal = LODResource.VertexBuffers.StaticMeshVertexBuffer.VertexTangentZ(i);
        Vertices.Append({ Normal.X ,Normal.Y ,Normal.Z });
    },
    [](const FStaticMeshLODResources& LODResource,TArray<float>& Vertices, uint32 i, float ExportUnitScale) {
        ExportTexcoordLOD<0>(LODResource, Vertices, i, ExportUnitScale);
    },
    [](const FStaticMeshLODResources& LODResource,TArray<float>& Vertices, uint32 i, float ExportUnitScale) {
        ExportTexcoordLOD<1>(LODResource, Vertices, i, ExportUnitScale);
    },
    [](const FStaticMeshLODResources& LODResource,TArray<float>& Vertices, uint32 i, float ExportUnitScale) {
        FVector Tangent = LODResource.VertexBuffers.StaticMeshVertexBuffer.VertexTangentX(i);
        Vertices.Append({ Tangent.X ,Tangent.Y ,Tangent.Z });
    },
    [](const FStaticMeshLODResources& LODResource,TArray<float>& Vertices, uint32 i, float ExportUnitScale) {
        FLinearColor Color = LODResource.VertexBuffers.ColorVertexBuffer.VertexColor(i);
        Vertices.Append({ Color.R ,Color.G ,Color.B ,Color.A });
    },
};

static void OptionsToVerticesData(const FStaticMeshLODResources& LODResource, const FExportStaticMeshOptions& Options, TArray<float>& vertices)
{
    uint32 NumVertices = LODResource.VertexBuffers.StaticMeshVertexBuffer.GetNumVertices();
    const bool* pOptions = reinterpret_cast<const bool*>(&Options);
    auto Settings = GetDefault<URenderDataExporterSettings>();
    for (uint32 i = 0; i < NumVertices; ++i)
    {
        for (uint32 j = 0; j < (uint32)EVertexFormat::MAX; ++j)
        {
            if (pOptions[j])
            {
                GExportFunctions[j](LODResource, vertices, i, Settings->ExportUnitScale);
            }
        }
    }
}


static void ExportMeshDataToStruct(FStaticMeshExportData& ExportData, UStaticMesh* Mesh, const FExportStaticMeshOptions& Options)
{
    ExportData.Name = Mesh->GetName();
    ExportData.ExportPath = Mesh->GetPackage()->GetPathName();
    ExportData.NumLOD = Mesh->GetNumLODs();
    for (const auto& LODResource : Mesh->RenderData->LODResources)
    {
        FStaticMeshLODData LODData;
        FExportStaticMeshOptions LODOptions = Options;
        if (LODResource.GetNumTexCoords() < 2)
        {
            LODOptions.bTexcoord1 = false;
        }
        if (!LODResource.bHasColorVertexData)
        {
            LODOptions.bVertexColor = false;
        }
        int32 NumIndices = LODResource.IndexBuffer.GetNumIndices();
        LODData.NumVertices = LODResource.GetNumVertices();
        LODData.NumIndices = NumIndices;
        LODData.NumTriangles = LODResource.GetNumTriangles();
        LODData.Indices.Reserve(NumIndices);
        for (int32 At = 0; At < NumIndices; ++At)
        {
            LODData.Indices.Add(LODResource.IndexBuffer.GetIndex(At));
        }

        OptionsToFormatList(LODOptions, LODData);
        OptionsToVerticesData(LODResource, LODOptions, LODData.Vertices);
        ExportData.LODs.Add(LODData);
    }
}


bool URenderDataExporterBPLibrary::ExportMeshToJson(UStaticMesh* Mesh, const FExportStaticMeshOptions& Options, const FString& Path)
{
    if (!IsValid(Mesh) || !Mesh->RenderData || Mesh->GetNumLODs() < 1)
    {
        return false;
    }

    FStaticMeshExportData ExportData;
    ExportMeshDataToStruct(ExportData, Mesh, Options);

    FString JsonStr;
    FJsonObjectConverter::UStructToJsonObjectString(ExportData, JsonStr);
    FFileHelper::SaveStringToFile(JsonStr, *Path);

    return true;
}


static void ExtractCameraData(const TArray<UCameraComponent*>& Cameras, const URenderDataExporterSettings* Settings, FSceneRenderData& Data)
{
    for (const auto& Camera : Cameras)
    {
        FCameraData CameraData;
        auto Transform = Camera->GetComponentToWorld();
        auto Location = Transform.GetLocation();
        auto Rotation = Transform.GetRotation();
        auto Rotator = Rotation.Rotator();
        auto Direction = Rotation.Vector();
        auto Target = Location + Direction * 100.0f;

        Location *= Settings->ExportUnitScale;
        Target *= Settings->ExportUnitScale;

        CameraData.Location = Location;
        CameraData.Rotation = Rotation;
        CameraData.Rotator = Rotator;
        CameraData.Direction = Direction;
        CameraData.Target = Target;

        CameraData.FOV = Camera->FieldOfView;
        CameraData.Aspect = Camera->AspectRatio;
        Data.Cameras.Add(CameraData);
    }
}

bool URenderDataExporterBPLibrary::ExportCamerasToJson(const TArray<UCameraComponent*>& Cameras, const FString& Path)
{
    auto Settings = GetDefault<URenderDataExporterSettings>();

    FSceneRenderData Data;
    ExtractCameraData(Cameras, Settings, Data);

    FString JsonStr;
    FJsonObjectConverter::UStructToJsonObjectString(Data, JsonStr);
    FFileHelper::SaveStringToFile(JsonStr, *Path);

    return true;
}

static FString GetMeshBinaryName(UStaticMesh* Mesh)
{
    return FString::Printf(TEXT("%s.bmesh"), *GetNameSafe(Mesh));
}

static FString GetMapBinaryName(UWorld* World)
{
    return FString::Printf(TEXT("%s.bmap"), *GetNameSafe(World));
}

static FString GetTextureBinaryName(UTexture* Texture)
{
    return FString::Printf(TEXT("%s.btex"), *GetNameSafe(Texture));
}

FArchive& operator<<(FArchive& Ar, FStaticMeshExportData& Data)
{
    return Ar << Data.LODs;
}

FArchive& operator<<(FArchive& Ar, FSceneRenderData& Data)
{
    return Ar << Data.Cameras << Data.Meshes << Data.DirectionalLight;
}

FArchive& operator<<(FArchive& Ar, FStaticMeshLODData& Data)
{
    return Ar << Data.FormatBits << Data.Vertices << Data.Indices;
}

FArchive& operator<<(FArchive& Ar, FCameraData& Data)
{
    return Ar << Data.Location
        << Data.Direction
        << Data.FOV
        << Data.Aspect;
}

FArchive& operator<<(FArchive& Ar, FStaticMeshSceneData& Data)
{
    return Ar << Data.Location
        << Data.Rotator
        << Data.Scale
        << Data.AssetPath
        << Data.Material;
}


FArchive& operator<<(FArchive& Ar, FMeshMaterialData& Data)
{
    return Ar << Data.ShadingModel 
    << Data.VertexShaderPath 
    << Data.PixelShaderPath 
    << Data.TexturePath;
}

FArchive& operator<<(FArchive& Ar, FTextureBinData& Data)
{
    return Ar << Data.Width << Data.Height << Data.Data;
}

FArchive& operator<<(FArchive& Ar, FDirectionalLightData& Data)
{
    return Ar << Data.Color << Data.Intensity << Data.Direction;
}

static void ExtractMapData(UWorld* World, FSceneRenderData& SceneRenderData,
    TSet<UStaticMesh*>& StaticMeshes, TSet<UTexture*>& Textures, const URenderDataExporterSettings* Settings)
{
    TArray<UStaticMeshComponent*> StaticMeshComponents;
    TArray<UCameraComponent*> CameraComponents;
    for (TActorIterator<AActor> Itr(World); Itr; ++Itr)
    {
        AActor* Actor = *Itr;
        TArray<UStaticMeshComponent*> MeshComponents;
        Actor->GetComponents(MeshComponents);
        for (auto Comp : MeshComponents)
        {
            if (IsValid(Comp->GetStaticMesh()) && (!Comp->bHiddenInGame || Settings->bExportHiddenInGameMesh))
            {
                StaticMeshComponents.Add(Comp);
            }
        }
        TArray<UCameraComponent*> CComps;
        Actor->GetComponents(CComps);
        if (CComps.Num() > 0)
        {
            CameraComponents.Append(CComps);
        }
        if (Actor->IsA<ADirectionalLight>())
        {
            auto DLC = Cast<ADirectionalLight>(Actor)->GetComponent();
            SceneRenderData.DirectionalLight.Intensity = DLC->Intensity;
            FLinearColor Color = DLC->LightColor;
            SceneRenderData.DirectionalLight.Color = { Color.R,Color.G,Color.B };
            SceneRenderData.DirectionalLight.Direction = DLC->GetComponentRotation().Vector();
        }
    }
    ExtractCameraData(CameraComponents, Settings, SceneRenderData);
    for (auto Comp : StaticMeshComponents)
    {
        FStaticMeshSceneData SceneData;
        auto Transform = Comp->GetComponentToWorld();
        auto Location = Transform.GetLocation();
        Location *= Settings->ExportUnitScale;
        Transform.SetLocation(Location);
        SceneData.Location = Location;
        SceneData.Rotator = Transform.GetRotation().Rotator();
        SceneData.Scale = Transform.GetScale3D();
        auto Mesh = Comp->GetStaticMesh();
        StaticMeshes.Add(Mesh);
        SceneData.AssetPath = Settings->MeshesFolderName / GetMeshBinaryName(Mesh);
        auto Material = Comp->GetMaterial(0);
        if (Material)
        {
            TArray<UTexture*> UsedTextures;
            Material->GetUsedTextures(UsedTextures, EMaterialQualityLevel::Num, true, ERHIFeatureLevel::SM5, true);
            for (const auto& Texture : UsedTextures)
            {
                Textures.Add(Texture);
                SceneData.Material.TexturePath.Add(Settings->TexturesFolderName / GetTextureBinaryName(Texture));
            }
            auto MaterialExporterData = Material->GetAssetUserData<UMaterialExporterData>();
            if (MaterialExporterData)
            {
                SceneData.Material.ShadingModel = MaterialExporterData->ShadingModel;
                SceneData.Material.VertexShaderPath = MaterialExporterData->VertexShaderPath;
                SceneData.Material.PixelShaderPath = MaterialExporterData->PixelShaderPath;
            }
        }

        SceneRenderData.Meshes.Add(SceneData);
    }
}

static void ExportTexturetiBinary(UTexture* Texture, const FString& Path)
{
    if (!IsValid(Texture))
    {
        return;
    }
    FTextureBinData Data;
    Data.Width = Texture->Source.GetSizeX();
    Data.Height = Texture->Source.GetSizeY();
    uint32 DataSize = Data.Width * Data.Height * 4;
    Data.Data.SetNum(DataSize);
    auto DataSource = Texture->Source.LockMip(0);
    FMemory::Memcpy(Data.Data.GetData(),DataSource,DataSize);
    Texture->Source.UnlockMip(0);
    TUniquePtr<FArchive> FileWriter(IFileManager::Get().CreateFileWriter(*Path));
    *FileWriter << Data;
}

bool URenderDataExporterBPLibrary::ExportMapToBinaries(UObject* WorldContextObject)
{
    if (!IsValid(WorldContextObject) || !IsValid(WorldContextObject->GetWorld()))
    {
        return false;
    }
    FSceneRenderData SceneRenderData;
    UWorld* World = WorldContextObject->GetWorld();
    auto Settings = GetDefault<URenderDataExporterSettings>();

    TSet<UStaticMesh*> StaticMeshes;
    TSet<UTexture*> Textures;
    ExtractMapData(World, SceneRenderData, StaticMeshes, Textures, Settings);

    {
        FString MapBinPath = Settings->ExportRootPath.Path
            / Settings->MapsFolderName
            / GetMapBinaryName(World);
        TUniquePtr<FArchive> FileWriter(IFileManager::Get().CreateFileWriter(*MapBinPath));
        *FileWriter << SceneRenderData;
    }

    for (auto Mesh : StaticMeshes)
    {
        FStaticMeshExportData MeshData;
        ExportMeshDataToStruct(MeshData, Mesh, Settings->ExportStaticMeshOptions);
        FString MeshBinPath = Settings->ExportRootPath.Path
            / Settings->MeshesFolderName
            / GetMeshBinaryName(Mesh);
        TUniquePtr<FArchive> FileWriter(IFileManager::Get().CreateFileWriter(*MeshBinPath));
        *FileWriter << MeshData;
    }

    for (auto Texture : Textures)
    {
        FString TextureBinPath = Settings->ExportRootPath.Path
            / Settings->TexturesFolderName
            / GetTextureBinaryName(Texture);
        ExportTexturetiBinary(Texture, TextureBinPath);
    }

    return true;
}

bool URenderDataExporterBPLibrary::ExportMapToJson(UObject* WorldContextObject)
{
    if (!IsValid(WorldContextObject) || !IsValid(WorldContextObject->GetWorld()))
    {
        return false;
    }
    FSceneRenderData SceneRenderData;
    UWorld* World = WorldContextObject->GetWorld();
    auto Settings = GetDefault<URenderDataExporterSettings>();
    TSet<UStaticMesh*> StaticMeshes;
    TSet<UTexture*> Textures;
    ExtractMapData(World, SceneRenderData, StaticMeshes, Textures, Settings);

    {
        FString MapJsonPath = FPaths::ProjectSavedDir() / FString::Printf(TEXT("%s.json"), *GetNameSafe(World));
        FString JsonStr;
        FJsonObjectConverter::UStructToJsonObjectString(SceneRenderData, JsonStr);
        FFileHelper::SaveStringToFile(JsonStr, *MapJsonPath);
    }

    for (auto Mesh : StaticMeshes)
    {
        FString MeshJsonPath = FPaths::ProjectSavedDir() / FString::Printf(TEXT("%s.json"), *GetNameSafe(Mesh));
        ExportMeshToJson(Mesh, Settings->ExportStaticMeshOptions, MeshJsonPath);
    }

    return true;
}

