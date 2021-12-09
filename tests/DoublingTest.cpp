#include <algs4/Stopwatch.h>
#include <algs4/StdRandom.h>
#include <algs4/ThreeSum.h>
#include <algs4/StdOut.h>

#include <vector>
#include <cstdint>

// $ DoublingTest

namespace algs4 {

constexpr int MAXIMUM_INTEGER = 1000000;

double timeTrial(const std::size_t n) {

    std::vector<int> a(n);

    for (std::size_t i = 0; i < n; i++) {
        a[i] = StdRandom::uniform(-MAXIMUM_INTEGER, MAXIMUM_INTEGER);
    }

    Stopwatch timer;
    ThreeSum::count(a);
    return timer.elapsedTime();
}

}

int main() {
    using namespace algs4;
    for (std::size_t n = 250; true; n += n) {
        double time = timeTrial(n);
        StdOut::printf("%7d %7.1f\n", n, time);
    }
}
