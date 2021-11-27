cmake_minimum_required(VERSION 3.21.2)

project(algs4-cpp LANGUAGES CXX)
include(CMakePrintHelpers)
include(CTest)
enable_testing()

set(ALGS4_SOURCE_DIR ${PROJECT_SOURCE_DIR})
set(ALGS4_BINARY_DIR ${PROJECT_BINARY_DIR})

function(add_algs4_library name)
  set(options PRIVATE PUBLIC INTERFACE)
  set(one_value_args TARGETS)
  set(multi_value_args SOURCES DEPENDENCIES)

  cmake_parse_arguments(${name} "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

  cmake_print_variables(name ${name}_TARGETS ${name}_SOURCES ${name}_DEPENDENCIES)

  set(scope)
  if(${name}_PRIVATE)
    set(scope PRIVATE)
  elseif(${name}_PUBLIC)
    set(scope PUBLIC)
  else()
    set(scope INTERFACE)
  endif()

  add_library(${name} ${${name}_SOURCES})
  target_link_libraries(${name} ${scope} ${${name}_DEPENDENCIES})
  target_include_directories(${name} PUBLIC ${ALGS4_SOURCE_DIR}/include)
endfunction()

add_algs4_library(StdOut SOURCES src/StdOut.cpp)
add_algs4_library(StdIn SOURCES src/StdIn.cpp)

function(add_algs4_test name)
  set(options)
  set(one_value_args TEST_EXECUTABLE SOURCE)
  set(multi_value_args LINK TEST_ARGUMENTS)

  cmake_parse_arguments(${name} "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

  add_executable(${name} ${${name}_SOURCE})
  target_link_libraries(${name} PRIVATE ${${name}_LINK})

  add_test(NAME ${name} COMMAND ${name} ${${TEST_ARGUMENTS}})
endfunction()

add_algs4_test(StdOut_test SOURCE tests/StdOut_test.cpp LINK StdOut)
add_algs4_test(StdIn_read_one_by_one SOURCE tests/StdIn_read_one_by_one.cpp LINK StdIn)
add_algs4_test(StdIn_readAll_test SOURCE tests/StdIn_readAll_test.cpp LINK StdIn StdOut)
add_algs4_test(StdIn_readAllStrings_test SOURCE tests/StdIn_readAllStrings_test.cpp LINK StdIn StdOut)
add_algs4_test(StdIn_readAllLines_test SOURCE tests/StdIn_readAllLines_test.cpp LINK StdIn StdOut)
add_algs4_test(StdIn_readAllInts_test SOURCE tests/StdIn_readAllInts_test.cpp LINK StdIn StdOut)
add_algs4_test(StdIn_readAllDoubles_test SOURCE tests/StdIn_readAllDoubles.cpp LINK StdIn StdOut)
add_algs4_test(StdIn_readAllLongs_test SOURCE tests/StdIn_readAllLongs_test.cpp LINK StdIn StdOut)
add_algs4_test(StdIn_isEmpty SOURCE tests/StdIn_isEmpty.cpp LINK StdIn)
add_algs4_test(StdIn_hasNextChar SOURCE tests/StdIn_hasNextChar.cpp LINK StdIn)
add_algs4_test(StdIn_hasNextLine SOURCE tests/StdIn_hasNextLine.cpp LINK StdIn)

