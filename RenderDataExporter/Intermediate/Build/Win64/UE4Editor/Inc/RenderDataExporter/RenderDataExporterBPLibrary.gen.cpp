// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RenderDataExporter/Public/RenderDataExporterBPLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRenderDataExporterBPLibrary() {}
// Cross Module References
	RENDERDATAEXPORTER_API UEnum* Z_Construct_UEnum_RenderDataExporter_EVertexFormat();
	UPackage* Z_Construct_UPackage__Script_RenderDataExporter();
	RENDERDATAEXPORTER_API UScriptStruct* Z_Construct_UScriptStruct_FExportStaticMeshOptions();
	RENDERDATAEXPORTER_API UScriptStruct* Z_Construct_UScriptStruct_FSceneRenderData();
	RENDERDATAEXPORTER_API UScriptStruct* Z_Construct_UScriptStruct_FCameraData();
	RENDERDATAEXPORTER_API UScriptStruct* Z_Construct_UScriptStruct_FStaticMeshSceneData();
	RENDERDATAEXPORTER_API UScriptStruct* Z_Construct_UScriptStruct_FDirectionalLightData();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	RENDERDATAEXPORTER_API UScriptStruct* Z_Construct_UScriptStruct_FMeshMaterialData();
	RENDERDATAEXPORTER_API UScriptStruct* Z_Construct_UScriptStruct_FMaterialInstanceData();
	RENDERDATAEXPORTER_API UScriptStruct* Z_Construct_UScriptStruct_FTextureBinData();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
	RENDERDATAEXPORTER_API UScriptStruct* Z_Construct_UScriptStruct_FStaticMeshExportData();
	RENDERDATAEXPORTER_API UScriptStruct* Z_Construct_UScriptStruct_FStaticMeshLODData();
	RENDERDATAEXPORTER_API UClass* Z_Construct_UClass_URenderDataExporterBPLibrary_NoRegister();
	RENDERDATAEXPORTER_API UClass* Z_Construct_UClass_URenderDataExporterBPLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
// End Cross Module References
	static UEnum* EVertexFormat_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_RenderDataExporter_EVertexFormat, Z_Construct_UPackage__Script_RenderDataExporter(), TEXT("EVertexFormat"));
		}
		return Singleton;
	}
	template<> RENDERDATAEXPORTER_API UEnum* StaticEnum<EVertexFormat>()
	{
		return EVertexFormat_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EVertexFormat(EVertexFormat_StaticEnum, TEXT("/Script/RenderDataExporter"), TEXT("EVertexFormat"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_RenderDataExporter_EVertexFormat_Hash() { return 2188553971U; }
	UEnum* Z_Construct_UEnum_RenderDataExporter_EVertexFormat()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_RenderDataExporter();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EVertexFormat"), 0, Get_Z_Construct_UEnum_RenderDataExporter_EVertexFormat_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EVertexFormat::POSITION", (int64)EVertexFormat::POSITION },
				{ "EVertexFormat::NORMAL", (int64)EVertexFormat::NORMAL },
				{ "EVertexFormat::TEXCOORD0", (int64)EVertexFormat::TEXCOORD0 },
				{ "EVertexFormat::TEXCOORD1", (int64)EVertexFormat::TEXCOORD1 },
				{ "EVertexFormat::TANGENT", (int64)EVertexFormat::TANGENT },
				{ "EVertexFormat::COLOR", (int64)EVertexFormat::COLOR },
				{ "EVertexFormat::MAX", (int64)EVertexFormat::MAX },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "COLOR.Name", "EVertexFormat::COLOR" },
				{ "Comment", "/* \n*\x09""Function library class.\n*\x09""Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*\x09When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*\x09""BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*\x09""BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*\x09""DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*\x09\x09\x09\x09Its lets you name the node using characters not allowed in C++ function names.\n*\x09""CompactNodeTitle - the word(s) that appear on the node.\n*\x09Keywords -\x09the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. \n*\x09\x09\x09\x09Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*\x09""Category -\x09the category your node will be under in the Blueprint drop-down menu.\n*\n*\x09""For more info on custom blueprint nodes visit documentation:\n*\x09https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation\n*/" },
				{ "MAX.Name", "EVertexFormat::MAX" },
				{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
				{ "NORMAL.Name", "EVertexFormat::NORMAL" },
				{ "POSITION.Name", "EVertexFormat::POSITION" },
				{ "TANGENT.Name", "EVertexFormat::TANGENT" },
				{ "TEXCOORD0.Name", "EVertexFormat::TEXCOORD0" },
				{ "TEXCOORD1.Name", "EVertexFormat::TEXCOORD1" },
				{ "ToolTip", "*      Function library class.\n*      Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*      When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*      BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*      BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*      DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*                              Its lets you name the node using characters not allowed in C++ function names.\n*      CompactNodeTitle - the word(s) that appear on the node.\n*      Keywords -      the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.\n*                              Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*      Category -      the category your node will be under in the Blueprint drop-down menu.\n*\n*      For more info on custom blueprint nodes visit documentation:\n*      https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_RenderDataExporter,
				nullptr,
				"EVertexFormat",
				"EVertexFormat",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FExportStaticMeshOptions::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RENDERDATAEXPORTER_API uint32 Get_Z_Construct_UScriptStruct_FExportStaticMeshOptions_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FExportStaticMeshOptions, Z_Construct_UPackage__Script_RenderDataExporter(), TEXT("ExportStaticMeshOptions"), sizeof(FExportStaticMeshOptions), Get_Z_Construct_UScriptStruct_FExportStaticMeshOptions_Hash());
	}
	return Singleton;
}
template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<FExportStaticMeshOptions>()
{
	return FExportStaticMeshOptions::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FExportStaticMeshOptions(FExportStaticMeshOptions::StaticStruct, TEXT("/Script/RenderDataExporter"), TEXT("ExportStaticMeshOptions"), false, nullptr, nullptr);
static struct FScriptStruct_RenderDataExporter_StaticRegisterNativesFExportStaticMeshOptions
{
	FScriptStruct_RenderDataExporter_StaticRegisterNativesFExportStaticMeshOptions()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ExportStaticMeshOptions")),new UScriptStruct::TCppStructOps<FExportStaticMeshOptions>);
	}
} ScriptStruct_RenderDataExporter_StaticRegisterNativesFExportStaticMeshOptions;
	struct Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bPosition_MetaData[];
