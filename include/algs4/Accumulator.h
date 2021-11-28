#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

#include <iosfwd>

namespace algs4 {

class Accumulator {
  private:
    int n = 0;
    double sum = 0.0;
    double mu = 0.0;

  public:
    void addDataValue(const double x) noexcept;

    double mean() const noexcept;
    double var() const noexcept;
    double stddev() const noexcept;
    int count() const noexcept;

    friend std::ostream &operator<<(std::ostream &os, const Accumulator &ac);
};

}

#endif
