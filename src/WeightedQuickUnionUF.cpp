#include <algs4/WeightedQuickUnionUF.h>
#include <vector>
#include <cstdint>
#include <stdexcept>

namespace algs4 {

void WeightedQuickUnionUF::validate(const std::size_t p) const {
    auto n = m_parent.size();

    if (p < 0 || p >= n) {
        throw std::invalid_argument("index " + std::to_string(p) + " is not between 0 and " +
                                    std::to_string(n - 1));
    }
}

WeightedQuickUnionUF::WeightedQuickUnionUF(const std::size_t n) {
    m_count = n;
    m_parent.resize(n);
    m_size.resize(n);

    for (int i = 0; i < n; i++) {
        m_parent[i] = i;
        m_size[i] = 1;
    }
}

int WeightedQuickUnionUF::count() const {
    return m_count;
}

int WeightedQuickUnionUF::find(int p) const {
    validate(p);
    while (p != m_parent[p])
        p = m_parent[p];
    return p;
}

void WeightedQuickUnionUF::Union(const std::size_t p, const std::size_t q) {
    const int rootP = find(p);
    const int rootQ = find(q);
    if (rootP == rootQ) return;

    if (m_size[rootP] < m_size[rootQ]) {
        m_parent[rootP] = rootQ;
        m_size[rootQ] += m_size[rootP];
    } else {
        m_parent[rootQ] = rootP;
        m_size[rootP] += m_size[rootQ];
    }
    m_count--;
}

bool WeightedQuickUnionUF::connected(const std::size_t p, const std::size_t q) const {
    return find(p) == find(q);
}

}
