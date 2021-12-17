#include <algs4/UF.h>
#include <vector>
#include <cstdint>
#include <stdexcept>

namespace algs4 {

void UF::validate(const std::size_t p) const {
    auto n = m_parent.size();

    if (p < 0 || p >= n) {
        throw std::invalid_argument("index " + std::to_string(p) + " is not between 0 and " +
                                    std::to_string(n - 1));
    }
}

UF::UF(const std::size_t n) {
    if (n < 0) throw std::invalid_argument("Vertex numbers can't be negative");
    m_count = n;
    m_parent.resize(n);
    m_rank.resize(n);

    for (int i = 0; i < n; i++) {
        m_parent[i] = i;
        m_rank[i] = 0;
    }
}

std::size_t UF::find(std::size_t p) {
    validate(p);

    while (p != m_parent[p]) {
        m_parent[p] = m_parent[m_parent[p]];
        p = m_parent[p];
    }
    return p;
}

std::size_t UF::count() const {
    return m_count;
}

void UF::Union(const std::size_t p, const std::size_t q) {
    int rootP = find(p);
    int rootQ = find(q);
    if (rootP == rootQ) return;

    if (m_rank[rootP] < m_rank[rootQ]) m_parent[rootP] = rootQ;
    else if (m_rank[rootP] > m_rank[rootQ]) m_parent[rootQ] = rootP;
    else {
        m_parent[rootQ] = rootP;
        m_rank[rootP]++;
    }
    m_count--;
}

bool UF::connected(const std::size_t p, const std::size_t q) {
    return find(p) == find(q);
}

}
