#ifndef QUICK3WAY_H
#define QUICK3WAY_H

#include <algs4/StdRandom.h>
#include <algs4/StdOut.h>

#include <vector>
#include <cassert>

namespace algs4 {
namespace Quick3way {

template <typename T>
void sort(std::vector<T> &a);

template <typename T>
void sort(std::vector<T> &a, const std::size_t lo, const std::size_t hi);

template <typename T>
void exch(std::vector<T> &a, const std::size_t i, const std::size_t j);

template <typename T>
bool isSorted(const std::vector<T> &a);

template <typename T>
bool isSorted(const std::vector<T> &a, const std::size_t lo, const std::size_t hi);

template <typename T>
void show(const std::vector<T> &a);

//////////////////

template <typename T>
void sort(std::vector<T> &a) {
    StdRandom::shuffle(a);
    sort(a, 0, a.size() - 1);
    assert(isSorted(a));
}

template <typename T>
void sort(std::vector<T> &a, const std::size_t lo, const std::size_t hi) {
    if (hi <= lo) return;
    std::size_t lt = lo, gt = hi;
    auto v = a[lo];
    std::size_t i = lo + 1;
    while (i <= gt) {
        // clang-format off
        if      (a[i] < v) exch(a, lt++, i++);
        else if (a[i] > v) exch(a, i, gt--);
        else               i++;
        // clang-format on
    }

    if (int(lt - 1) >= 0) {
        sort(a, lo, lt - 1);
    }

    sort(a, gt + 1, hi);
    assert(isSorted(a, lo, hi));
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
