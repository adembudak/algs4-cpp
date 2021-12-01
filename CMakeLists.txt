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

add_algs4_library (In SOURCES src/In.cpp)
add_algs4_library (Out SOURCES src/Out.cpp)

add_algs4_library (Accumulator SOURCES src/Accumulator.cpp)
add_algs4_library (Stopwatch SOURCES src/Stopwatch.cpp)

add_algs4_test (StdOut_test SOURCE tests/StdOut_test.cpp LINK StdOut)

#[[
# Following commented tests expect argument from std::cin
# FIXME: how to pass file argument to std::cin with add_test(), 
# i.e. mimic this shell behivior: StdIn_read_one_by_one < primitives.txt
#                                                       ^--- this thing

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
]]#

add_algs4_test (In_read_one_by_one_test SOURCE tests/In_read_one_by_one_test.cpp WORKING_DIR
                ${ALGS4_SOURCE_DIR}/tests ARGUMENTS primitives.dat LINK In)

add_algs4_test (In_readAllInts_test SOURCE tests/In_readAllInts_test.cpp WORKING_DIR
                ${ALGS4_SOURCE_DIR}/tests ARGUMENTS ints.dat LINK In)

add_algs4_test (In_readAllDoubles_test SOURCE tests/In_readAllDoubles_test.cpp WORKING_DIR
                ${ALGS4_SOURCE_DIR}/tests ARGUMENTS doubles.dat LINK In)

add_algs4_test (In_readAllLongs_test SOURCE tests/In_readAllLongs_test.cpp WORKING_DIR
                ${ALGS4_SOURCE_DIR}/tests ARGUMENTS longs.dat LINK In)

add_algs4_test (In_readString_test SOURCE tests/In_readString_test.cpp WORKING_DIR
                ${ALGS4_SOURCE_DIR}/tests ARGUMENTS lorem_ipsum.dat LINK In)

add_algs4_test (In_readLine_test SOURCE tests/In_readLine_test.cpp WORKING_DIR
                ${ALGS4_SOURCE_DIR}/tests ARGUMENTS lorem_ipsum.dat LINK In)

add_algs4_test (In_readAllStrings_test SOURCE tests/In_readAllStrings_test.cpp WORKING_DIR
                ${ALGS4_SOURCE_DIR}/tests ARGUMENTS lorem_ipsum.dat LINK In)

add_algs4_test (In_readAllLines_test SOURCE tests/In_readAllLines_test.cpp WORKING_DIR
                ${ALGS4_SOURCE_DIR}/tests ARGUMENTS lorem_ipsum.dat LINK In)

add_algs4_test (Out_test SOURCE tests/Out_test.cpp WORKING_DIR ${ALGS4_SOURCE_DIR}/tests LINK Out)

add_algs4_executable (accumulator_demo SOURCE demos/accumulator_client.cpp LINK Accumulator StdIn StdOut)
add_algs4_executable (stopwatch_demo SOURCE demos/stopwatch_client.cpp LINK Accumulator Stopwatch StdOut)
