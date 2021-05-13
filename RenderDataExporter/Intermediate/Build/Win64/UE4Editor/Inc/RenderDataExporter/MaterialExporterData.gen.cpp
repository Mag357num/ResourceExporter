// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RenderDataExporter/Public/MaterialExporterData.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMaterialExporterData() {}
// Cross Module References
	RENDERDATAEXPORTER_API UClass* Z_Construct_UClass_UMaterialExporterData_NoRegister();
	RENDERDATAEXPORTER_API UClass* Z_Construct_UClass_UMaterialExporterData();
	ENGINE_API UClass* Z_Construct_UClass_UAssetUserData();
	UPackage* Z_Construct_UPackage__Script_RenderDataExporter();
// End Cross Module References
	void UMaterialExporterData::StaticRegisterNativesUMaterialExporterData()
	{
	}
	UClass* Z_Construct_UClass_UMaterialExporterData_NoRegister()
	{
		return UMaterialExporterData::StaticClass();
	}
	struct Z_Construct_UClass_UMaterialExporterData_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
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
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMaterialExporterData_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAssetUserData,
		(UObject* (*)())Z_Construct_UPackage__Script_RenderDataExporter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExporterData_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MaterialExporterData.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/MaterialExporterData.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExporterData_Statics::NewProp_ShadingModel_MetaData[] = {
		{ "Category", "MaterialExporterData" },
		{ "ModuleRelativePath", "Public/MaterialExporterData.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UMaterialExporterData_Statics::NewProp_ShadingModel = { "ShadingModel", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMaterialExporterData, ShadingModel), METADATA_PARAMS(Z_Construct_UClass_UMaterialExporterData_Statics::NewProp_ShadingModel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExporterData_Statics::NewProp_ShadingModel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExporterData_Statics::NewProp_VertexShaderPath_MetaData[] = {
		{ "Category", "MaterialExporterData" },
		{ "ModuleRelativePath", "Public/MaterialExporterData.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UMaterialExporterData_Statics::NewProp_VertexShaderPath = { "VertexShaderPath", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMaterialExporterData, VertexShaderPath), METADATA_PARAMS(Z_Construct_UClass_UMaterialExporterData_Statics::NewProp_VertexShaderPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExporterData_Statics::NewProp_VertexShaderPath_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExporterData_Statics::NewProp_PixelShaderPath_MetaData[] = {
		{ "Category", "MaterialExporterData" },
		{ "ModuleRelativePath", "Public/MaterialExporterData.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UMaterialExporterData_Statics::NewProp_PixelShaderPath = { "PixelShaderPath", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMaterialExporterData, PixelShaderPath), METADATA_PARAMS(Z_Construct_UClass_UMaterialExporterData_Statics::NewProp_PixelShaderPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExporterData_Statics::NewProp_PixelShaderPath_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMaterialExporterData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExporterData_Statics::NewProp_ShadingModel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExporterData_Statics::NewProp_VertexShaderPath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExporterData_Statics::NewProp_PixelShaderPath,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMaterialExporterData_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMaterialExporterData>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMaterialExporterData_Statics::ClassParams = {
		&UMaterialExporterData::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMaterialExporterData_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExporterData_Statics::PropPointers),
		0,
		0x003010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMaterialExporterData_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExporterData_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMaterialExporterData()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMaterialExporterData_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMaterialExporterData, 2592044184);
	template<> RENDERDATAEXPORTER_API UClass* StaticClass<UMaterialExporterData>()
	{
		return UMaterialExporterData::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMaterialExporterData(Z_Construct_UClass_UMaterialExporterData, &UMaterialExporterData::StaticClass, TEXT("/Script/RenderDataExporter"), TEXT("UMaterialExporterData"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMaterialExporterData);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
