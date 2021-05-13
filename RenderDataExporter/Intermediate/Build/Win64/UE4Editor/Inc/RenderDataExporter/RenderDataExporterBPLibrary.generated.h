// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UCameraComponent;
class UStaticMesh;
struct FExportStaticMeshOptions;
#ifdef RENDERDATAEXPORTER_RenderDataExporterBPLibrary_generated_h
#error "RenderDataExporterBPLibrary.generated.h already included, missing '#pragma once' in RenderDataExporterBPLibrary.h"
#endif
#define RENDERDATAEXPORTER_RenderDataExporterBPLibrary_generated_h

#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_221_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FExportStaticMeshOptions_Statics; \
	RENDERDATAEXPORTER_API static class UScriptStruct* StaticStruct();


template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<struct FExportStaticMeshOptions>();

#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_204_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSceneRenderData_Statics; \
	RENDERDATAEXPORTER_API static class UScriptStruct* StaticStruct();


template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<struct FSceneRenderData>();

#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_187_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FDirectionalLightData_Statics; \
	RENDERDATAEXPORTER_API static class UScriptStruct* StaticStruct();


template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<struct FDirectionalLightData>();

#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_164_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FStaticMeshSceneData_Statics; \
	RENDERDATAEXPORTER_API static class UScriptStruct* StaticStruct();


template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<struct FStaticMeshSceneData>();

#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_143_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMeshMaterialData_Statics; \
	RENDERDATAEXPORTER_API static class UScriptStruct* StaticStruct();


template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<struct FMeshMaterialData>();

#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_135_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMaterialInstanceData_Statics; \
	RENDERDATAEXPORTER_API static class UScriptStruct* StaticStruct();


template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<struct FMaterialInstanceData>();

#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_118_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTextureBinData_Statics; \
	RENDERDATAEXPORTER_API static class UScriptStruct* StaticStruct();


template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<struct FTextureBinData>();

#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_89_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCameraData_Statics; \
	RENDERDATAEXPORTER_API static class UScriptStruct* StaticStruct();


template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<struct FCameraData>();

#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_69_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FStaticMeshExportData_Statics; \
	RENDERDATAEXPORTER_API static class UScriptStruct* StaticStruct();


template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<struct FStaticMeshExportData>();

#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_40_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FStaticMeshLODData_Statics; \
	RENDERDATAEXPORTER_API static class UScriptStruct* StaticStruct();


template<> RENDERDATAEXPORTER_API UScriptStruct* StaticStruct<struct FStaticMeshLODData>();

#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_SPARSE_DATA
#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execExportMapToJson); \
	DECLARE_FUNCTION(execExportMapToBinaries); \
	DECLARE_FUNCTION(execExportCamerasToJson); \
	DECLARE_FUNCTION(execExportMeshToJson);


#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execExportMapToJson); \
	DECLARE_FUNCTION(execExportMapToBinaries); \
	DECLARE_FUNCTION(execExportCamerasToJson); \
	DECLARE_FUNCTION(execExportMeshToJson);


#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURenderDataExporterBPLibrary(); \
	friend struct Z_Construct_UClass_URenderDataExporterBPLibrary_Statics; \
public: \
	DECLARE_CLASS(URenderDataExporterBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/RenderDataExporter"), NO_API) \
	DECLARE_SERIALIZER(URenderDataExporterBPLibrary)


#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_INCLASS \
private: \
	static void StaticRegisterNativesURenderDataExporterBPLibrary(); \
	friend struct Z_Construct_UClass_URenderDataExporterBPLibrary_Statics; \
public: \
	DECLARE_CLASS(URenderDataExporterBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/RenderDataExporter"), NO_API) \
	DECLARE_SERIALIZER(URenderDataExporterBPLibrary)


#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URenderDataExporterBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URenderDataExporterBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URenderDataExporterBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URenderDataExporterBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URenderDataExporterBPLibrary(URenderDataExporterBPLibrary&&); \
	NO_API URenderDataExporterBPLibrary(const URenderDataExporterBPLibrary&); \
public:


#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URenderDataExporterBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URenderDataExporterBPLibrary(URenderDataExporterBPLibrary&&); \
	NO_API URenderDataExporterBPLibrary(const URenderDataExporterBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URenderDataExporterBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URenderDataExporterBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URenderDataExporterBPLibrary)


#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_PRIVATE_PROPERTY_OFFSET
#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_243_PROLOG
#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_PRIVATE_PROPERTY_OFFSET \
	hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_SPARSE_DATA \
	hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_RPC_WRAPPERS \
	hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_INCLASS \
	hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_PRIVATE_PROPERTY_OFFSET \
	hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_SPARSE_DATA \
	hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_RPC_WRAPPERS_NO_PURE_DECLS \
	hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_INCLASS_NO_PURE_DECLS \
	hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h_246_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RENDERDATAEXPORTER_API UClass* StaticClass<class URenderDataExporterBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID hellogameplay_Plugins_ResourceExporter_RenderDataExporter_Source_RenderDataExporter_Public_RenderDataExporterBPLibrary_h


#define FOREACH_ENUM_EVERTEXFORMAT(op) \
	op(EVertexFormat::POSITION) \
	op(EVertexFormat::NORMAL) \
	op(EVertexFormat::TEXCOORD0) \
	op(EVertexFormat::TEXCOORD1) \
	op(EVertexFormat::TANGENT) \
	op(EVertexFormat::COLOR) 

enum class EVertexFormat : uint8;
template<> RENDERDATAEXPORTER_API UEnum* StaticEnum<EVertexFormat>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
