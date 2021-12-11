#include <algs4/Interval1D.h>
#include <algs4/StdOut.h>

#include <algorithm> // for std::sort

int main() {
    using namespace algs4;

    Interval1D intervals[4];
    intervals[0] = Interval1D(15.0, 33.0);
    intervals[1] = Interval1D(45.0, 60.0);
    intervals[2] = Interval1D(20.0, 70.0);
    intervals[3] = Interval1D(46.0, 55.0);

    StdOut::println("Unsorted");
    for (int i = 0; i < 4; i++)
        StdOut::println(intervals[i]);
    StdOut::println();

    StdOut::println("Sort by min endpoint");
    std::sort(std::begin(intervals), std::end(intervals), MinEndpointComparator);
    for (int i = 0; i < 4; i++)
        StdOut::println(intervals[i]);
    StdOut::println();

    StdOut::println("Sort by max endpoint");
    std::sort(std::begin(intervals), std::end(intervals), MaxEndpointComparator);
    for (int i = 0; i < 4; i++)
        StdOut::println(intervals[i]);
    StdOut::println();

    StdOut::println("Sort by length");
    std::sort(std::begin(intervals), std::end(intervals), LengthComparator);
    for (int i = 0; i < 4; i++)
        StdOut::println(intervals[i]);
    StdOut::println();

    return 0;
}
