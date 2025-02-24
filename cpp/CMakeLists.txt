cmake_minimum_required(VERSION 3.10)

project(ArrowStudyCpp CXX)

set(CMAKE_GENERATOR "Ninja")

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(ARROW REQUIRED arrow)

add_executable(arrow-tests
    src/main.cpp
#    src/dummy_extension.cpp
)
include_directories(include)

enable_testing()
find_package(GTest REQUIRED)

add_executable(tests 
    tests/test_array.cpp
    tests/test_array_statistics.cpp
    tests/test_binary_view.cpp
    tests/test_extension.cpp
    tests/test_main.cpp
    tests/test_memory_pool.cpp
    tests/test_record_batch.cpp
)
target_link_libraries(tests GTest::gtest_main ${ARROW_LIBRARIES})
target_link_libraries(arrow-tests GTest::gtest_main ${ARROW_LIBRARIES})
target_include_directories(tests PRIVATE ${ARROW_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(arrow-tests PRIVATE ${ARROW_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_directories(tests PRIVATE ${ARROW_LIBRARY_DIRS})
target_link_directories(arrow-tests PRIVATE ${ARROW_LIBRARY_DIRS})


include(GoogleTest)
gtest_discover_tests(tests)

