cmake_minimum_required(VERSION 3.5.1)

project(gmock_c_example)

# GoogleTest requires at least C++ 14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} "./inc")

enable_testing()

add_executable(
	calculator_test
	./test/calculator_test.cc
)

target_link_libraries(
	calculator_test
	GTest::gtest_main
	GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(calculator_test)