#endif
		static void NewProp_bPosition_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bPosition;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bNormal_MetaData[];
#endif
		static void NewProp_bNormal_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bNormal;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bTexcoord0_MetaData[];
#endif
		static void NewProp_bTexcoord0_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bTexcoord0;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bTexcoord1_MetaData[];
#endif
		static void NewProp_bTexcoord1_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bTexcoord1;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bTangent_MetaData[];
#endif
		static void NewProp_bTangent_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bTangent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bVertexColor_MetaData[];
#endif
		static void NewProp_bVertexColor_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bVertexColor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FExportStaticMeshOptions>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bPosition_MetaData[] = {
		{ "Category", "ExportStaticMeshOptions" },
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bPosition_SetBit(void* Obj)
	{
		((FExportStaticMeshOptions*)Obj)->bPosition = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bPosition = { "bPosition", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FExportStaticMeshOptions), &Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bPosition_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bPosition_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bNormal_MetaData[] = {
		{ "Category", "ExportStaticMeshOptions" },
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bNormal_SetBit(void* Obj)
	{
		((FExportStaticMeshOptions*)Obj)->bNormal = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bNormal = { "bNormal", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FExportStaticMeshOptions), &Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bNormal_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bNormal_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bNormal_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTexcoord0_MetaData[] = {
		{ "Category", "ExportStaticMeshOptions" },
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTexcoord0_SetBit(void* Obj)
	{
		((FExportStaticMeshOptions*)Obj)->bTexcoord0 = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTexcoord0 = { "bTexcoord0", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FExportStaticMeshOptions), &Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTexcoord0_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTexcoord0_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTexcoord0_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTexcoord1_MetaData[] = {
		{ "Category", "ExportStaticMeshOptions" },
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTexcoord1_SetBit(void* Obj)
	{
		((FExportStaticMeshOptions*)Obj)->bTexcoord1 = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTexcoord1 = { "bTexcoord1", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FExportStaticMeshOptions), &Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTexcoord1_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTexcoord1_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTexcoord1_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTangent_MetaData[] = {
		{ "Category", "ExportStaticMeshOptions" },
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTangent_SetBit(void* Obj)
	{
		((FExportStaticMeshOptions*)Obj)->bTangent = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTangent = { "bTangent", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FExportStaticMeshOptions), &Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTangent_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTangent_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTangent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bVertexColor_MetaData[] = {
		{ "Category", "ExportStaticMeshOptions" },
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bVertexColor_SetBit(void* Obj)
	{
		((FExportStaticMeshOptions*)Obj)->bVertexColor = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bVertexColor = { "bVertexColor", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FExportStaticMeshOptions), &Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bVertexColor_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bVertexColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bVertexColor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bNormal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTexcoord0,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTexcoord1,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bTangent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::NewProp_bVertexColor,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RenderDataExporter,
		nullptr,
		&NewStructOps,
		"ExportStaticMeshOptions",
		sizeof(FExportStaticMeshOptions),
		alignof(FExportStaticMeshOptions),
		Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FExportStaticMeshOptions()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FExportStaticMeshOptions_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_RenderDataExporter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ExportStaticMeshOptions"), sizeof(FExportStaticMeshOptions), Get_Z_Construct_UScriptStruct_FExportStaticMeshOptions_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FExportStaticMeshOptions_Hash() { return 3064206003U; }
class UScriptStruct* FSceneRenderData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RENDERDATAEXPORTER_API uint32 Get_Z_Construct_UScriptStruct_FSceneRenderData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSceneRenderData, Z_Construct_UPackage__Script_RenderDataExporter(), TEXT("SceneRenderData"), sizeof(FSceneRenderData), Get_Z_Construct_UScriptStruct_FSceneRenderData_Hash());
	}
	return Singleton;
}
template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<FSceneRenderData>()
{
	return FSceneRenderData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSceneRenderData(FSceneRenderData::StaticStruct, TEXT("/Script/RenderDataExporter"), TEXT("SceneRenderData"), false, nullptr, nullptr);
static struct FScriptStruct_RenderDataExporter_StaticRegisterNativesFSceneRenderData
{
	FScriptStruct_RenderDataExporter_StaticRegisterNativesFSceneRenderData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("SceneRenderData")),new UScriptStruct::TCppStructOps<FSceneRenderData>);
	}
} ScriptStruct_RenderDataExporter_StaticRegisterNativesFSceneRenderData;
	struct Z_Construct_UScriptStruct_FSceneRenderData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Cameras_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Cameras_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Cameras;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Meshes_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Meshes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Meshes;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DirectionalLight_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_DirectionalLight;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSceneRenderData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSceneRenderData>();
	}
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_Cameras_Inner = { "Cameras", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FCameraData, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_Cameras_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_Cameras = { "Cameras", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSceneRenderData, Cameras), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_Cameras_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_Cameras_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_Meshes_Inner = { "Meshes", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FStaticMeshSceneData, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_Meshes_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_Meshes = { "Meshes", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSceneRenderData, Meshes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_Meshes_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_Meshes_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_DirectionalLight_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_DirectionalLight = { "DirectionalLight", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSceneRenderData, DirectionalLight), Z_Construct_UScriptStruct_FDirectionalLightData, METADATA_PARAMS(Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_DirectionalLight_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_DirectionalLight_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSceneRenderData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_Cameras_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_Cameras,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_Meshes_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_Meshes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSceneRenderData_Statics::NewProp_DirectionalLight,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSceneRenderData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RenderDataExporter,
		nullptr,
		&NewStructOps,
		"SceneRenderData",
		sizeof(FSceneRenderData),
		alignof(FSceneRenderData),
		Z_Construct_UScriptStruct_FSceneRenderData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneRenderData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSceneRenderData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneRenderData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSceneRenderData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSceneRenderData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_RenderDataExporter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SceneRenderData"), sizeof(FSceneRenderData), Get_Z_Construct_UScriptStruct_FSceneRenderData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSceneRenderData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSceneRenderData_Hash() { return 521983965U; }
class UScriptStruct* FDirectionalLightData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RENDERDATAEXPORTER_API uint32 Get_Z_Construct_UScriptStruct_FDirectionalLightData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FDirectionalLightData, Z_Construct_UPackage__Script_RenderDataExporter(), TEXT("DirectionalLightData"), sizeof(FDirectionalLightData), Get_Z_Construct_UScriptStruct_FDirectionalLightData_Hash());
	}
	return Singleton;
}
template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<FDirectionalLightData>()
{
	return FDirectionalLightData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FDirectionalLightData(FDirectionalLightData::StaticStruct, TEXT("/Script/RenderDataExporter"), TEXT("DirectionalLightData"), false, nullptr, nullptr);
static struct FScriptStruct_RenderDataExporter_StaticRegisterNativesFDirectionalLightData
{
	FScriptStruct_RenderDataExporter_StaticRegisterNativesFDirectionalLightData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("DirectionalLightData")),new UScriptStruct::TCppStructOps<FDirectionalLightData>);
	}
} ScriptStruct_RenderDataExporter_StaticRegisterNativesFDirectionalLightData;
	struct Z_Construct_UScriptStruct_FDirectionalLightData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Intensity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Intensity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Direction;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDirectionalLightData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDirectionalLightData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewProp_Color_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FDirectionalLightData, Color), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewProp_Color_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewProp_Color_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewProp_Intensity_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewProp_Intensity = { "Intensity", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FDirectionalLightData, Intensity), METADATA_PARAMS(Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewProp_Intensity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewProp_Intensity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewProp_Direction_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FDirectionalLightData, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewProp_Direction_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewProp_Direction_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDirectionalLightData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewProp_Color,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewProp_Intensity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDirectionalLightData_Statics::NewProp_Direction,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDirectionalLightData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RenderDataExporter,
		nullptr,
		&NewStructOps,
		"DirectionalLightData",
		sizeof(FDirectionalLightData),
		alignof(FDirectionalLightData),
		Z_Construct_UScriptStruct_FDirectionalLightData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDirectionalLightData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FDirectionalLightData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDirectionalLightData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FDirectionalLightData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FDirectionalLightData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_RenderDataExporter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("DirectionalLightData"), sizeof(FDirectionalLightData), Get_Z_Construct_UScriptStruct_FDirectionalLightData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FDirectionalLightData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FDirectionalLightData_Hash() { return 4294306196U; }
class UScriptStruct* FStaticMeshSceneData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RENDERDATAEXPORTER_API uint32 Get_Z_Construct_UScriptStruct_FStaticMeshSceneData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FStaticMeshSceneData, Z_Construct_UPackage__Script_RenderDataExporter(), TEXT("StaticMeshSceneData"), sizeof(FStaticMeshSceneData), Get_Z_Construct_UScriptStruct_FStaticMeshSceneData_Hash());
	}
	return Singleton;
}
template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<FStaticMeshSceneData>()
{
	return FStaticMeshSceneData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FStaticMeshSceneData(FStaticMeshSceneData::StaticStruct, TEXT("/Script/RenderDataExporter"), TEXT("StaticMeshSceneData"), false, nullptr, nullptr);
static struct FScriptStruct_RenderDataExporter_StaticRegisterNativesFStaticMeshSceneData
{
	FScriptStruct_RenderDataExporter_StaticRegisterNativesFStaticMeshSceneData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("StaticMeshSceneData")),new UScriptStruct::TCppStructOps<FStaticMeshSceneData>);
	}
} ScriptStruct_RenderDataExporter_StaticRegisterNativesFStaticMeshSceneData;
	struct Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Rotator_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Rotator;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Scale;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AssetPath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AssetPath;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Material_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Material;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStaticMeshSceneData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Location_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStaticMeshSceneData, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Location_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Rotator_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Rotator = { "Rotator", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStaticMeshSceneData, Rotator), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Rotator_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Rotator_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Scale_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStaticMeshSceneData, Scale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Scale_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Scale_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_AssetPath_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_AssetPath = { "AssetPath", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStaticMeshSceneData, AssetPath), METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_AssetPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_AssetPath_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Material_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Material = { "Material", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStaticMeshSceneData, Material), Z_Construct_UScriptStruct_FMeshMaterialData, METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Material_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Material_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Location,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Rotator,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Scale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_AssetPath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::NewProp_Material,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RenderDataExporter,
		nullptr,
		&NewStructOps,
		"StaticMeshSceneData",
		sizeof(FStaticMeshSceneData),
		alignof(FStaticMeshSceneData),
		Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FStaticMeshSceneData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FStaticMeshSceneData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_RenderDataExporter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("StaticMeshSceneData"), sizeof(FStaticMeshSceneData), Get_Z_Construct_UScriptStruct_FStaticMeshSceneData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FStaticMeshSceneData_Hash() { return 2539151684U; }
