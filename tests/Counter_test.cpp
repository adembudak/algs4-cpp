#include <algs4/Counter.h>
#include <algs4/StdRandom.h>
#include <algs4/StdOut.h>

#include <cstdlib>

// Counter_test 6 600000

int main(int argc, const char *argv[]) {
    using namespace algs4;

    int n = std::atoi(argv[1]);
    int trials = std::atoi(argv[2]);

    // create n counters
    std::vector<Counter> hits(n);

    for (int i = 0; i < n; i++) {
        hits[i] = Counter("counter" + std::to_string(i));
    }

    // increment trials counters at random
    for (int t = 0; t < trials; t++) {
        hits[StdRandom::uniform(n)].increment();
    }

    // print results
    for (int i = 0; i < n; i++) {
        StdOut::println(hits[i]);
    }

    return 0;
}
