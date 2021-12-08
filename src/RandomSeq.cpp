#include "algs4/StdRandom.h"
#include "algs4/StdOut.h"

#include <cstdlib>

// $ RandomSeq 5 100.0 200.0

int main(int argc, const char *argv[]) {
    using namespace algs4;

    int n = std::atoi(argv[1]);

    if (argc == 2) {
        for (int i = 0; i < n; i++) {
            double x = StdRandom::uniform();
            StdOut::println(x);
        }
    }

    else if (argc == 4) {
        double lo = std::atof(argv[2]);
        double hi = std::atof(argv[3]);

        for (int i = 0; i < n; i++) {
            double x = StdRandom::uniform(lo, hi);
            StdOut::printf("%.2f\n", x);
        }
    }

    else {
        StdOut::println("Invalid number of arguments");
    }

    return 0;
}
