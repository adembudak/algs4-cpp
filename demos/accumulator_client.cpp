#include "algs4/Accumulator.h"
#include "algs4/StdIn.h"
#include "algs4/StdOut.h"

#include <iostream>

int main() {
    using namespace algs4;

    Accumulator stats;
    while (!StdIn::isEmpty()) {
        double x = StdIn::readDouble();
        stats.addDataValue(x);
    }

    StdOut::printf("n      = %d\n", stats.count());
    StdOut::printf("mean   = %.5f\n", stats.mean());
    StdOut::printf("stddev = %.5f\n", stats.stddev());
    StdOut::printf("var    = %.5f\n", stats.var());

    std::cout << stats << '\n';
    // StdOut::println(stats);
}
