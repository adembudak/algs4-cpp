cmake_minimum_required (VERSION 3.21.2)

project (algs4-cpp LANGUAGES CXX)
include (CMakePrintHelpers)
include (CTest)
enable_testing ()

set (ALGS4_SOURCE_DIR ${PROJECT_SOURCE_DIR})
set (ALGS4_BINARY_DIR ${PROJECT_BINARY_DIR})
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ALGS4_SOURCE_DIR}/cmake")

include (add_algs4_executable)
include (add_algs4_test)
include (add_algs4_library)

add_algs4_library (StdOut SOURCES src/StdOut.cpp)
add_algs4_library (StdIn SOURCES src/StdIn.cpp)

add_algs4_library (Accumulator SOURCES src/Accumulator.cpp)

add_algs4_test (StdOut_test SOURCE tests/StdOut_test.cpp LINK StdOut)
add_algs4_test (StdIn_read_one_by_one SOURCE tests/StdIn_read_one_by_one_test.cpp LINK StdIn)
add_algs4_test (StdIn_readAll_test SOURCE tests/StdIn_readAll_test.cpp LINK StdIn StdOut)
add_algs4_test (StdIn_readAllStrings_test SOURCE tests/StdIn_readAllStrings_test.cpp LINK StdIn StdOut)
add_algs4_test (StdIn_readAllLines_test SOURCE tests/StdIn_readAllLines_test.cpp LINK StdIn StdOut)
add_algs4_test (StdIn_readAllInts_test SOURCE tests/StdIn_readAllInts_test.cpp LINK StdIn StdOut)
add_algs4_test (StdIn_readAllDoubles_test SOURCE tests/StdIn_readAllDoubles_test.cpp LINK StdIn StdOut)
add_algs4_test (StdIn_readAllLongs_test SOURCE tests/StdIn_readAllLongs_test.cpp LINK StdIn StdOut)
add_algs4_test (StdIn_isEmpty_test SOURCE tests/StdIn_isEmpty_test.cpp LINK StdIn)
add_algs4_test (StdIn_hasNextChar_test SOURCE tests/StdIn_hasNextChar_test.cpp LINK StdIn)
add_algs4_test (StdIn_hasNextLine_test SOURCE tests/StdIn_hasNextLine_test.cpp LINK StdIn)

add_algs4_executable (accumulator_demo SOURCE demos/accumulator_client.cpp LINK Accumulator StdIn StdOut)
