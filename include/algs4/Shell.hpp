#ifndef SHELL_H
#define SHELL_H

#include <algs4/StdOut.h>

#include <vector>
#include <cstdint>
#include <cassert>

namespace algs4 {
namespace Shell {

template <typename T> void exch(std::vector<T> &a, const std::size_t i, const std::size_t j);
template <typename T> bool isSorted(const std::vector<T> &a);
template <typename T> bool isHsorted(const std::vector<T> &a, const std::size_t h);

template <typename T> void sort(std::vector<T> &a) {
    const auto n = a.size();

    std::size_t h = 1;
    while (h < (n / 3)) // 3x+1 increment sequence:  1, 4, 13, 40, 121, 364, 1093, ...
        h = 3 * h + 1;

    while (h >= 1) {
        for (std::size_t i = h; i < n; i++) {
            for (std::size_t j = i; j >= h && (a[j] < a[j - h]); j -= h) {
                exch(a, j, j - h);
            }
        }
        assert(isHsorted(a, h));
        h /= 3;
    }

    assert(isSorted(a));
}

template <typename T> void exch(std::vector<T> &a, const std::size_t i, const std::size_t j) {
    auto swap = a[i];
    a[i] = a[j];
    a[j] = swap;
}

template <typename T> bool isSorted(const std::vector<T> &a) {
    for (std::size_t i = 1; i < a.size(); i++)
        if (a[i] < a[i - 1]) return false;
    return true;
}

template <typename T> bool isHsorted(const std::vector<T> &a, const std::size_t h) {
    for (std::size_t i = h; i < a.size(); i++)
        if (a[i] < a[i - h]) return false;
    return true;
}

template <typename T> void show(const std::vector<T> &a) {
    for (std::size_t i = 0; i < a.size(); i++) {
        StdOut::println(a[i]);
    }
}

}
}

#endif
