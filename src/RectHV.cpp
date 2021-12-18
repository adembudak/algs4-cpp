#include <algs4/RectHV.h>
#include <algs4/Point2D.h>

#include <string>
#include <cmath>
#include <stdexcept>
#include <cassert>

namespace algs4 {

RectHV::RectHV(const double xmin, const double ymin, const double xmax, const double ymax)
    : m_xmin(xmin), m_ymin(ymin), m_xmax(xmax), m_ymax(ymax) {

    if (std::isnan(xmin) || std::isnan(xmax)) {
        throw std::invalid_argument("x-coordinate is NaN: " + std::string(*this));
    }
    if (std::isnan(ymin) || std::isnan(ymax)) {
        throw std::invalid_argument("y-coordinate is NaN: " + std::string(*this));
    }
    if (xmax < xmin) {
        throw std::invalid_argument("xmax < xmin: " + std::string(*this));
    }
    if (ymax < ymin) {
        throw std::invalid_argument("ymax < ymin: " + std::string(*this));
    }
}

double RectHV::xmin() const {
    return m_xmin;
}

double RectHV::xmax() const {
    return m_xmax;
}

double RectHV::ymin() const {
    return m_ymin;
}

double RectHV::ymax() const {
    return m_ymax;
}

double RectHV::width() const {
    return m_xmax - m_xmin;
}

double RectHV::height() const {
    return m_ymax - m_ymin;
}

bool RectHV::intersects(const RectHV &that) const {
    return m_xmax >= that.m_xmin && m_ymax >= that.m_ymin && that.m_xmax >= m_xmin &&
           that.m_ymax >= m_ymin;
}

bool RectHV::contains(const Point2D &p) const {
    return (p.x() >= m_xmin) && (p.x() <= m_xmax) && (p.y() >= m_ymin) && (p.y() <= m_ymax);
}

double RectHV::distanceTo(const Point2D &p) const {
    return std::sqrt(distanceSquaredTo(p));
}

double RectHV::distanceSquaredTo(const Point2D &p) const {
    double dx = 0.0, dy = 0.0;
    // clang-format off
    if      (p.x() < m_xmin) dx = p.x() - m_xmin;
    else if (p.x() > m_xmax) dx = p.x() - m_xmax;
    if      (p.y() < m_ymin) dy = p.y() - m_ymin;
    else if (p.y() > m_ymax) dy = p.y() - m_ymax;
    return dx*dx + dy*dy;
    // clang-format on
}

bool RectHV::operator==(const RectHV &other) const {
    if (*this == other) return true;
    if (m_xmin != other.xmin()) return false;
    if (m_ymin != other.ymin()) return false;
    if (m_xmax != other.xmax()) return false;
    if (m_ymax != other.ymax()) return false;
    return true;
}

int RectHV::hashCode() const {
    const int hash1 = std::hash<double>{}(m_xmin);
    const int hash2 = std::hash<double>{}(m_ymin);
    const int hash3 = std::hash<double>{}(m_xmax);
    const int hash4 = std::hash<double>{}(m_ymax);
    return 31 * (31 * (31 * hash1 + hash2) + hash3) + hash4;
}

RectHV::operator std::string() const {
    return "[" + std::to_string(m_xmin) + ", " + std::to_string(m_xmax) + "] x [" +
           std::to_string(m_ymin) + ", " + std::to_string(m_ymax) + "]";
}

void RectHV::draw() const {
    assert(false && "StdDraw not implemented yet");
}

}
