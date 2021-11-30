#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

#include <string>

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

    operator std::string() const;
};

}

#endif
