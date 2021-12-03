cmake_minimum_required (VERSION 3.21.2)

project (algs4-cpp LANGUAGES CXX)
include (CMakePrintHelpers)
include (CTest)

set (ALGS4_SOURCE_DIR ${PROJECT_SOURCE_DIR})
set (ALGS4_BINARY_DIR ${PROJECT_BINARY_DIR})
set (ALGS4_DATA_DIR "${ALGS4_SOURCE_DIR}/demos/algs4-data")
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ALGS4_SOURCE_DIR}/cmake")

include (add_algs4_executable)
include (add_algs4_test)
include (add_algs4_library)
include (download_algs4_data)

option (WITH_TESTS "" FALSE)
option (WITH_DEMOS "" TRUE)

add_algs4_library (StdOut SOURCES src/StdOut.cpp)
add_algs4_library (StdIn SOURCES src/StdIn.cpp)
add_algs4_library (In SOURCES src/In.cpp)
add_algs4_library (Out SOURCES src/Out.cpp)
add_algs4_library (StdArrayIO SOURCES src/StdArrayIO.cpp)
add_algs4_library (StdStats SOURCES src/StdStats.cpp)

add_algs4_library (Accumulator SOURCES src/Accumulator.cpp)
add_algs4_library (Counter SOURCES src/Counter.cpp)
add_algs4_library (Stopwatch SOURCES src/Stopwatch.cpp)
add_algs4_library (BinarySearch SOURCES src/BinarySearch.cpp)
add_algs4_library (ThreeSum SOURCES src/ThreeSum.cpp)
add_algs4_library (ThreeSumFast SOURCES src/ThreeSumFast.cpp)

if(WITH_TESTS)
  enable_testing ()
  add_algs4_test (StdOut_test SOURCE tests/StdOut_test.cpp LINK StdOut)

  #[[
# Following commented tests expect argument from std::cin
# FIXME: how to pass file argument to std::cin with add_test(),
# i.e. mimic this shell bahavior: StdIn_read_one_by_one < primitives.txt
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
]]
  #

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

  add_algs4_test (In_readLine_test SOURCE tests/In_readLine_test.cpp WORKING_DIR ${ALGS4_SOURCE_DIR}/tests
                  ARGUMENTS lorem_ipsum.dat LINK In)

  add_algs4_test (In_readAllStrings_test SOURCE tests/In_readAllStrings_test.cpp WORKING_DIR
                  ${ALGS4_SOURCE_DIR}/tests ARGUMENTS lorem_ipsum.dat LINK In)

  add_algs4_test (In_readAllLines_test SOURCE tests/In_readAllLines_test.cpp WORKING_DIR
                  ${ALGS4_SOURCE_DIR}/tests ARGUMENTS lorem_ipsum.dat LINK In)

  add_algs4_test (Out_test SOURCE tests/Out_test.cpp WORKING_DIR ${ALGS4_SOURCE_DIR}/tests LINK Out)

  if(NOT EXISTS ${ALGS4_DATA_DIR}/tinyDouble1D.txt)
    download ("https://introcs.cs.princeton.edu/java/22library/tinyDouble1D.txt"
              ${ALGS4_DATA_DIR}/tinyDouble1D.txt)
    download ("https://introcs.cs.princeton.edu/java/22library/tinyDouble2D.txt"
              ${ALGS4_DATA_DIR}/tinyDouble2D.txt)
    download ("https://introcs.cs.princeton.edu/java/22library/tinyBoolean2D.txt"
              ${ALGS4_DATA_DIR}/tinyBoolean2D.txt)
  endif()
  add_algs4_test (StdArrayIO_test SOURCE tests/StdArrayIO_test.cpp WORKING_DIR ${ALGS4_SOURCE_DIR}/tests LINK
                  StdArrayIO StdIn StdOut)

  add_algs4_test (StdStats_test SOURCE tests/StdStats_test.cpp WORKING_DIR ${ALGS4_SOURCE_DIR}/tests LINK
                  StdStats StdOut StdArrayIO StdIn)
endif()

if(WITH_DEMOS)
  if(NOT EXISTS ${ALGS4_SOURCE_DIR}/demos)
    download ("https://algs4.cs.princeton.edu/code/algs4-data.zip" algs4-data.zip)
    extract (algs4-data.zip ${ALGS4_DATA_DIR})
  endif()

  add_algs4_executable (accumulator_demo SOURCE demos/accumulator_client.cpp LINK Accumulator StdIn StdOut)
  add_algs4_executable (stopwatch_demo SOURCE demos/stopwatch_client.cpp LINK Accumulator Stopwatch StdOut)
  add_algs4_executable (threesum_demo SOURCE demos/threesum_client.cpp LINK ThreeSum Stopwatch StdOut In)
  add_algs4_executable (binarysearch_demo SOURCE demos/binarysearch_client.cpp LINK StdOut StdIn In
                        BinarySearch)
  add_algs4_executable (threesumfast_demo SOURCE demos/threesumfast_client.cpp LINK ThreeSumFast StdOut In
                        BinarySearch)
endif()
