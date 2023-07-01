include(FetchContent)

message(STATUS "Fetching JUCE...")

FetchContent_Declare(
    juce
    URL https://github.com/juce-framework/JUCE/archive/refs/tags/7.0.5.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP true
)

FetchContent_MakeAvailable(juce)

message(STATUS "juce_SOURCE_DIR: ${juce_SOURCE_DIR}")
message(STATUS "juce_BINARY_DIR: ${juce_BINARY_DIR}")

set(juce_modules
    juce::juce_audio_basics
    juce::juce_audio_devices
    juce::juce_audio_formats
    juce::juce_audio_plugin_client
    juce::juce_audio_processors
    juce::juce_audio_utils
    juce::juce_core
    juce::juce_data_structures
    juce::juce_events
    juce::juce_graphics
    juce::juce_gui_basics
    juce::juce_gui_extra
)