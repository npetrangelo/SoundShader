cmake_minimum_required(VERSION 3.14.0)

set(vst3sdk_SOURCE_DIR /Users/qe/Documents/VST_SDK/vst3sdk)
if(NOT vst3sdk_SOURCE_DIR)
    message(FATAL_ERROR "Path to VST3 SDK is empty!")
endif()

project(SoundShaderEffect)

set(SMTG_VSTGUI_ROOT "${vst3sdk_SOURCE_DIR}")

add_subdirectory(${vst3sdk_SOURCE_DIR} ${PROJECT_BINARY_DIR}/vst3sdk)
smtg_enable_vst3_sdk()

smtg_add_vst3plugin(SoundShaderEffect
    source/version.h
    source/cids.h
    source/processor.h
    source/processor.cpp
    source/controller.h
    source/controller.cpp
    source/entry.cpp
)

#- VSTGUI Wanted ----
if(SMTG_ADD_VSTGUI)
    target_sources(SoundShaderEffect
        PRIVATE
            resource/editor.uidesc
    )
    target_link_libraries(SoundShaderEffect
        PRIVATE
            vstgui_support
    )
    smtg_target_add_plugin_resources(SoundShaderEffect
        RESOURCES
            "resource/editor.uidesc"
    )
endif(SMTG_ADD_VSTGUI)
# -------------------

smtg_target_add_plugin_snapshots (SoundShaderEffect
    RESOURCES
        resource/VST_snapshot.png
        resource/VST_snapshot_2.0x.png
)

target_link_libraries(SoundShaderEffect
    PRIVATE
        sdk
)

if(SMTG_MAC)
    set(CMAKE_OSX_DEPLOYMENT_TARGET 10.12)
    smtg_target_set_bundle(SoundShaderEffect
        BUNDLE_IDENTIFIER com.fam.soundshader.effect
        INFOPLIST "${CMAKE_CURRENT_LIST_DIR}/resource/Info.plist" PREPROCESS
    )
    smtg_target_set_debug_executable(SoundShaderEffect
        "/Applications/VST3PluginTestHost.app"
        "--pluginfolder;$(BUILT_PRODUCTS_DIR)"
    )
elseif(SMTG_WIN)
    target_sources(SoundShaderEffect PRIVATE 
        resource/win32resource.rc
    )
    if(MSVC)
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SoundShaderEffect)

        smtg_target_set_debug_executable(SoundShaderEffect
            "$(ProgramW6432)/Steinberg/VST3PluginTestHost/VST3PluginTestHost.exe"
            "--pluginfolder \"$(OutDir)/\""
        )
    endif()
endif(SMTG_MAC)