class UScriptStruct* FMeshMaterialData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RENDERDATAEXPORTER_API uint32 Get_Z_Construct_UScriptStruct_FMeshMaterialData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMeshMaterialData, Z_Construct_UPackage__Script_RenderDataExporter(), TEXT("MeshMaterialData"), sizeof(FMeshMaterialData), Get_Z_Construct_UScriptStruct_FMeshMaterialData_Hash());
	}
	return Singleton;
}
template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<FMeshMaterialData>()
{
	return FMeshMaterialData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMeshMaterialData(FMeshMaterialData::StaticStruct, TEXT("/Script/RenderDataExporter"), TEXT("MeshMaterialData"), false, nullptr, nullptr);
static struct FScriptStruct_RenderDataExporter_StaticRegisterNativesFMeshMaterialData
{
	FScriptStruct_RenderDataExporter_StaticRegisterNativesFMeshMaterialData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("MeshMaterialData")),new UScriptStruct::TCppStructOps<FMeshMaterialData>);
	}
} ScriptStruct_RenderDataExporter_StaticRegisterNativesFMeshMaterialData;
	struct Z_Construct_UScriptStruct_FMeshMaterialData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShadingModel_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ShadingModel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VertexShaderPath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_VertexShaderPath;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PixelShaderPath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PixelShaderPath;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_TexturePath_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TexturePath_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TexturePath;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshMaterialData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMeshMaterialData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_ShadingModel_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_ShadingModel = { "ShadingModel", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshMaterialData, ShadingModel), METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_ShadingModel_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_ShadingModel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_VertexShaderPath_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_VertexShaderPath = { "VertexShaderPath", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshMaterialData, VertexShaderPath), METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_VertexShaderPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_VertexShaderPath_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_PixelShaderPath_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_PixelShaderPath = { "PixelShaderPath", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshMaterialData, PixelShaderPath), METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_PixelShaderPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_PixelShaderPath_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_TexturePath_Inner = { "TexturePath", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_TexturePath_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_TexturePath = { "TexturePath", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeshMaterialData, TexturePath), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_TexturePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_TexturePath_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMeshMaterialData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_ShadingModel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_VertexShaderPath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_PixelShaderPath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_TexturePath_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeshMaterialData_Statics::NewProp_TexturePath,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMeshMaterialData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RenderDataExporter,
		nullptr,
		&NewStructOps,
		"MeshMaterialData",
		sizeof(FMeshMaterialData),
		alignof(FMeshMaterialData),
		Z_Construct_UScriptStruct_FMeshMaterialData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshMaterialData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMeshMaterialData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMeshMaterialData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMeshMaterialData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FMeshMaterialData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_RenderDataExporter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MeshMaterialData"), sizeof(FMeshMaterialData), Get_Z_Construct_UScriptStruct_FMeshMaterialData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FMeshMaterialData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMeshMaterialData_Hash() { return 1452473407U; }
class UScriptStruct* FMaterialInstanceData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RENDERDATAEXPORTER_API uint32 Get_Z_Construct_UScriptStruct_FMaterialInstanceData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMaterialInstanceData, Z_Construct_UPackage__Script_RenderDataExporter(), TEXT("MaterialInstanceData"), sizeof(FMaterialInstanceData), Get_Z_Construct_UScriptStruct_FMaterialInstanceData_Hash());
	}
	return Singleton;
}
template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<FMaterialInstanceData>()
{
	return FMaterialInstanceData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMaterialInstanceData(FMaterialInstanceData::StaticStruct, TEXT("/Script/RenderDataExporter"), TEXT("MaterialInstanceData"), false, nullptr, nullptr);
static struct FScriptStruct_RenderDataExporter_StaticRegisterNativesFMaterialInstanceData
{
	FScriptStruct_RenderDataExporter_StaticRegisterNativesFMaterialInstanceData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("MaterialInstanceData")),new UScriptStruct::TCppStructOps<FMaterialInstanceData>);
	}
} ScriptStruct_RenderDataExporter_StaticRegisterNativesFMaterialInstanceData;
	struct Z_Construct_UScriptStruct_FMaterialInstanceData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMaterialInstanceData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMaterialInstanceData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMaterialInstanceData>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMaterialInstanceData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RenderDataExporter,
		nullptr,
		&NewStructOps,
		"MaterialInstanceData",
		sizeof(FMaterialInstanceData),
		alignof(FMaterialInstanceData),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMaterialInstanceData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMaterialInstanceData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMaterialInstanceData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FMaterialInstanceData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_RenderDataExporter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MaterialInstanceData"), sizeof(FMaterialInstanceData), Get_Z_Construct_UScriptStruct_FMaterialInstanceData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FMaterialInstanceData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMaterialInstanceData_Hash() { return 691778018U; }
