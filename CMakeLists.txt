cmake_minimum_required (VERSION 3.21.2)

project (algs4-cpp LANGUAGES CXX)

set (ALGS4_SOURCE_DIR ${PROJECT_SOURCE_DIR})
set (ALGS4_BINARY_DIR ${PROJECT_BINARY_DIR})
set (ALGS4_TEST_DIR "${ALGS4_SOURCE_DIR}/tests")
set (ALGS4_DATA_DIR "${ALGS4_TEST_DIR}/algs4-data")
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ALGS4_SOURCE_DIR}/cmake")

include (get_deps)
include (add_algs4_executable)
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

if(NOT EXISTS ${ALGS4_DATA_DIR}/tinyAllowlist.txt)
  download ("https://algs4.cs.princeton.edu/11model/tinyAllowlist.txt" ${ALGS4_DATA_DIR}/tinyAllowlist.txt)
  download ("https://algs4.cs.princeton.edu/11model/tinyText.txt" ${ALGS4_DATA_DIR}/tinyText.txt)
  download ("https://algs4.cs.princeton.edu/11model/largeAllowlist.txt" ${ALGS4_DATA_DIR}/largeAllowlist.txt)
  download ("https://algs4.cs.princeton.edu/11model/largeText.txt" ${ALGS4_DATA_DIR}/largeText.txt)
endif()

add_algs4_library (StdOut PUBLIC SOURCES src/StdOut.cpp)
add_algs4_library (StdIn PUBLIC SOURCES src/StdIn.cpp)
add_algs4_library (In PUBLIC SOURCES src/In.cpp DEPENDS httplib::httplib)
add_algs4_library (Out PUBLIC SOURCES src/Out.cpp)
add_algs4_library (BinaryIn PUBLIC SOURCES src/BinaryIn.cpp)
add_algs4_library (StdArrayIO PUBLIC SOURCES src/StdArrayIO.cpp)
add_algs4_library (StdStats PUBLIC SOURCES src/StdStats.cpp)
add_algs4_library (StdRandom PUBLIC SOURCES src/StdRandom.cpp)
add_algs4_library (StdDraw PUBLIC SOURCES src/StdDraw.cpp DEPENDS ftxui::screen ftxui::dom ftxui::component)

add_algs4_library (BinarySearch PUBLIC SOURCES src/BinarySearch.cpp)
add_algs4_library (Knuth PUBLIC SOURCES src/Knuth.cpp)
add_algs4_library (Counter PUBLIC SOURCES src/Counter.cpp)
add_algs4_library (StaticSETofInts PUBLIC SOURCES src/StaticSETofInts.cpp)
add_algs4_library (Vector PUBLIC SOURCES src/Vector.cpp)
add_algs4_library (Date PUBLIC SOURCES src/Date.cpp)
add_algs4_library (Transaction PUBLIC SOURCES src/Transaction.cpp DEPENDS Date)
add_algs4_library (Point2D PUBLIC SOURCES src/Point2D.cpp)
add_algs4_library (RectHV PUBLIC SOURCES src/RectHV.cpp DEPENDS Point2D)
add_algs4_library (Interval1D PUBLIC SOURCES src/Interval1D.cpp)
add_algs4_library (Interval2D PUBLIC SOURCES src/Interval2D.cpp DEPENDS Point2D Interval1D)
add_algs4_library (Accumulator PUBLIC SOURCES src/Accumulator.cpp)
add_algs4_library (ResizingArrayStack INTERFACE)
add_algs4_library (Stack INTERFACE)
add_algs4_library (ResizingArrayBag INTERFACE)
add_algs4_library (Bag INTERFACE)
add_algs4_library (Stopwatch PUBLIC SOURCES src/Stopwatch.cpp)
add_algs4_library (LinearRegression PUBLIC SOURCES src/LinearRegression.cpp)
add_algs4_library (ThreeSum PUBLIC SOURCES src/ThreeSum.cpp)
add_algs4_library (ThreeSumFast PUBLIC SOURCES src/ThreeSumFast.cpp)
add_algs4_library (QuickFindUF PUBLIC SOURCES src/QuickFindUF.cpp)
add_algs4_library (QuickUnionUF PUBLIC SOURCES src/QuickUnionUF.cpp)
add_algs4_library (WeightedQuickUnionUF PUBLIC SOURCES src/WeightedQuickUnionUF.cpp)
add_algs4_library (UF PUBLIC SOURCES src/UF.cpp)

add_algs4_library (Insertion INTERFACE)
add_algs4_library (InsertionX INTERFACE)
add_algs4_library (BinaryInsertion INTERFACE)
add_algs4_library (Selection INTERFACE)
add_algs4_library (Shell INTERFACE)
add_algs4_library (Merge INTERFACE)
add_algs4_library (Quick INTERFACE)
add_algs4_library (QuickX INTERFACE)
add_algs4_library (Quick3way INTERFACE)

add_algs4_library (Graph PUBLIC SOURCES src/Graph.cpp DEPENDS In)
add_algs4_library (DepthFirstSearch PUBLIC SOURCES src/DepthFirstSearch.cpp DEPENDS Graph)

##############################################################

add_algs4_executable (StdOut_test SOURCE tests/StdOut_test.cpp LINK StdOut)
add_algs4_executable (StdIn_test SOURCE tests/StdIn_test.cpp LINK StdIn StdOut)
add_algs4_executable (In_test SOURCE tests/In_test.cpp LINK In)
add_algs4_executable (BinaryIn_test SOURCE tests/BinaryIn_test.cpp LINK BinaryIn)
add_algs4_executable (Out_test SOURCE tests/Out_test.cpp LINK Out)
add_algs4_executable (StdArrayIO_test SOURCE tests/StdArrayIO_test.cpp LINK StdArrayIO StdIn StdOut)
add_algs4_executable (StdStats_test SOURCE tests/StdStats_test.cpp LINK StdStats StdOut StdArrayIO StdIn)
add_algs4_executable (StdRandom_test SOURCE tests/StdRandom_test.cpp LINK StdRandom StdOut)
add_algs4_executable (StdDraw_test SOURCE tests/StdDraw_test.cpp LINK StdDraw ftxui::screen ftxui::dom
                      ftxui::component)

