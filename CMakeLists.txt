cmake_minimum_required(VERSION 3.20)
project(strings LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(strings INTERFACE)
add_library(strings::strings ALIAS strings)

target_include_directories(strings INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

if (MSVC)
  target_compile_options(strings INTERFACE /W4 /permissive-)
else()
  target_compile_options(strings INTERFACE -Wall -Wextra -Wpedantic)
endif()

include(CTest)
enable_testing()

add_executable(strings_basic_test tests/test_basic.cpp)
target_link_libraries(strings_basic_test PRIVATE strings::strings)
add_test(NAME strings.basic COMMAND strings_basic_test)
