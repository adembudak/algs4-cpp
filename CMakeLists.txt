cmake_minimum_required (VERSION 3.21.2)

project (algs4-cpp LANGUAGES CXX)
include (CTest)
enable_testing ()

set (ALGS4_SOURCE_DIR ${PROJECT_SOURCE_DIR})
set (ALGS4_BINARY_DIR ${PROJECT_BINARY_DIR})
set (ALGS4_TEST_DIR "${ALGS4_SOURCE_DIR}/tests")
set (ALGS4_DATA_DIR "${ALGS4_TEST_DIR}/algs4-data")
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ALGS4_SOURCE_DIR}/cmake")

include (add_algs4_executable)
include (add_algs4_test)
include (add_algs4_library)
include (download_algs4_data)

# download test data
if(NOT EXISTS ${ALGS4_DATA_DIR})
  download ("https://algs4.cs.princeton.edu/code/algs4-data.zip" algs4-data.zip)
  extract (algs4-data.zip ${ALGS4_DATA_DIR})
endif()

if(NOT EXISTS ${ALGS4_DATA_DIR}/tinyDouble1D.txt)
  download ("https://introcs.cs.princeton.edu/java/22library/tinyDouble1D.txt"
            ${ALGS4_DATA_DIR}/tinyDouble1D.txt)
  download ("https://introcs.cs.princeton.edu/java/22library/tinyDouble2D.txt"
            ${ALGS4_DATA_DIR}/tinyDouble2D.txt)
  download ("https://introcs.cs.princeton.edu/java/22library/tinyBoolean2D.txt"
            ${ALGS4_DATA_DIR}/tinyBoolean2D.txt)
endif()

add_algs4_library (StdOut SOURCES src/StdOut.cpp)
add_algs4_library (StdIn SOURCES src/StdIn.cpp)
add_algs4_library (In SOURCES src/In.cpp)
add_algs4_library (Out SOURCES src/Out.cpp)
add_algs4_library (StdArrayIO SOURCES src/StdArrayIO.cpp)
add_algs4_library (StdStats SOURCES src/StdStats.cpp)
add_algs4_library (StdRandom SOURCES src/StdRandom.cpp)

add_algs4_library (Accumulator SOURCES src/Accumulator.cpp)
add_algs4_library (Counter SOURCES src/Counter.cpp)
add_algs4_library (Stopwatch SOURCES src/Stopwatch.cpp)
add_algs4_library (BinarySearch SOURCES src/BinarySearch.cpp)
add_algs4_library (ThreeSum SOURCES src/ThreeSum.cpp)
add_algs4_library (ThreeSumFast SOURCES src/ThreeSumFast.cpp)
add_algs4_library (Date SOURCES src/Date.cpp)
add_algs4_library (Transaction SOURCES src/Transaction.cpp DEPENDENCIES Date)
add_algs4_library (Knuth SOURCES src/Knuth.cpp)

##############################################################
add_algs4_executable (StdOut_test SOURCE tests/StdOut_test.cpp LINK StdOut)
add_algs4_test (StdOut_test)

add_algs4_executable (StdIn_test SOURCE tests/StdIn_test.cpp LINK StdIn StdOut)
add_algs4_test (StdIn_test TAKE_INPUT_FROM_STDIN ARGUMENTS ${ALGS4_TEST_DIR}/test-input/StdIn_test.dat)

#TODO add test for StdIn

add_algs4_executable (Out_test SOURCE tests/Out_test.cpp LINK Out)
add_algs4_test (Out_test)

add_algs4_executable (StdArrayIO_test SOURCE tests/StdArrayIO_test.cpp LINK StdArrayIO StdIn StdOut)
#TODO register test fro StdArrayIO

add_algs4_executable (StdStats_test SOURCE tests/StdStats_test.cpp LINK StdStats StdOut StdArrayIO StdIn)
add_algs4_test (StdStats_test TAKE_INPUT_FROM_STDIN ARGUMENTS ${ALGS4_DATA_DIR}/tinyDouble1D.txt)

add_algs4_executable (StdRandom_test SOURCE tests/StdRandom_test.cpp LINK StdRandom StdOut)
add_algs4_test (StdRandom_test ARGUMENTS 5)

add_algs4_executable (Accumulator_test SOURCE tests/Accumulator_test.cpp LINK Accumulator StdIn StdOut)
add_algs4_test (Accumulator_test TAKE_INPUT_FROM_STDIN ARGUMENTS ${ALGS4_TEST_DIR}/test-input/doubles.dat)

add_algs4_executable (Counter_test SOURCE tests/Counter_test.cpp LINK Counter StdRandom StdOut)
add_algs4_test (Counter_test ARGUMENTS 6 600000)

add_algs4_executable (Stopwatch_test SOURCE tests/Stopwatch_test.cpp LINK Stopwatch StdOut)
add_algs4_test (Stopwatch_test ARGUMENTS 100000000)

add_algs4_executable (Binarysearch_test SOURCE tests/Binarysearch_test.cpp LINK StdOut StdIn In BinarySearch)
#TODO register Binarysearch_test

add_algs4_executable (ThreeSum_test SOURCE tests/ThreeSum_test.cpp LINK ThreeSum Stopwatch StdOut In)
add_algs4_test (ThreeSum_test ARGUMENTS ${ALGS4_DATA_DIR}/1Kints.txt)

add_algs4_executable (ThreeSumFast_test SOURCE tests/ThreeSumFast_test.cpp LINK ThreeSumFast BinarySearch
                      StdOut In)
add_algs4_test (ThreeSumFast_test ARGUMENTS ${ALGS4_DATA_DIR}/16Kints.txt)

add_algs4_executable (Knuth_test SOURCE tests/Knuth_test.cpp LINK Knuth StdIn StdOut)
add_algs4_test (Knuth_test TAKE_INPUT_FROM_STDIN ARGUMENTS ${ALGS4_DATA_DIR}/cards.txt)

add_algs4_executable (Date_test SOURCE tests/Date_test.cpp LINK Date StdOut)
add_algs4_test (Date_test)

add_algs4_executable (Average SOURCE src/Average.cpp LINK StdOut StdIn)
add_algs4_test (Average TAKE_INPUT_FROM_STDIN ARGUMENTS ${ALGS4_TEST_DIR}/test-input/doubles.dat)

add_algs4_executable (Cat SOURCE src/Cat.cpp LINK Out In)
# add_algs4_test (Cat ARGUMENTS ${ALGS4_DATA_DIR}/In1.txt ${ALGS4_DATA_DIR}/In2.txt out.txt)

add_algs4_executable (RandomSeq SOURCE src/RandomSeq.cpp LINK StdRandom StdOut)
add_algs4_test (RandomSeq ARGUMENTS 5 100.0 200.0)

add_algs4_executable (Transaction_test SOURCE tests/Transaction_test.cpp LINK Transaction StdOut)
add_algs4_test (Transaction_test)
