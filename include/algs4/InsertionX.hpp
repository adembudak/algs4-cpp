#ifndef INSERTIONX_H
#define INSERTIONX_H

#include <algs4/StdOut.h>

#include <vector>
#include <cassert>

namespace algs4 {
namespace InsertionX {

template <typename T>
void exch(std::vector<T> &a, const std::size_t i, const std::size_t j);
template <typename T>
bool isSorted(const std::vector<T> &a);

template <typename T>
void sort(std::vector<T> &a) {
    const auto n = a.size();

    int exchanges = 0;
    for (std::size_t i = n - 1; i > 0; i--) {
        if (a[i] < a[i - 1]) {
            exch(a, i, i - 1);
            exchanges++;
        }
    }
    if (exchanges == 0) return;

    for (std::size_t i = 2; i < n; i++) {
        auto v = a[i];
        std::size_t j = i;
        while (v < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = v;
    }

    assert(isSorted(a));
}

template <typename T>
void exch(std::vector<T> &a, const std::size_t i, const std::size_t j) {
    auto swap = a[i];
    a[i] = a[j];
    a[j] = swap;
}

template <typename T>
bool isSorted(const std::vector<T> &a) {
    for (std::size_t i = 1; i < a.size(); i++)
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
