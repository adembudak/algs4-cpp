#ifndef SELECTION_H
#define SELECTION_H

#include <algs4/StdOut.h>
#include <vector>
#include <cstdint>
#include <cassert>

namespace algs4 {
namespace Selection {

// clang-format off
template <typename T> void exch(std::vector<T> &a, const std::size_t i, const std::size_t j);
template <typename T> bool isSorted(const std::vector<T> &a, const std::size_t lo, const std::size_t hi);
template <typename T> bool isSorted(const std::vector<T> &a);

template <typename T, class Compare> bool isSorted(const std::vector<T> &a, Compare comp, const std::size_t lo, const std::size_t hi);
template <typename T, class Compare> bool isSorted(const std::vector<T> &a, Compare comp);
// clang-format on

template <typename T> void sort(std::vector<T> &a) {
    const auto n = a.size();
    for (std::size_t i = 0; i < n; i++) {
        std::size_t min = i;
        for (std::size_t j = i + 1; j < n; j++) {
            if (a[j] < a[min]) min = j;
        }
        exch(a, i, min);
        assert(isSorted(a, 0, i));
    }
    assert(isSorted(a));
}

template <typename T, class Compare> void sort(std::vector<T> &a, Compare comp) {
    const auto n = a.size();
    for (std::size_t i = 0; i < n; i++) {
        std::size_t min = i;
        for (std::size_t j = i + 1; j < n; j++) {
            if (comp(a[j], a[min])) min = j;
        }
        exch(a, i, min);
        assert(isSorted(a, comp, 0, i));
    }
    assert(isSorted(a, comp));
}

template <typename T> void exch(std::vector<T> &a, const std::size_t i, const std::size_t j) {
    auto swap = a[i];
    a[i] = a[j];
    a[j] = swap;
}

template <typename T>
bool isSorted(const std::vector<T> &a, const std::size_t lo, const std::size_t hi) {
    for (std::size_t i = lo + 1; i < hi; i++)
        if (a[i] < a[i - 1]) return false;
    return true;
}

template <typename T> bool isSorted(const std::vector<T> &a) {
    return isSorted(a, 0, a.size());
}

template <typename T, class Compare>
bool isSorted(const std::vector<T> &a, Compare comp, const std::size_t lo, const std::size_t hi) {
    for (std::size_t i = lo + 1; i < hi; i++)
        if (comp(a[i], a[i - 1])) return false;
    return true;
}

template <typename T, class Compare> bool isSorted(const std::vector<T> &a, Compare comp) {
    return isSorted(a, comp, 0, a.size());
}

template <typename T> void show(const std::vector<T> &a) {
    for (std::size_t i = 0; i < a.size(); i++) {
        StdOut::println(a[i]);
    }
}

}
}

#endif