add_algs4_executable (Binarysearch_test SOURCE tests/Binarysearch_test.cpp LINK StdOut StdIn In BinarySearch)
add_algs4_executable (RandomSeq SOURCE src/RandomSeq.cpp LINK StdRandom StdOut)
add_algs4_executable (Average SOURCE src/Average.cpp LINK StdOut StdIn)
add_algs4_executable (Cat SOURCE src/Cat.cpp LINK Out In)
add_algs4_executable (Knuth_test SOURCE tests/Knuth_test.cpp LINK Knuth StdIn StdOut)
add_algs4_executable (Counter_test SOURCE tests/Counter_test.cpp LINK Counter StdRandom StdOut)
add_algs4_executable (Allowlist SOURCE src/Allowlist.cpp LINK StaticSETofInts In StdIn StdOut)
add_algs4_executable (Vector_test SOURCE tests/Vector_test.cpp LINK Vector StdOut)
add_algs4_executable (Date_test SOURCE tests/Date_test.cpp LINK Date StdOut)
add_algs4_executable (Transaction_test SOURCE tests/Transaction_test.cpp LINK Transaction StdOut)
add_algs4_executable (Interval1D_test SOURCE tests/Interval1D_test.cpp LINK Interval1D StdOut)
add_algs4_executable (Interval2D_test SOURCE tests/Interval2D_test.cpp LINK Interval2D Interval1D Point2D
                      Counter StdRandom StdOut)
add_algs4_executable (Accumulator_test SOURCE tests/Accumulator_test.cpp LINK Accumulator StdIn StdOut)
add_algs4_executable (ResizingArrayStack_test SOURCE tests/ResizingArrayStack_test.cpp LINK
                      ResizingArrayStack StdIn StdOut)
add_algs4_executable (Stack_test SOURCE tests/Stack_test.cpp LINK Stack StdIn StdOut)
add_algs4_executable (ResizingArrayBag_test SOURCE tests/ResizingArrayBag_test.cpp LINK ResizingArrayBag
                      StdOut)
add_algs4_executable (Bag_test SOURCE tests/Bag_test.cpp LINK StdIn StdOut)
add_algs4_executable (Stopwatch_test SOURCE tests/Stopwatch_test.cpp LINK Stopwatch StdOut)
add_algs4_executable (ThreeSum_test SOURCE tests/ThreeSum_test.cpp LINK ThreeSum Stopwatch StdOut In)
add_algs4_executable (ThreeSumFast_test SOURCE tests/ThreeSumFast_test.cpp LINK ThreeSumFast BinarySearch
                      StdOut In)
add_algs4_executable (DoublingTest SOURCE src/DoublingTest.cpp LINK Stopwatch StdRandom ThreeSum StdOut)
add_algs4_executable (DoublingRatio SOURCE src/DoublingRatio.cpp LINK Stopwatch StdRandom ThreeSum StdOut)
add_algs4_executable (FlipsMax SOURCE src/FlipsMax.cpp LINK Counter StdRandom StdOut)
add_algs4_executable (Rolls SOURCE src/Rolls.cpp LINK StdRandom Counter StdOut)
add_algs4_executable (Fibonacci SOURCE src/Fibonacci.cpp LINK StdOut)
add_algs4_executable (QuickFindUF_test SOURCE tests/QuickFindUF_test.cpp LINK QuickFindUF StdIn StdOut)
add_algs4_executable (QuickUnionUF_test SOURCE tests/QuickUnionUF_test.cpp LINK QuickUnionUF StdIn StdOut)
add_algs4_executable (WeightedQuickUnionUF_test SOURCE tests/WeightedQuickUnionUF_test.cpp LINK
                      WeightedQuickUnionUF StdIn StdOut)
add_algs4_executable (UF_test SOURCE tests/UF_test.cpp LINK UF StdIn StdOut)

add_algs4_executable (Insertion_test SOURCE tests/Insertion_test.cpp LINK Insertion StdIn StdOut)
add_algs4_executable (InsertionX_test SOURCE tests/InsertionX_test.cpp LINK InsertionX StdIn StdOut)
add_algs4_executable (BinaryInsertion_test SOURCE tests/BinaryInsertion_test.cpp LINK BinaryInsertion StdIn
                      StdOut)
add_algs4_executable (Selection_test SOURCE tests/Selection_test.cpp LINK Selection StdIn StdOut)
add_algs4_executable (Shell_test SOURCE tests/Shell_test.cpp LINK Shell StdIn StdOut)

add_algs4_executable (Merge_test SOURCE tests/Merge_test.cpp LINK Merge StdIn StdOut)
add_algs4_executable (Quick_test SOURCE tests/Quick_test.cpp LINK Quick StdRandom StdIn StdOut)
add_algs4_executable (QuickX_test SOURCE tests/QuickX_test.cpp LINK QuickX StdRandom StdIn StdOut)
add_algs4_executable (Quick3way_test SOURCE tests/Quick3way_test.cpp LINK Quick3way StdRandom StdIn StdOut)

add_algs4_executable (Graph_test SOURCE tests/Graph_test.cpp LINK Graph In StdOut)
add_algs4_executable (DepthFirstSearch_test SOURCE tests/DepthFirstSearch_test.cpp LINK DepthFirstSearch
                      Graph In StdIn StdOut)
