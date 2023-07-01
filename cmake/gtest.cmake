include(FetchContent)

message(STATUS "Fetching Google Test...")

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP true
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

message(STATUS "googletest_SOURCE_DIR: ${googletest_SOURCE_DIR}")
message(STATUS "googletest_BINARY_DIR: ${googletest_BINARY_DIR}")