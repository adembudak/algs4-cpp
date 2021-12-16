#include <algs4/QuickUnionUF.h>
#include <stdexcept>

namespace algs4 {

void QuickUnionUF::validate(const std::size_t p) const {
    auto n = m_parent.size();

    if (p < 0 || p >= n) {

        throw std::invalid_argument("index " + std::to_string(p) + " is not between 0 and " +
                                    std::to_string(n - 1));
    }
}

QuickUnionUF::QuickUnionUF(const std::size_t n) {
    m_parent.resize(n);
    m_count = n;
    for (int i = 0; i < n; i++) {
        m_parent[i] = i;
    }
}

int QuickUnionUF::count() const {
    return m_count;
}

int QuickUnionUF::find(std::size_t p) const {
    validate(p);
    while (p != m_parent[p])
        p = m_parent[p];
    return p;
}

bool QuickUnionUF::connected(const std::size_t p, const std::size_t q) const {
    return find(p) == find(q);
}

void QuickUnionUF::Union(const std::size_t p, const std::size_t q) {
    int rootP = find(p);
    int rootQ = find(q);
    if (rootP == rootQ) return;
    m_parent[rootP] = rootQ;
    m_count--;
}

}
