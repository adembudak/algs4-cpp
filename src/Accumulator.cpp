#include "algs4/Accumulator.h"

#include <cmath>
#include <ostream>

namespace algs4 {

void Accumulator::addDataValue(const double x) noexcept {
    n++;
    const double delta = x - mu;
    mu += delta / n;
    sum += (double)(n - 1) / n * delta * delta;
}

double Accumulator::mean() const noexcept {
    return mu;
}

double Accumulator::var() const noexcept {
    if (n <= 1) return 0.0;
    return sum / (n - 1);
}

double Accumulator::stddev() const noexcept {
    return std::sqrt(var());
}

int Accumulator::count() const noexcept {
    return n;
}

std::ostream &operator<<(std::ostream &os, const Accumulator &ac) {
    return os << "n = " << ac.n << ", mean = " << ac.mean() << ", stddev = " << ac.stddev();
}

}
