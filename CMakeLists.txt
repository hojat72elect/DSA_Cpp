cmake_minimum_required(VERSION 3.14)
project(DSA_Cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSA_Cpp src/main.cpp
        src/Stack.hpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(StackTests tests/StackTests.cpp src/Stack.hpp)
target_include_directories(StackTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(StackTests GTest::gtest GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(StackTests)
