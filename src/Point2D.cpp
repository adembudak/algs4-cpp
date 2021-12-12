#include <algs4/Point2D.h>

#include <cmath>
#include <stdexcept>
#include <utility>

namespace algs4 {

Point2D::Point2D(const double x, const double y) {
    if (std::isinf(x) || std::isinf(y)) {
        throw std::invalid_argument("Coordinates must be finite");
    }

    if (std::isnan(x) || std::isnan(y)) {
        throw std::invalid_argument("Coordinates cannot be NaN");
    }

    if (x == 0.0) m_x = 0.0;
    else m_x = x;

    if (y == 0.0) m_y = 0.0;
    else m_y = y;
}

double Point2D::x() const {
    return m_x;
}

double Point2D::y() const {
    return m_y;
}

double Point2D::r() const {
    return std::sqrt(m_x * m_x + m_y * m_y);
}

double Point2D::theta() const {
    return std::atan2(m_y, m_x);
}

double Point2D::angleTo(const Point2D &that) const {
    const double dx = that.x() - m_x;
    const double dy = that.y() - m_y;
    return std::atan2(dy, dx);
}

double Point2D::distanceTo(const Point2D &that) const {
    const double dx = m_x - that.x();
    const double dy = m_y - that.y();
    return std::sqrt(dx * dx + dy * dy);
}

double Point2D::distanceSquaredTo(const Point2D &that) const {
    const double dx = m_x - that.x();
    const double dy = m_y - that.y();
    return dx * dx + dy * dy;
}

int Point2D::operator<(const Point2D &that) const {
    if (m_y < that.y()) return -1;
    if (m_y > that.y()) return +1;
    if (m_x < that.x()) return -1;
    if (m_x > that.x()) return +1;
    return 0;
}

bool Point2D::operator==(const Point2D &other) const {
    if (other == *this) return true;
    return m_x == other.x() && m_y == other.y();
}

Point2D::operator std::string() const {
    return "(" + std::to_string(m_x) + ", " + std::to_string(m_y) + ")";
}

int Point2D::hashCode() const {
    const int hashX = std::hash<double>{}(m_x);
    const int hashY = std::hash<double>{}(m_y);
    return 31 * hashX + hashY;
}

void Point2D::draw() const {
    // TODO: implement this
}

void Point2D::drawTo() const {
    // TODO: implement this
}

int ccw(const Point2D &a, const Point2D &b, const Point2D &c) {
    const double area2 = (b.x() - a.x()) * (c.y() - a.y()) - (b.y() - a.y()) * (c.x() - a.x());

    if (area2 < 0) return -1;
    else if (area2 > 0) return +1;
    else return 0;
}

double area2(const Point2D &a, const Point2D &b, const Point2D &c) {
    const double area2 = (b.x() - a.x()) * (c.y() - a.y()) - (b.y() - a.y()) * (c.x() - a.x());

    if (area2 < 0) return -1;
    else if (area2 > 0) return +1;
    else return 0;
}

bool XOrder(const Point2D &p, const Point2D &q) {
    if (p.x() < q.x()) return -1;
    if (p.x() > q.x()) return +1;
    return 0;
}

bool YOrder(const Point2D &p, const Point2D &q) {
    if (p.y() < q.y()) return -1;
    if (p.y() > q.y()) return +1;
    return 0;
}

bool ROrder(const Point2D &p, const Point2D &q) {
    double delta = (p.x() * p.x() + p.y() * p.y()) - (q.x() * q.x() + q.y() * q.y());
    if (delta < 0) return -1;
    if (delta > 0) return +1;
    return 0;
}

bool Point2D::Atan2Order(const Point2D &q1, const Point2D &q2) {
    double angle1 = angleTo(q1);
    double angle2 = angleTo(q2);
    if (angle1 < angle2) return -1;
    else if (angle1 > angle2) return +1;
    else return 0;
}

bool Point2D::PolarOrder(const Point2D &q1, const Point2D &q2) {
    const double dx1 = q1.x() - m_x;
    const double dy1 = q1.y() - m_y;
    const double dx2 = q2.x() - m_x;
    const double dy2 = q2.y() - m_y;

    if (dy1 >= 0 && dy2 < 0) return -1;      // q1 above; q2 below
    else if (dy2 >= 0 && dy1 < 0) return +1; // q1 below; q2 above
    else if (dy1 == 0 && dy2 == 0) {         // 3-collinear and horizontal
        if (dx1 >= 0 && dx2 < 0) return -1;
        else if (dx2 >= 0 && dx1 < 0) return +1;
        else return 0;
    } else return -ccw(*this, q1, q2); // both above or below
}

bool Point2D::DistanceToOrder(const Point2D &p, const Point2D &q) {
    const double dist1 = distanceSquaredTo(p);
    const double dist2 = distanceSquaredTo(q);

    if (dist1 < dist2) return -1;
    else if (dist1 > dist2) return +1;
    else return 0;
}

}
