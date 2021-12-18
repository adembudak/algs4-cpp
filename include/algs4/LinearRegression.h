#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include <vector>
#include <string>

namespace algs4 {

class LinearRegression {
  private:
    double m_intercept, m_slope;
    double m_r2;
    double m_svar0, m_svar1;

  public:
    LinearRegression(const std::vector<double> &x, const std::vector<double> &y);

    double intercept() const;
    double slope() const;
    double R2() const;
    double interceptStdErr() const;
    double slopeStdErr() const;
    double predict(const double x);

    operator std::string() const;
};

}

#endif
