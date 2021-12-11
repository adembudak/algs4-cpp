#include <algs4/Interval1D.h>

#include <string>
#include <utility> // std::hash

namespace algs4 {

Interval1D::Interval1D(const double min, const double max) : m_min(min), m_max(max) {
}

[[deprecated]] double Interval1D::left() const {
    return m_min;
}

[[deprecated]] double Interval1D::right() const {
    return m_max;
}

double Interval1D::min() const {
    return m_min;
}

double Interval1D::max() const {
    return m_max;
}

bool Interval1D::intersects(const Interval1D &that) const {
    if (m_max < that.min()) return false;
    if (that.max() < m_min) return false;
    return true;
}

bool Interval1D::contains(const double x) const {
    return (m_min <= x) && (x <= m_max);
}

double Interval1D::length() const {
    return m_max - m_min;
}

Interval1D::operator std::string() const {
    return "[" + std::to_string(m_min) + ", " + std::to_string(m_max) + "]";
}

bool Interval1D::operator==(const Interval1D &other) const {
    if (other == *this) return true;
    return m_min == other.min() && m_max == other.max();
}

int Interval1D::hashCode() const {
    int hash1 = std::hash<double>{}(m_min);
    int hash2 = std::hash<double>{}(m_max);
    return 31 * hash1 + hash2;
}

bool MinEndpointComparator(const Interval1D &a, const Interval1D &b) {
    if (a.min() < b.min()) return true;
    else if (a.min() > b.min()) return false;
    else if (a.max() < b.max()) return true;
    else if (a.max() > b.max()) return false;
    else return true;
}

bool MaxEndpointComparator(const Interval1D &a, const Interval1D &b) {
    if (a.max() < b.max()) return true;
    else if (a.max() > b.max()) return false;
    else if (a.min() < b.min()) return true;
    else if (a.min() > b.min()) return false;
    else return true;
}

bool LengthComparator(const Interval1D &a, const Interval1D &b) {
    const double alen = a.length();
    const double blen = b.length();

    if (alen < blen) return true;
    else if (alen > blen) return false;
    else return true;
}

}
