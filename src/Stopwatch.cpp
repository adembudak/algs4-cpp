#include "algs4/Stopwatch.h"

namespace algs4 {

Stopwatch::Stopwatch() {
    start = std::chrono::steady_clock::now();
}

double Stopwatch::elapsedTime() {
    auto now = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(now - start).count();
}

}
