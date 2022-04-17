#ifndef QUICK_H
#define QUICK_H

#include <algs4/StdOut.h>
#include <algs4/StdRandom.h>

#include <vector>
#include <cstdint>
#include <string>
#include <cassert>
#include <stdexcept>

namespace algs4 {
namespace Quick {

template <typename T>
void sort(std::vector<T> &a);

template <typename T>
void sort(std::vector<T> &a, const std::size_t lo, const std::size_t hi);

template <typename T>
std::size_t partition(std::vector<T> &a, const std::size_t lo, const std::size_t hi);

template <typename T>
T select(std::vector<T> &a, const std::size_t k);

template <typename T>
void exch(std::vector<T> &a, const std::size_t i, const std::size_t j);

template <typename T>
bool isSorted(const std::vector<T> &a, const std::size_t lo, const std::size_t hi);

template <typename T>
bool isSorted(const std::vector<T> &a);

template <typename T>
void show(const std::vector<T> &a);

//////////////////////

template <typename T>
void sort(std::vector<T> &a) {
    StdRandom::shuffle(a);
    sort(a, 0, a.size() - 1);
    assert(isSorted(a));
}

template <typename T>
void sort(std::vector<T> &a, const std::size_t lo, const std::size_t hi) {
    if (hi <= lo) return;
    const std::size_t j = partition(a, lo, hi);

    if (int(j - 1) >= 0) { // should i use ssize_t instead?
        sort(a, lo, j - 1);
    }

    sort(a, j + 1, hi);
    assert(isSorted(a, lo, hi));
}

template <typename T>
std::size_t partition(std::vector<T> &a, const std::size_t lo, const std::size_t hi) {
    std::size_t i = lo;
    std::size_t j = hi + 1;

    while (true) {

        while (a[++i] < a[lo]) {
            if (i == hi) break;
        }

        while (a[lo] < a[--j]) {
            if (j == lo) break;
        }

        if (i >= j) break;

        exch(a, i, j);
    }
    exch(a, lo, j);

    return j;
}

template <typename T>
T select(std::vector<T> &a, const std::size_t k) {
    if (k < 0 || k >= a.size()) {
        throw std::invalid_argument(std::string("index is not between 0 and ")
                                        .append(std::to_string(a.size()))
                                        .append(": ")
                                        .append(std::to_string(k)));
    }

    StdRandom::shuffle(a);
    std::size_t lo = 0, hi = a.size() - 1;
    while (hi > lo) {
        auto i = partition(a, lo, hi);
        if (i > k) hi = i - 1;
        else if (i < k) lo = i + 1;
        else return a[i];
    }
    return a[lo];
}

template <typename T>
void exch(std::vector<T> &a, const std::size_t i, const std::size_t j) {
    auto swap = a[i];
    a[i] = a[j];
    a[j] = swap;
}

template <typename T>
bool isSorted(const std::vector<T> &a) {
    return isSorted(a, 0, a.size() - 1);
}

template <typename T>
bool isSorted(const std::vector<T> &a, const std::size_t lo, const std::size_t hi) {
    for (std::size_t i = lo + 1; i <= hi; i++)
        if (a[i] < a[i - 1]) return false;
    return true;
}

template <typename T>
void show(const std::vector<T> &a) {
    for (std::size_t i = 0; i < a.size(); i++) {
        StdOut::println(a[i]);
    }
}

}
}

#endif
