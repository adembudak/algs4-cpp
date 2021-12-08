#include "algs4/ThreeSum.h"
#include "algs4/Stopwatch.h"
#include "algs4/In.h"
#include "algs4/StdOut.h"

// $ Threesum_test 1Kints.txt

int main(int argc, const char *argv[]) {
    using namespace algs4;

    In in(argv[1]);
    auto a = in.readAllInts();

    Stopwatch timer;
    int count = ThreeSum::count(a);
    StdOut::println("Elapsed time = " + std::to_string(timer.elapsedTime()));
    StdOut::println(count);

    return 0;
}
