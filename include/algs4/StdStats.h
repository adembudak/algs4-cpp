#ifndef STDSTATS_H
#define STDSTATS_H

#include <vector>
#include <limits>
#include <cstddef>

namespace algs4 {

namespace StdStats {

const double double_INF = std::numeric_limits<double>::infinity();
const double negative_double_INF = -std::numeric_limits<double>::infinity();
const double double_NaN = std::numeric_limits<double>::quiet_NaN();

const int int_MIN = std::numeric_limits<int>::min();
const int int_MAX = std::numeric_limits<int>::max();

double max(const std::vector<double> &a);
double max(const std::vector<double> &a, const std::size_t lo, const std::size_t hi);
int max(const std::vector<int> &a);

double min(const std::vector<double> &a);
double min(const std::vector<double> &a, const std::size_t lo, const std::size_t hi);
int min(const std::vector<int> &a);

double sum(const std::vector<double> &a);
int sum(const std::vector<int> &a);
double sum(const std::vector<double> &a, const std::size_t lo, const std::size_t hi);

double mean(const std::vector<double> &a);
double mean(const std::vector<double> &a, const std::size_t lo, const std::size_t hi);
double mean(const std::vector<int> &a);

double var(const std::vector<double> &a);
double var(const std::vector<double> &a, const std::size_t lo, const std::size_t hi);
double var(const std::vector<int> &a);

double varp(const std::vector<double> &a);
double varp(const std::vector<double> &a, const std::size_t lo, const std::size_t hi);

double stddev(const std::vector<double> &a);
double stddev(const std::vector<int> &a);
double stddev(const std::vector<double> &a, const std::size_t lo, const std::size_t hi);

double stddevp(const std::vector<double> &a);
double stddevp(const std::vector<double> &a, const std::size_t lo, const std::size_t hi);

}
}

#endif
