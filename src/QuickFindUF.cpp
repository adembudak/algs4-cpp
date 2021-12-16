#include <algs4/QuickFindUF.h>
#include <stdexcept>

namespace algs4 {

void QuickFindUF::validate(const int p) {
    int n = id.capacity();
    if (p < 0 || p >= n) {
        throw std::invalid_argument("index " + std::to_string(p) + " is not between 0 and " +
                                    std::to_string(n - 1));
    };
}

QuickFindUF::QuickFindUF(const int n) {
    m_count = n;
    id.reserve(n);
    for (int i = 0; i < n; i++)
        id[i] = i;
}

int QuickFindUF::count() const {
    return m_count;
}

int QuickFindUF::find(const int p) {
    validate(p);
    return id[p];
}

bool QuickFindUF::connected(const int p, const int q) {
    validate(p);
    validate(q);
    return id[p] == id[q];
}

void QuickFindUF::Union(const int p, const int q) {
    validate(p);
    validate(q);

    int pID = id[p];
    int qID = id[q];

    if (pID == qID) return;

    for (int i = 0; i < id.capacity(); i++)
        if (id[i] == pID) id[i] = qID;
    m_count--;
}

}
