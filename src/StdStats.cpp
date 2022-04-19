#include "algs4/StdStats.h"

#include <vector>
#include <limits>
#include <cmath>
#include <cstddef>

namespace algs4 {

namespace StdStats {

double max(const std::vector<double> &a) {
    double max = negative_double_INF;

    for (std::size_t i = 0; i < a.size(); i++) {
        if (std::isnan(a[i])) return double_NaN;
        if (a[i] > max) max = a[i];
    }
    return max;
}

// find maximum value in subarray [lo, hi) of a
double max(const std::vector<double> &a, const std::size_t lo, const std::size_t hi) {
    double max_ = negative_double_INF;

    for (auto i = lo; i < hi; i++) {
        if (std::isnan(a[i])) return double_NaN;
        if (a[i] > max_) max_ = a[i];
    }
    return max_;
}

int max(const std::vector<int> &a) {
    int max_ = int_MIN;

    for (std::size_t i = 0; i < a.size(); i++) {
        if (a[i] > max_) max_ = a[i];
    }
    return max_;
}

double min(const std::vector<double> &a) {
    double min_ = double_INF;

    for (std::size_t i = 0; i < a.size(); i++) {
        if (std::isnan(a[i])) return double_NaN;
        if (a[i] < min_) min_ = a[i];
    }
    return min_;
}

double min(const std::vector<double> &a, const std::size_t lo, const std::size_t hi) {
    double min = double_INF;

    for (auto i = lo; i < hi; i++) {
        if (std::isnan(a[i])) return double_NaN;
        if (a[i] < min) min = a[i];
    }
    return min;
}

int min(const std::vector<int> &a) {
    int min = int_MAX;

    for (std::size_t i = 0; i < a.size(); i++) {
        if (a[i] < min) min = a[i];
    }
    return min;
}

double sum(const std::vector<double> &a) {
    double sum = 0.0;
    for (std::size_t i = 0; i < a.size(); i++) {
        sum += a[i];
    }
    return sum;
}

int sum(const std::vector<int> &a) {
    int sum = 0.0;
    for (std::size_t i = 0; i < a.size(); i++) {
        sum += a[i];
    }
    return sum;
}

double sum(const std::vector<double> &a, const std::size_t lo, const std::size_t hi) {
    double sum_ = 0.0;
    for (auto i = lo; i < hi; i++) {
        sum_ += a[i];
    }
    return sum_;
}

double mean(const std::vector<double> &a) {

    if (a.empty()) return double_NaN;
    const double sum_ = sum(a);
    return sum_ / double(a.size());
}

double mean(const std::vector<double> &a, const std::size_t lo, const std::size_t hi) {
    const auto length = hi - lo;
    if (length == 0) return double_NaN;

    double sum_ = sum(a, lo, hi);
    return sum_ / double(length);
}

double mean(const std::vector<int> &a) {

    if (a.empty()) return double_NaN;
    const int sum_ = sum(a);
    return double(sum_) / double(a.size());
}

double var(const std::vector<double> &a) {

    if (a.empty()) return double_NaN;

    const double avg = mean(a);
    double sum = 0.0;

    for (std::size_t i = 0; i < a.size(); i++)
        sum += (a[i] - avg) * (a[i] - avg);

    return sum / double(a.size() - 1);
}

double var(const std::vector<double> &a, const std::size_t lo, const std::size_t hi) {
    const auto length = hi - lo;
    if (length == 0) return double_NaN;

    double avg = mean(a, lo, hi);
    double sum = 0.0;

    for (auto i = lo; i < hi; i++)
        sum += (a[i] - avg) * (a[i] - avg);

    return sum / double(length - 1);
}

double var(const std::vector<int> &a) {

    if (a.empty()) return double_NaN;

    const double avg = mean(a);
    double sum = 0.0;

    for (std::size_t i = 0; i < a.size(); i++)
        sum += (a[i] - avg) * (a[i] - avg);

    return sum / double(a.size() - 1);
}

double varp(const std::vector<double> &a) {

    if (a.empty()) return double_NaN;

    const double avg = mean(a);
    double sum = 0.0;

    for (std::size_t i = 0; i < a.size(); i++)
        sum += (a[i] - avg) * (a[i] - avg);

    return sum / double(a.size());
}

double varp(const std::vector<double> &a, const std::size_t lo, const std::size_t hi) {

    const auto length = hi - lo;
    if (length == 0) return double_NaN;

    const double avg = mean(a, lo, hi);
    double sum = 0.0;

    for (auto i = lo; i < hi; i++)
        sum += (a[i] - avg) * (a[i] - avg);

    return sum / double(a.size());
}

double stddev(const std::vector<double> &a) {
    return std::sqrt(var(a));
}

double stddev(const std::vector<int> &a) {
    return std::sqrt(var(a));
}

double stddev(const std::vector<double> &a, const std::size_t lo, const std::size_t hi) {
    return std::sqrt(var(a, lo, hi));
}

double stddevp(const std::vector<double> &a) {
    return std::sqrt(varp(a));
}

double stddevp(const std::vector<double> &a, const std::size_t lo, const std::size_t hi) {
    return std::sqrt(varp(a, lo, hi));
}

}
}
