#include <algs4/LinearRegression.h>

#include <vector>
#include <cstdint>
#include <cmath>
#include <string>
#include <sstream>

namespace algs4 {

LinearRegression::LinearRegression(const std::vector<double> &x, const std::vector<double> &y) {
    const std::size_t n = x.size();

    // first pass
    double sumx = 0.0, sumy = 0.0, sumx2 = 0.0;
    for (std::size_t i = 0; i < n; i++) {
        sumx += x[i];
        sumx2 += x[i] * x[i];
        sumy += y[i];
    }

    double xbar = sumx / n;
    double ybar = sumy / n;

    // second pass: compute summary statistics
    double xxbar = 0.0, yybar = 0.0, xybar = 0.0;
    for (std::size_t i = 0; i < n; i++) {
        xxbar += (x[i] - xbar) * (x[i] - xbar);
        yybar += (y[i] - ybar) * (y[i] - ybar);
        xybar += (x[i] - xbar) * (y[i] - ybar);
    }
    m_slope = xybar / xxbar;
    m_intercept = ybar - m_slope * xbar;

    // more statistical analysis
    double rss = 0.0; // residual sum of squares
    double ssr = 0.0; // regression sum of squares
    for (int i = 0; i < n; i++) {
        double fit = m_slope * x[i] + m_intercept;
        rss += (fit - y[i]) * (fit - y[i]);
        ssr += (fit - ybar) * (fit - ybar);
    }

    int degreesOfFreedom = n - 2;
    m_r2 = ssr / yybar;
    double svar = rss / degreesOfFreedom;
    m_svar1 = svar / xxbar;
    m_svar0 = svar / n + xbar * xbar * m_svar1;
}

double LinearRegression::intercept() const {
    return m_intercept;
}

double LinearRegression::slope() const {
    return m_slope;
}

double LinearRegression::R2() const {
    return m_r2;
}

double LinearRegression::interceptStdErr() const {
    return std::sqrt(m_svar0);
}

double LinearRegression::slopeStdErr() const {
    return std::sqrt(m_svar1);
}

double LinearRegression::predict(const double x) {
    return m_slope * x + m_intercept;
}

LinearRegression::operator std::string() const {
    std::ostringstream ss;
    ss << slope() << " n + " << intercept();
    ss << "  (R^2 = " << R2() << ")";
    return ss.str();
}

}
