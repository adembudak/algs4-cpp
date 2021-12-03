#include "algs4/StdStats.h"

#include <vector>
#include <limits>
#include <cmath>

namespace algs4 {

namespace StdStats {

double max(const std::vector<double> &a) {
    double max = negative_double_INF;

    for (int i = 0; i < a.size(); i++) {
        if (std::isnan(a[i])) return double_NaN;
        if (a[i] > max) max = a[i];
    }
    return max;
}

// find maximum value in subarray [lo, hi) of a
double max(const std::vector<double> &a, const int lo, const int hi) {
    double max = negative_double_INF;

    for (int i = lo; i < hi; i++) {
        if (std::isnan(a[i])) return double_NaN;
        if (a[i] > max) max = a[i];
    }
    return max;
}

int max(const std::vector<int> &a) {
    int max = int_MIN;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

double min(const std::vector<double> &a) {
    double min = double_INF;

    for (int i = 0; i < a.size(); i++) {
        if (std::isnan(a[i])) return double_NaN;
        if (a[i] < min) min = a[i];
    }
    return min;
}

double min(const std::vector<double> &a, const int lo, const int hi) {
    double min = double_INF;

    for (int i = lo; i < hi; i++) {
        if (std::isnan(a[i])) return double_NaN;
        if (a[i] < min) min = a[i];
    }
    return min;
}

int min(const std::vector<int> &a) {
    int min = int_MAX;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] < min) min = a[i];
    }
    return min;
}

double sum(const std::vector<double> &a) {
    double sum = 0.0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
    }
    return sum;
}

int sum(const std::vector<int> &a) {
    int sum = 0.0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
    }
    return sum;
}

double sum(const std::vector<double> &a, const int lo, const int hi) {
    double sum_ = 0.0;
    for (int i = lo; i < hi; i++) {
        sum_ += a[i];
    }
    return sum_;
}

double mean(const std::vector<double> &a) {

    if (a.empty()) return double_NaN;
    const double sum_ = sum(a);
    return sum_ / a.size();
}

double mean(const std::vector<double> &a, const int lo, const int hi) {

    const int length = hi - lo;
    if (length == 0) return double_NaN;

    double sum_ = sum(a, lo, hi);
    return sum_ / length;
}

double mean(const std::vector<int> &a) {

    if (a.empty()) return double_NaN;
    const int sum_ = sum(a);
    return sum_ / a.size();
}

double var(const std::vector<double> &a) {

    if (a.empty()) return double_NaN;

    const double avg = mean(a);
    double sum = 0.0;

    for (int i = 0; i < a.size(); i++) {
        sum += (a[i] - avg) * (a[i] - avg);
    }
    return sum / (a.size() - 1);
}

double var(const std::vector<double> &a, const int lo, const int hi) {
    const int length = hi - lo;
    if (length == 0) return double_NaN;

    double avg = mean(a, lo, hi);
    double sum = 0.0;

    for (int i = lo; i < hi; i++) {
        sum += (a[i] - avg) * (a[i] - avg);
    }
    return sum / (length - 1);
}

double var(const std::vector<int> &a) {

    if (a.empty()) return double_NaN;

    const double avg = mean(a);
    double sum = 0.0;

    for (int i = 0; i < a.size(); i++) {
        sum += (a[i] - avg) * (a[i] - avg);
    }
    return sum / (a.size() - 1);
}

double varp(const std::vector<double> &a) {

    if (a.empty()) return double_NaN;

    const double avg = mean(a);
    double sum = 0.0;

    for (int i = 0; i < a.size(); i++) {
        sum += (a[i] - avg) * (a[i] - avg);
    }
    return sum / a.size();
}

double varp(const std::vector<double> &a, const int lo, const int hi) {

    const int length = hi - lo;
    if (length == 0) return double_NaN;

    const double avg = mean(a, lo, hi);
    double sum = 0.0;

    for (int i = lo; i < hi; i++) {
        sum += (a[i] - avg) * (a[i] - avg);
    }
    return sum / a.size();
}

double stddev(const std::vector<double> &a) {
    return std::sqrt(var(a));
}

double stddev(const std::vector<int> &a) {
    return std::sqrt(var(a));
}

double stddev(const std::vector<double> &a, const int lo, const int hi) {
    return std::sqrt(var(a, lo, hi));
}

double stddevp(const std::vector<double> &a) {
    return std::sqrt(varp(a));
}

double stddevp(const std::vector<double> &a, const int lo, const int hi) {
    return std::sqrt(varp(a, lo, hi));
}

}
}
