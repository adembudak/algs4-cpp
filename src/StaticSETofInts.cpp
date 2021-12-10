#include <algs4/StaticSETofInts.h>
#include <algorithm> // for std::sort
#include <cstdint>   //for std::size_t
#include <stdexcept>

namespace algs4 {

StaticSETofInts::StaticSETofInts(const std::vector<int> &a) : m_a(a) {
    std::sort(begin(m_a), end(m_a));

    for (std::size_t i = 1; i < m_a.size(); i++) {
        if (m_a[i] == m_a[i - 1]) {
            throw std::invalid_argument("Argument arrays contains duplicate keys.");
        }
    }
}

bool StaticSETofInts::contains(const int key) const {
    return rank(key) != -1;
}

int StaticSETofInts::rank(const int key) const {
    std::size_t lo = 0;
    std::size_t hi = m_a.size() - 1;

    while (lo <= hi) {
        std::size_t mid = lo + (hi - lo) / 2;
        if (key < m_a[mid]) hi = mid - 1;
        else if (key > m_a[mid]) lo = mid + 1;
        else return mid;
    }
    return -1;
}

}
