#include "algs4/StdRandom.h"
#include "algs4/StdOut.h"

#include <cstdlib> // for std::atoi, std::atol

// $ StdRandom_test 5

int main(int argc, const char *argv[]) {
    using namespace algs4;

    const int n = std::atoi(argv[1]);
    if (argc == 3) StdRandom::setSeed(std::atol(argv[2]));

    const auto probabilities = std::vector<double>{0.5, 0.3, 0.1, 0.1};
    const auto frequencies = std::vector<int>{5, 3, 1, 1};
    auto a = std::vector<char>{'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    auto original = a;

    StdOut::printf("seed = %ld\n", StdRandom::getSeed());
    for (int i = 0; i < n; i++) {
        StdOut::printf("%2d ", StdRandom::uniform(100));
        StdOut::printf("%8.5f ", StdRandom::uniform(10.0, 99.0));
        StdOut::printf("%5s ", StdRandom::bernoulli(0.5) ? "true" : "false");
        StdOut::printf("%7.5f ", StdRandom::gaussian(9.0, 0.2));
        StdOut::printf("%1d ", StdRandom::discrete(probabilities));
        StdOut::printf("%1d ", StdRandom::discrete(frequencies));
        StdOut::printf("%11ld ", StdRandom::uniform(100000000000L));
        StdRandom::shuffle(a);
        for (auto s : a)
            StdOut::print(s);
        StdOut::println();
    }
}
