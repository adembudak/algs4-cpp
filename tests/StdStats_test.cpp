#include "algs4/StdStats.h"
#include "algs4/StdArrayIO.h"
#include "algs4/StdOut.h"

// run by: StdStats_test < algs4-data/tinyDouble1D.txt

int main(int argc, const char *argv[]) {
    using namespace algs4;

    auto a = StdArrayIO::readDouble1D();

    StdOut::printf("       min %10.3f\n", StdStats::min(a));
    StdOut::printf("      mean %10.3f\n", StdStats::mean(a));
    StdOut::printf("       max %10.3f\n", StdStats::max(a));
    StdOut::printf("    stddev %10.3f\n", StdStats::stddev(a));
    StdOut::printf("       var %10.3f\n", StdStats::var(a));
    StdOut::printf("   stddevp %10.3f\n", StdStats::stddevp(a));
    StdOut::printf("      varp %10.3f\n", StdStats::varp(a));

    return 0;
}
