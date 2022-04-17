#ifndef INSERTION_H
#define INSERTION_H

#include <algs4/StdOut.h>

#include <vector>
#include <cstdint>
#include <cassert>

namespace algs4 {
namespace Insertion {

template <typename T>
void sort(std::vector<T> &a);

template <typename T>
void sort(std::vector<T> &a, const std::size_t lo, const std::size_t hi);

template <typename T, class Compare>
void sort(std::vector<T> &a, Compare comp);

template <typename T, class Compare>
void sort(std::vector<T> &a, const std::size_t lo, const std::size_t hi, Compare comp);

template <typename T>
std::vector<int> indexSort(const std::vector<T> &a);

template <typename T>
void exch(std::vector<T> &a, const std::size_t i, const std::size_t j);

template <typename T>
bool isSorted(std::vector<T> &a);

template <typename T>
bool isSorted(std::vector<T> &a, const std::size_t lo, const std::size_t hi);

template <typename T, typename Comp>
bool isSorted(std::vector<T> &a, Comp comparator);

template <typename T, typename Comp>
bool isSorted(std::vector<T> &a, const std::size_t lo, const std::size_t hi, Comp comparator);

template <typename T>
void show(const std::vector<T> &a);

/////////

template <typename T>
void sort(std::vector<T> &a) {
    const auto n = a.size();
    for (std::size_t i = 1; i < n; i++) {
        for (std::size_t j = i; j > 0 && (a[j] < a[j - 1]); j--) {
            exch(a, j, j - 1);
        }
        assert(isSorted(a, 0, i));
    }
    assert(isSorted(a));
}

template <typename T>
void sort(std::vector<T> &a, const std::size_t lo, const std::size_t hi) {
    for (std::size_t i = lo + 1; i < hi; i++) {
        for (std::size_t j = i; j > lo && (a[j] < a[j - 1]); j--) {
            exch(a, j, j - 1);
        }
    }
    assert(isSorted(a, lo, hi));
}

template <typename T, class Compare>
void sort(std::vector<T> &a, Compare comp) {
    const auto n = a.size();
    for (std::size_t i = 1; i < n; i++) {
        for (std::size_t j = i; j > 0 && comp(a[j], a[j - 1]); j--) {
            exch(a, j, j - 1);
        }
        assert(isSorted(a, 0, i));
    }
    assert(isSorted(a));
}

template <typename T, class Compare>
void sort(std::vector<T> &a, const std::size_t lo, const std::size_t hi, Compare comp) {
    for (std::size_t i = lo + 1; i < hi; i++) {
        for (std::size_t j = i; j > lo && comp(a[j], a[j - 1]); j--) {
            exch(a, j, j - 1);
        }
    }
    assert(isSorted(a, lo, hi, comp));
}

template <typename T>
std::vector<int> indexSort(const std::vector<T> &a) {
    const auto n = a.size();
    std::vector<int> index(n);
    for (std::size_t i = 0; i < n; i++)
        index[i] = i;

    for (std::size_t i = 1; i < n; i++)
        for (int j = i; j > 0 && (a[index[j]] < a[index[j - 1]]); j--)
            exch(index, j, j - 1);

    return index;
}

template <typename T>
void exch(std::vector<T> &a, const std::size_t i, const std::size_t j) {
    auto swap = a[i];
    a[i] = a[j];
    a[j] = swap;
}

template <typename T>
bool isSorted(std::vector<T> &a) {
    return isSorted(a, 0, a.size());
}

template <typename T>
bool isSorted(std::vector<T> &a, const std::size_t lo, const std::size_t hi) {
    for (std::size_t i = lo + 1; i < hi; i++)
        if (a[i] < a[i - 1]) return false;
    return true;
}

template <typename T, typename Comp>
bool isSorted(std::vector<T> &a, Comp comparator) {
    return isSorted(a, 0, a.size(), comparator);
}

template <typename T, typename Comp>
bool isSorted(std::vector<T> &a, const std::size_t lo, const std::size_t hi, Comp comparator) {
    for (std::size_t i = lo + 1; i < hi; i++)
        if (comparator(a[i], a[i - 1])) return false;
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