class UScriptStruct* FTextureBinData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RENDERDATAEXPORTER_API uint32 Get_Z_Construct_UScriptStruct_FTextureBinData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FTextureBinData, Z_Construct_UPackage__Script_RenderDataExporter(), TEXT("TextureBinData"), sizeof(FTextureBinData), Get_Z_Construct_UScriptStruct_FTextureBinData_Hash());
	}
	return Singleton;
}
template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<FTextureBinData>()
{
	return FTextureBinData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FTextureBinData(FTextureBinData::StaticStruct, TEXT("/Script/RenderDataExporter"), TEXT("TextureBinData"), false, nullptr, nullptr);
static struct FScriptStruct_RenderDataExporter_StaticRegisterNativesFTextureBinData
{
	FScriptStruct_RenderDataExporter_StaticRegisterNativesFTextureBinData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("TextureBinData")),new UScriptStruct::TCppStructOps<FTextureBinData>);
	}
} ScriptStruct_RenderDataExporter_StaticRegisterNativesFTextureBinData;
	struct Z_Construct_UScriptStruct_FTextureBinData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_Width;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_Height;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Data_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Data;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTextureBinData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FTextureBinData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTextureBinData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Width_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTextureBinData, Width), METADATA_PARAMS(Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Width_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Width_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Height_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTextureBinData, Height), METADATA_PARAMS(Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Height_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Height_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Data_Inner = { "Data", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Data_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTextureBinData, Data), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Data_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Data_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTextureBinData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Width,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Height,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Data_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTextureBinData_Statics::NewProp_Data,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTextureBinData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RenderDataExporter,
		nullptr,
		&NewStructOps,
		"TextureBinData",
		sizeof(FTextureBinData),
		alignof(FTextureBinData),
		Z_Construct_UScriptStruct_FTextureBinData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureBinData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FTextureBinData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTextureBinData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FTextureBinData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FTextureBinData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_RenderDataExporter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("TextureBinData"), sizeof(FTextureBinData), Get_Z_Construct_UScriptStruct_FTextureBinData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FTextureBinData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FTextureBinData_Hash() { return 1700371421U; }
class UScriptStruct* FCameraData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RENDERDATAEXPORTER_API uint32 Get_Z_Construct_UScriptStruct_FCameraData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FCameraData, Z_Construct_UPackage__Script_RenderDataExporter(), TEXT("CameraData"), sizeof(FCameraData), Get_Z_Construct_UScriptStruct_FCameraData_Hash());
	}
	return Singleton;
}
template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<FCameraData>()
{
	return FCameraData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FCameraData(FCameraData::StaticStruct, TEXT("/Script/RenderDataExporter"), TEXT("CameraData"), false, nullptr, nullptr);
static struct FScriptStruct_RenderDataExporter_StaticRegisterNativesFCameraData
{
	FScriptStruct_RenderDataExporter_StaticRegisterNativesFCameraData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("CameraData")),new UScriptStruct::TCppStructOps<FCameraData>);
	}
} ScriptStruct_RenderDataExporter_StaticRegisterNativesFCameraData;
	struct Z_Construct_UScriptStruct_FCameraData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Rotator_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Rotator;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Rotation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Direction;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Target;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FOV_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_FOV;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Aspect_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Aspect;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCameraData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCameraData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCameraData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Location_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCameraData, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Location_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Rotator_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Rotator = { "Rotator", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCameraData, Rotator), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Rotator_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Rotator_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Rotation_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCameraData, Rotation), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Rotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Rotation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Direction_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCameraData, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Direction_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Direction_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Target_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCameraData, Target), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Target_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Target_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_FOV_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_FOV = { "FOV", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCameraData, FOV), METADATA_PARAMS(Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_FOV_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_FOV_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Aspect_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Aspect = { "Aspect", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCameraData, Aspect), METADATA_PARAMS(Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Aspect_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Aspect_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCameraData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Location,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Rotator,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Rotation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Direction,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Target,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_FOV,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCameraData_Statics::NewProp_Aspect,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCameraData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RenderDataExporter,
		nullptr,
		&NewStructOps,
		"CameraData",
		sizeof(FCameraData),
		alignof(FCameraData),
		Z_Construct_UScriptStruct_FCameraData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCameraData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCameraData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCameraData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FCameraData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_RenderDataExporter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("CameraData"), sizeof(FCameraData), Get_Z_Construct_UScriptStruct_FCameraData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FCameraData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FCameraData_Hash() { return 420373353U; }
class UScriptStruct* FStaticMeshExportData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RENDERDATAEXPORTER_API uint32 Get_Z_Construct_UScriptStruct_FStaticMeshExportData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FStaticMeshExportData, Z_Construct_UPackage__Script_RenderDataExporter(), TEXT("StaticMeshExportData"), sizeof(FStaticMeshExportData), Get_Z_Construct_UScriptStruct_FStaticMeshExportData_Hash());
	}
	return Singleton;
}
template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<FStaticMeshExportData>()
{
	return FStaticMeshExportData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FStaticMeshExportData(FStaticMeshExportData::StaticStruct, TEXT("/Script/RenderDataExporter"), TEXT("StaticMeshExportData"), false, nullptr, nullptr);
static struct FScriptStruct_RenderDataExporter_StaticRegisterNativesFStaticMeshExportData
{
	FScriptStruct_RenderDataExporter_StaticRegisterNativesFStaticMeshExportData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("StaticMeshExportData")),new UScriptStruct::TCppStructOps<FStaticMeshExportData>);
	}
} ScriptStruct_RenderDataExporter_StaticRegisterNativesFStaticMeshExportData;
	struct Z_Construct_UScriptStruct_FStaticMeshExportData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Name;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExportPath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ExportPath;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NumLOD_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_NumLOD;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LODs_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LODs_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_LODs;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStaticMeshExportData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStaticMeshExportData, Name), METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_Name_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_ExportPath_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_ExportPath = { "ExportPath", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStaticMeshExportData, ExportPath), METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_ExportPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_ExportPath_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_NumLOD_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_NumLOD = { "NumLOD", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStaticMeshExportData, NumLOD), METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_NumLOD_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_NumLOD_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_LODs_Inner = { "LODs", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FStaticMeshLODData, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_LODs_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_LODs = { "LODs", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStaticMeshExportData, LODs), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_LODs_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_LODs_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_Name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_ExportPath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_NumLOD,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_LODs_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::NewProp_LODs,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RenderDataExporter,
		nullptr,
		&NewStructOps,
		"StaticMeshExportData",
		sizeof(FStaticMeshExportData),
		alignof(FStaticMeshExportData),
		Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FStaticMeshExportData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FStaticMeshExportData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_RenderDataExporter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("StaticMeshExportData"), sizeof(FStaticMeshExportData), Get_Z_Construct_UScriptStruct_FStaticMeshExportData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FStaticMeshExportData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FStaticMeshExportData_Hash() { return 1185451911U; }
class UScriptStruct* FStaticMeshLODData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RENDERDATAEXPORTER_API uint32 Get_Z_Construct_UScriptStruct_FStaticMeshLODData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FStaticMeshLODData, Z_Construct_UPackage__Script_RenderDataExporter(), TEXT("StaticMeshLODData"), sizeof(FStaticMeshLODData), Get_Z_Construct_UScriptStruct_FStaticMeshLODData_Hash());
	}
	return Singleton;
}
template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<FStaticMeshLODData>()
{
	return FStaticMeshLODData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FStaticMeshLODData(FStaticMeshLODData::StaticStruct, TEXT("/Script/RenderDataExporter"), TEXT("StaticMeshLODData"), false, nullptr, nullptr);
static struct FScriptStruct_RenderDataExporter_StaticRegisterNativesFStaticMeshLODData
{
	FScriptStruct_RenderDataExporter_StaticRegisterNativesFStaticMeshLODData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("StaticMeshLODData")),new UScriptStruct::TCppStructOps<FStaticMeshLODData>);
	}
} ScriptStruct_RenderDataExporter_StaticRegisterNativesFStaticMeshLODData;
	struct Z_Construct_UScriptStruct_FStaticMeshLODData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NumVertices_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_NumVertices;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NumTriangles_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_NumTriangles;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NumIndices_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_NumIndices;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Format_Inner_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Format_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Format_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Format;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Vertices_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Vertices;
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_Indices_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Indices_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Indices;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStaticMeshLODData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_NumVertices_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_NumVertices = { "NumVertices", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStaticMeshLODData, NumVertices), METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_NumVertices_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_NumVertices_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_NumTriangles_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_NumTriangles = { "NumTriangles", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStaticMeshLODData, NumTriangles), METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_NumTriangles_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_NumTriangles_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_NumIndices_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_NumIndices = { "NumIndices", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStaticMeshLODData, NumIndices), METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_NumIndices_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_NumIndices_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Format_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Format_Inner = { "Format", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_RenderDataExporter_EVertexFormat, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Format_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Format = { "Format", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStaticMeshLODData, Format), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Format_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Format_MetaData)) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Vertices_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStaticMeshLODData, Vertices), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Vertices_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Vertices_MetaData)) };
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Indices_Inner = { "Indices", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Indices_MetaData[] = {
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Indices = { "Indices", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStaticMeshLODData, Indices), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Indices_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Indices_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_NumVertices,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_NumTriangles,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_NumIndices,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Format_Inner_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Format_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Format,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Vertices_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Vertices,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Indices_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::NewProp_Indices,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RenderDataExporter,
		nullptr,
		&NewStructOps,
		"StaticMeshLODData",
		sizeof(FStaticMeshLODData),
		alignof(FStaticMeshLODData),
		Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FStaticMeshLODData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FStaticMeshLODData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_RenderDataExporter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("StaticMeshLODData"), sizeof(FStaticMeshLODData), Get_Z_Construct_UScriptStruct_FStaticMeshLODData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FStaticMeshLODData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FStaticMeshLODData_Hash() { return 3811887346U; }
	DEFINE_FUNCTION(URenderDataExporterBPLibrary::execExportMapToJson)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=URenderDataExporterBPLibrary::ExportMapToJson(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URenderDataExporterBPLibrary::execExportMapToBinaries)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=URenderDataExporterBPLibrary::ExportMapToBinaries(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URenderDataExporterBPLibrary::execExportCamerasToJson)
	{
		P_GET_TARRAY_REF(UCameraComponent*,Z_Param_Out_Cameras);
		P_GET_PROPERTY(FStrProperty,Z_Param_Path);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=URenderDataExporterBPLibrary::ExportCamerasToJson(Z_Param_Out_Cameras,Z_Param_Path);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URenderDataExporterBPLibrary::execExportMeshToJson)
	{
		P_GET_OBJECT(UStaticMesh,Z_Param_Mesh);
		P_GET_STRUCT_REF(FExportStaticMeshOptions,Z_Param_Out_Options);
		P_GET_PROPERTY(FStrProperty,Z_Param_Path);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=URenderDataExporterBPLibrary::ExportMeshToJson(Z_Param_Mesh,Z_Param_Out_Options,Z_Param_Path);
		P_NATIVE_END;
	}
	void URenderDataExporterBPLibrary::StaticRegisterNativesURenderDataExporterBPLibrary()
	{
		UClass* Class = URenderDataExporterBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ExportCamerasToJson", &URenderDataExporterBPLibrary::execExportCamerasToJson },
			{ "ExportMapToBinaries", &URenderDataExporterBPLibrary::execExportMapToBinaries },
			{ "ExportMapToJson", &URenderDataExporterBPLibrary::execExportMapToJson },
			{ "ExportMeshToJson", &URenderDataExporterBPLibrary::execExportMeshToJson },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics
	{
		struct RenderDataExporterBPLibrary_eventExportCamerasToJson_Parms
		{
			TArray<UCameraComponent*> Cameras;
			FString Path;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Cameras_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Cameras_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Cameras;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Path;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_Cameras_Inner = { "Cameras", nullptr, (EPropertyFlags)0x0000000000080000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_Cameras_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_Cameras = { "Cameras", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RenderDataExporterBPLibrary_eventExportCamerasToJson_Parms, Cameras), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_Cameras_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_Cameras_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_Path_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RenderDataExporterBPLibrary_eventExportCamerasToJson_Parms, Path), METADATA_PARAMS(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_Path_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_Path_MetaData)) };
	void Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((RenderDataExporterBPLibrary_eventExportCamerasToJson_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(RenderDataExporterBPLibrary_eventExportCamerasToJson_Parms), &Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_Cameras_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_Cameras,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_Path,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::Function_MetaDataParams[] = {
		{ "Category", "RenderDataExporter" },
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URenderDataExporterBPLibrary, nullptr, "ExportCamerasToJson", nullptr, nullptr, sizeof(RenderDataExporterBPLibrary_eventExportCamerasToJson_Parms), Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04442401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries_Statics
	{
		struct RenderDataExporterBPLibrary_eventExportMapToBinaries_Parms
		{
			UObject* WorldContextObject;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RenderDataExporterBPLibrary_eventExportMapToBinaries_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((RenderDataExporterBPLibrary_eventExportMapToBinaries_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(RenderDataExporterBPLibrary_eventExportMapToBinaries_Parms), &Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries_Statics::Function_MetaDataParams[] = {
		{ "Category", "RenderDataExporter" },
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URenderDataExporterBPLibrary, nullptr, "ExportMapToBinaries", nullptr, nullptr, sizeof(RenderDataExporterBPLibrary_eventExportMapToBinaries_Parms), Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson_Statics
	{
		struct RenderDataExporterBPLibrary_eventExportMapToJson_Parms
		{
			UObject* WorldContextObject;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RenderDataExporterBPLibrary_eventExportMapToJson_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((RenderDataExporterBPLibrary_eventExportMapToJson_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(RenderDataExporterBPLibrary_eventExportMapToJson_Parms), &Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson_Statics::Function_MetaDataParams[] = {
		{ "Category", "RenderDataExporter" },
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URenderDataExporterBPLibrary, nullptr, "ExportMapToJson", nullptr, nullptr, sizeof(RenderDataExporterBPLibrary_eventExportMapToJson_Parms), Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics
	{
		struct RenderDataExporterBPLibrary_eventExportMeshToJson_Parms
		{
			UStaticMesh* Mesh;
			FExportStaticMeshOptions Options;
			FString Path;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Mesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Options_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Options;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Path;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RenderDataExporterBPLibrary_eventExportMeshToJson_Parms, Mesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_Options_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_Options = { "Options", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RenderDataExporterBPLibrary_eventExportMeshToJson_Parms, Options), Z_Construct_UScriptStruct_FExportStaticMeshOptions, METADATA_PARAMS(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_Options_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_Options_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_Path_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RenderDataExporterBPLibrary_eventExportMeshToJson_Parms, Path), METADATA_PARAMS(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_Path_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_Path_MetaData)) };
	void Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((RenderDataExporterBPLibrary_eventExportMeshToJson_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(RenderDataExporterBPLibrary_eventExportMeshToJson_Parms), &Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_Mesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_Options,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_Path,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::Function_MetaDataParams[] = {
		{ "Category", "RenderDataExporter" },
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URenderDataExporterBPLibrary, nullptr, "ExportMeshToJson", nullptr, nullptr, sizeof(RenderDataExporterBPLibrary_eventExportMeshToJson_Parms), Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04442401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URenderDataExporterBPLibrary_NoRegister()
	{
		return URenderDataExporterBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_URenderDataExporterBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URenderDataExporterBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_RenderDataExporter,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_URenderDataExporterBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportCamerasToJson, "ExportCamerasToJson" }, // 3120788535
		{ &Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToBinaries, "ExportMapToBinaries" }, // 268065689
		{ &Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMapToJson, "ExportMapToJson" }, // 3470439282
		{ &Z_Construct_UFunction_URenderDataExporterBPLibrary_ExportMeshToJson, "ExportMeshToJson" }, // 553991122
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URenderDataExporterBPLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "RenderDataExporterBPLibrary.h" },
		{ "ModuleRelativePath", "Public/RenderDataExporterBPLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_URenderDataExporterBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URenderDataExporterBPLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_URenderDataExporterBPLibrary_Statics::ClassParams = {
		&URenderDataExporterBPLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_URenderDataExporterBPLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URenderDataExporterBPLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URenderDataExporterBPLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_URenderDataExporterBPLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(URenderDataExporterBPLibrary, 1013113083);
	template<> RENDERDATAEXPORTER_API UClass* StaticClass<URenderDataExporterBPLibrary>()
	{
		return URenderDataExporterBPLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_URenderDataExporterBPLibrary(Z_Construct_UClass_URenderDataExporterBPLibrary, &URenderDataExporterBPLibrary::StaticClass, TEXT("/Script/RenderDataExporter"), TEXT("URenderDataExporterBPLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URenderDataExporterBPLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
