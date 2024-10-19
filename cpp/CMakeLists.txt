cmake_minimum_required(VERSION 3.10)

project(ArrowStudyCpp CXX)

set(CMAKE_GENERATOR "Ninja")

set(CMAKE_CXX_STANDARD 17)

add_executable(arrow-tests src/main.cpp)

enable_testing()
find_package(GTest REQUIRED)

add_executable(tests tests/test_main.cpp)
target_link_libraries(tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)

