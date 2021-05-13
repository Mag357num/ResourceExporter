// Copyright Epic Games, Inc. All Rights Reserved.

#include "RenderDataExporter.h"
#include "RenderDataExporterSettings.h"
#include "ISettingsModule.h"

#define LOCTEXT_NAMESPACE "FRenderDataExporterModule"

void FRenderDataExporterModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        SettingsModule->RegisterSettings(
            "Project", "Plugins", "RenderDataExporter",
            LOCTEXT("Settings Name", "Render Data Exporter"),
            LOCTEXT("Settings Description", "Configure the RenderDataExporter plugin"),
            GetMutableDefault< URenderDataExporterSettings >());
    }
}

void FRenderDataExporterModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        SettingsModule->UnregisterSettings("Project", "Plugins", "RenderDataExporter");
    }
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRenderDataExporterModule, RenderDataExporter)