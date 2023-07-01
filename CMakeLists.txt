include("cmake/juce.cmake")

cmake_minimum_required(VERSION 3.24)

# Don't change project version (this value is replaced in the release pipeline)
project(PluginHostSG VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64") # Always build universal binary on OSX
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.11) # El Capitan

add_compile_definitions(JUCE_DISPLAY_SPLASH_SCREEN=0)

# Build warnings

add_subdirectory(src)
#add_subdirectory(utests)