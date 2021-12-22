#ifndef MERGE_H
#define MERGE_H

#include <algs4/StdOut.h>
#include <cassert>
#include <vector>

namespace algs4 {
namespace Merge {

template <typename T>
bool isSorted(const std::vector<T> &a, const std::size_t lo, const std::size_t hi);
template <typename T> bool isSorted(const std::vector<T> &a);

template <typename T>
void merge(std::vector<T> &a, std::vector<T> &aux, const std::size_t lo, const std::size_t mid,
           const std::size_t hi) {
    assert(isSorted(a, lo, mid));
    assert(isSorted(a, mid + 1, hi));

    for (std::size_t k = lo; k <= hi; k++) {
        aux[k] = a[k];
    }

    std::size_t i = lo, j = mid + 1;
    for (std::size_t k = lo; k <= hi; k++) {
        // clang-format off
        if      (i > mid)         a[k] = aux[j++];
        else if (j > hi)          a[k] = aux[i++];
        else if (aux[j] < aux[i]) a[k] = aux[j++];
        else                      a[k] = aux[i++];
        // clang-format on
    }
    assert(isSorted(a, lo, hi));
}

template <typename T>
void sort(std::vector<T> &a, std::vector<T> &aux, const std::size_t lo, const std::size_t hi) {
    if (hi <= lo) return;
    const std::size_t mid = lo + (hi - lo) / 2;
    sort(a, aux, lo, mid);
    sort(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
}

template <typename T> void sort(std::vector<T> &a) {
    std::vector<T> aux(a.size());
    sort(a, aux, 0, a.size() - 1);
    assert(isSorted(a));
}

template <typename T>
bool isSorted(const std::vector<T> &a, const std::size_t lo, const std::size_t hi) {
    for (std::size_t i = lo + 1; i <= hi; i++) // why [lo, hi] and not [lo, hi) ?
        if (a[i] < a[i - 1]) return false;
    return true;
}

template <typename T> bool isSorted(const std::vector<T> &a) {
    return isSorted(a, 0, a.size() - 1);
}

template <typename T>
void merge(std::vector<T> &a, std::vector<int> &index, std::vector<int> &aux, const std::size_t lo,
           const std::size_t mid, const std::size_t hi) {

    for (std::size_t k = lo; k <= hi; k++) {
        aux[k] = index[k];
    }

    std::size_t i = lo, j = mid + 1;
    for (std::size_t k = lo; k <= hi; k++) {
        // clang-format off
        if      (i > mid)               index[k] = aux[j++];
        else if (j > hi)                index[k] = aux[i++];
        else if (a[aux[j]] < a[aux[i]]) index[k] = aux[j++];
        else                            index[k] = aux[i++];
        // clang-format on
    }
}

template <typename T>
void sort(std::vector<T> &a, std::vector<int> &index, std::vector<int> &aux, std::size_t lo,
          std::size_t hi) {
    if (hi <= lo) return;
    const std::size_t mid = lo + (hi - lo) / 2;
    sort(a, index, aux, lo, mid);
    sort(a, index, aux, mid + 1, hi);
    merge(a, index, aux, lo, mid, hi);
}

template <typename T> std::vector<int> indexSort(std::vector<T> &a) {
    const auto n = a.size();
    std::vector<int> index(n);
    for (std::size_t i = 0; i < n; i++)
        index[i] = i;

    std::vector<int> aux(n);
    sort(a, index, aux, 0, n - 1);
    return index;
}

template <typename T> void show(const std::vector<T> &a) {
    for (std::size_t i = 0; i < a.size(); i++) {
        StdOut::println(a[i]);
    }
}

}
}

#endif
