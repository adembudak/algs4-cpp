#ifndef BINARYINSERTION_H
#define BINARYINSERTION_H

#include <algs4/StdOut.h>
#include <vector>
#include <cstdint>
#include <cassert>

namespace algs4 {
namespace BinaryInsertion {

template <typename T>
bool isSorted(const std::vector<T> &a);

template <typename T>
void sort(std::vector<T> &a) {
    const auto n = a.size();

    for (std::size_t i = 1; i < n; i++) {
        const auto v = a[i];
        std::size_t lo = 0, hi = i;

        while (lo < hi) {
            const std::size_t mid = lo + (hi - lo) / 2;
            if (v < a[mid]) hi = mid;
            else lo = mid + 1;
        }

        for (std::size_t j = i; j > lo; j--)
            a[j] = a[j - 1];
        a[lo] = v;
    }
    assert(isSorted(a));
}

template <typename T>
bool isSorted(const std::vector<T> &a, const std::size_t lo, const std::size_t hi) {
    for (std::size_t i = lo + 1; i < hi; i++)
        if (a[i] < a[i - 1]) return false;
    return true;
}

template <typename T>
bool isSorted(const std::vector<T> &a) {
    return isSorted(a, 0, a.size());
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
