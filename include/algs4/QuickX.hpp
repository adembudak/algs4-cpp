#ifndef QUICKX_H
#define QUICKX_H

#include <algs4/Insertion.hpp>

#include <cstdint>
#include <vector>
#include <cassert>

namespace algs4 {
namespace QuickX {

static constexpr std::size_t INSERTION_SORT_CUTOFF = 8;

template <typename T>
void sort(std::vector<T> &a, const std::size_t lo, const std::size_t hi);

template <typename T>
std::size_t partition(std::vector<T> &a, const std::size_t lo, const std::size_t hi);

template <typename T>
std::size_t median3(std::vector<T> &a, const std::size_t i, const std::size_t j,
                    const std::size_t k);

template <typename T>
void exch(std::vector<T> &a, const std::size_t i, const std::size_t j);

template <typename T>
bool isSorted(const std::vector<T> &a, const std::size_t lo, const std::size_t hi);

template <typename T>
bool isSorted(const std::vector<T> &a);

template <typename T>
void show(const std::vector<T> &a);

////////////////////////////////

template <typename T>
void sort(std::vector<T> &a) {
    sort(a, std::size_t{0}, a.size() - std::size_t{1});
    assert(isSorted(a));
}

template <typename T>
void sort(std::vector<T> &a, const std::size_t lo, const std::size_t hi) {
    if (hi <= lo) return;

    std::size_t n = hi - lo + 1;
    if (n <= INSERTION_SORT_CUTOFF) {
        Insertion::sort(a, lo, hi + 1);
    }

    std::size_t j = partition(a, lo, hi);
    sort(a, lo, j - 1);
    sort(a, j + 1, hi);
}

template <typename T>
std::size_t partition(std::vector<T> &a, const std::size_t lo, const std::size_t hi) {
    std::size_t n = hi - lo + 1;
    std::size_t m = median3(a, lo, lo + n / 2, hi);
    exch(a, m, lo);

    std::size_t i = lo;
    std::size_t j = hi + 1;

    while (a[++i] < a[lo]) {
        if (i == hi) {
            exch(a, lo, hi);
            return hi;
        }
    }

    while (a[lo] < a[--j]) {
        if (j == lo + 1) return lo;
    }

    while (i < j) {
        exch(a, i, j);

        while (a[++i] < a[lo])
            ;

        while (a[lo] < a[--j])
            ;
    }

    exch(a, lo, j);

    return j;
}

template <typename T>
std::size_t median3(std::vector<T> &a, const std::size_t i, const std::size_t j,
                    const std::size_t k) {
    // clang-format off
    return (a[i] < a[j] ? 
           (a[j] < a[k] ? j : a[i] < a[k] ? k : i) : 
           (a[k] < a[j] ? j : a[k] < a[i] ? k : i));
    // clang-format on
}

template <typename T>
void exch(std::vector<T> &a, const std::size_t i, const std::size_t j) {
    T swap = a[i];
    a[i] = a[j];
    a[j] = swap;
}

template <typename T>
bool isSorted(const std::vector<T> &a, const std::size_t lo, const std::size_t hi) {
    for (std::size_t i = lo + 1; i < hi; i++)
        if (a[i] < a[i - 1]) return false;
    return true;
}

template <typename T>
bool isSorted(const std::vector<T> &a) {
    for (std::size_t i = 1; i < a.size(); i++)
        if (a[i] < a[i - 1]) return false;
    return true;
}

template <typename T>
void show(const std::vector<T> &a) {
    for (std::size_t i = 0; i < a.size(); i++)
        StdOut::println(a[i]);
}

}
}

#endif
