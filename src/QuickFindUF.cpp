#include <algs4/QuickFindUF.h>
#include <stdexcept>
#include <cstdint>

namespace algs4 {

void QuickFindUF::validate(const std::size_t p) {
    std::size_t n = id.size();
    if (p < 0 || p >= n) {
        throw std::invalid_argument("index " + std::to_string(p) + " is not between 0 and " +
                                    std::to_string(n - 1));
    };
}

QuickFindUF::QuickFindUF(const std::size_t n) {
    m_count = n;
    id.resize(n);
    for (std::size_t i = 0; i < n; i++)
        id[i] = i;
}

int QuickFindUF::count() const {
    return m_count;
}

int QuickFindUF::find(const std::size_t p) {
    validate(p);
    return id[p];
}

bool QuickFindUF::connected(const std::size_t p, const std::size_t q) {
    validate(p);
    validate(q);
    return id[p] == id[q];
}

void QuickFindUF::Union(const std::size_t p, const std::size_t q) {
    validate(p);
    validate(q);

    int pID = id[p];
    int qID = id[q];

    if (pID == qID) return;

    for (int i = 0; i < id.size(); i++)
        if (id[i] == pID) id[i] = qID;
    m_count--;
}

}
