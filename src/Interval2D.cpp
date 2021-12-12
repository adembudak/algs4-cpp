#include <algs4/Interval2D.h>
#include <algs4/Point2D.h>

#include <string>

namespace algs4 {

Interval2D::Interval2D(const Interval1D &x, const Interval1D &y) : m_x(x), m_y(y) {
}

bool Interval2D::intersects(const Interval2D &that) {
    if (!m_x.intersects(that.m_x)) return false;
    if (!m_y.intersects(that.m_y)) return false;
    return true;
}

bool Interval2D::contains(const Point2D &p) {
    return m_x.contains(p.x()) && m_y.contains(p.y());
}

double Interval2D::area() const {
    return m_x.length() * m_y.length();
}

Interval2D::operator std::string() const {
    return std::string(m_x) + " x " + std::string(m_y);
}

bool Interval2D::operator==(const Interval2D &other) const {
    if (other == *this) return true;
    return m_x == other.m_x && m_y == other.m_y;
}

int Interval2D::hashCode() const {
    const int hash1 = m_x.hashCode();
    const int hash2 = m_y.hashCode();

    return 31 * hash1 + hash2;
}

void Interval2D::draw() const {
    // TODO: implement this
}

}
