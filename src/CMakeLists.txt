
# Specify "-G Xcode" for AU build
set(plugin_name "PluginHostSG")

# TODO
#file(READ "${CMAKE_CURRENT_SOURCE_DIR}/Info.plist" plist_content_to_merge)

juce_add_plugin(${plugin_name}
    PRODUCT_NAME "PluginHostSG"
    VERSION "${project_version}"
    COMPANY_COPYRIGHT "© 2023 Saigon AT"
    COMPANY_NAME "Saigon Audio Technology"
    COMPANY_WEBSITE "www.SaigonAudioTechnology.com"
    FORMATS VST3 AU Standalone
    PLUGIN_MANUFACTURER_CODE "Sgat"
    PLUGIN_CODE "Phsg"
    PLUGINHOST_AU TRUE
    #PLIST_TO_MERGE "${plist_content_to_merge}"
)

target_compile_definitions(${plugin_name} PUBLIC
    JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
    JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
    JUCE_VST3_CAN_REPLACE_VST2=0
    JUCE_PLUGINHOST_LADSPA=0
    JUCE_PLUGINHOST_VST3=1
    JUCE_PLUGINHOST_AU=1
)

target_include_directories(${plugin_name} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(${plugin_name} PRIVATE
    JuceHeader.h
    PluginEditor.h
    PluginEditor.cpp
    PluginProcessor.h
    PluginProcessor.cpp
)

target_link_libraries(${plugin_name}
    PRIVATE
    ${juce_modules}
    PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
)