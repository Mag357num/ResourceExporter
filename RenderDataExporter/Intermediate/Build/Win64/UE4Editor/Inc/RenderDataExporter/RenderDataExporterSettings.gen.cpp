// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RenderDataExporter/Public/RenderDataExporterSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRenderDataExporterSettings() {}
// Cross Module References
	RENDERDATAEXPORTER_API UClass* Z_Construct_UClass_URenderDataExporterSettings_NoRegister();
	RENDERDATAEXPORTER_API UClass* Z_Construct_UClass_URenderDataExporterSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_RenderDataExporter();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FDirectoryPath();
	RENDERDATAEXPORTER_API UScriptStruct* Z_Construct_UScriptStruct_FExportStaticMeshOptions();
// End Cross Module References
	void URenderDataExporterSettings::StaticRegisterNativesURenderDataExporterSettings()
	{
	}
	UClass* Z_Construct_UClass_URenderDataExporterSettings_NoRegister()
	{
		return URenderDataExporterSettings::StaticClass();
	}
	struct Z_Construct_UClass_URenderDataExporterSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExportUnitScale_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ExportUnitScale;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExportRootPath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ExportRootPath;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MapsFolderName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_MapsFolderName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshesFolderName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_MeshesFolderName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TexturesFolderName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_TexturesFolderName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bExportHiddenInGameMesh_MetaData[];
#endif
		static void NewProp_bExportHiddenInGameMesh_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bExportHiddenInGameMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExportStaticMeshOptions_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ExportStaticMeshOptions;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URenderDataExporterSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_RenderDataExporter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URenderDataExporterSettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "RenderDataExporterSettings.h" },
		{ "ModuleRelativePath", "Public/RenderDataExporterSettings.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_ExportUnitScale_MetaData[] = {
		{ "Category", "RenderDataExporterSettings" },
		{ "ModuleRelativePath", "Public/RenderDataExporterSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_ExportUnitScale = { "ExportUnitScale", nullptr, (EPropertyFlags)0x0010000000044015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URenderDataExporterSettings, ExportUnitScale), METADATA_PARAMS(Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_ExportUnitScale_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_ExportUnitScale_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_ExportRootPath_MetaData[] = {
		{ "Category", "RenderDataExporterSettings" },
		{ "ModuleRelativePath", "Public/RenderDataExporterSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_ExportRootPath = { "ExportRootPath", nullptr, (EPropertyFlags)0x0010000000044015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URenderDataExporterSettings, ExportRootPath), Z_Construct_UScriptStruct_FDirectoryPath, METADATA_PARAMS(Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_ExportRootPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_ExportRootPath_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_MapsFolderName_MetaData[] = {
		{ "Category", "RenderDataExporterSettings" },
		{ "ModuleRelativePath", "Public/RenderDataExporterSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_MapsFolderName = { "MapsFolderName", nullptr, (EPropertyFlags)0x0010000000044015, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URenderDataExporterSettings, MapsFolderName), METADATA_PARAMS(Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_MapsFolderName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_MapsFolderName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_MeshesFolderName_MetaData[] = {
		{ "Category", "RenderDataExporterSettings" },
		{ "ModuleRelativePath", "Public/RenderDataExporterSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_MeshesFolderName = { "MeshesFolderName", nullptr, (EPropertyFlags)0x0010000000044015, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URenderDataExporterSettings, MeshesFolderName), METADATA_PARAMS(Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_MeshesFolderName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_MeshesFolderName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_TexturesFolderName_MetaData[] = {
		{ "Category", "RenderDataExporterSettings" },
		{ "ModuleRelativePath", "Public/RenderDataExporterSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_TexturesFolderName = { "TexturesFolderName", nullptr, (EPropertyFlags)0x0010000000044015, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URenderDataExporterSettings, TexturesFolderName), METADATA_PARAMS(Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_TexturesFolderName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_TexturesFolderName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_bExportHiddenInGameMesh_MetaData[] = {
		{ "Category", "RenderDataExporterSettings" },
		{ "ModuleRelativePath", "Public/RenderDataExporterSettings.h" },
	};
#endif
	void Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_bExportHiddenInGameMesh_SetBit(void* Obj)
	{
		((URenderDataExporterSettings*)Obj)->bExportHiddenInGameMesh = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_bExportHiddenInGameMesh = { "bExportHiddenInGameMesh", nullptr, (EPropertyFlags)0x0010000000044015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(URenderDataExporterSettings), &Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_bExportHiddenInGameMesh_SetBit, METADATA_PARAMS(Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_bExportHiddenInGameMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_bExportHiddenInGameMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_ExportStaticMeshOptions_MetaData[] = {
		{ "Category", "RenderDataExporterSettings" },
		{ "ModuleRelativePath", "Public/RenderDataExporterSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_ExportStaticMeshOptions = { "ExportStaticMeshOptions", nullptr, (EPropertyFlags)0x0010000000044015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URenderDataExporterSettings, ExportStaticMeshOptions), Z_Construct_UScriptStruct_FExportStaticMeshOptions, METADATA_PARAMS(Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_ExportStaticMeshOptions_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_ExportStaticMeshOptions_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URenderDataExporterSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_ExportUnitScale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_ExportRootPath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_MapsFolderName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_MeshesFolderName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_TexturesFolderName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_bExportHiddenInGameMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URenderDataExporterSettings_Statics::NewProp_ExportStaticMeshOptions,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_URenderDataExporterSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URenderDataExporterSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_URenderDataExporterSettings_Statics::ClassParams = {
		&URenderDataExporterSettings::StaticClass,
		"RenderDataExporter",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_URenderDataExporterSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_URenderDataExporterSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_URenderDataExporterSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URenderDataExporterSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URenderDataExporterSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_URenderDataExporterSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(URenderDataExporterSettings, 4274892905);
	template<> RENDERDATAEXPORTER_API UClass* StaticClass<URenderDataExporterSettings>()
	{
		return URenderDataExporterSettings::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_URenderDataExporterSettings(Z_Construct_UClass_URenderDataExporterSettings, &URenderDataExporterSettings::StaticClass, TEXT("/Script/RenderDataExporter"), TEXT("URenderDataExporterSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URenderDataExporterSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
