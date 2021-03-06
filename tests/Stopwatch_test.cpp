#include "algs4/Stopwatch.h"
#include "algs4/StdOut.h"

#include <cmath>
#include <cstdlib>

// $ Stopwatch_test 100000000

int main(int argc, const char *argv[]) {
    using namespace algs4;

    int n = std::atoi(argv[1]);

    Stopwatch timer1;
    double sum1 = 0.0;

    for (int i = 1; i <= n; i++) {
        sum1 += std::sqrt(i);
    }

    double time1 = timer1.elapsedTime();
    StdOut::printf("%e (%.2f seconds)\n", sum1, time1);

    Stopwatch timer2;
    double sum2 = 0.0;

    for (int i = 1; i <= n; i++) {
        sum2 += std::pow(i, 0.5);
    }

    double time2 = timer2.elapsedTime();
    StdOut::printf("%e (%.2f seconds)\n", sum2, time2);

    return 0;
}
