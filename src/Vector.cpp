#include <algs4/Vector.h>

#include <initializer_list>
#include <string>
#include <sstream> // for operator std::string
#include <cstdint>
#include <cmath>
#include <stdexcept>

namespace algs4 {

Vector::Vector(const std::size_t d) {
    this->m_d = d;
    m_data.resize(d);
}

Vector::Vector(const std::initializer_list<double> &a) {
    m_d = a.size();
    m_data.assign(a.begin(), a.end());
}

int Vector::dimension() const {
    return m_d;
}

double Vector::dot(const Vector &that) const {
    if (m_d != that.dimension()) throw std::invalid_argument("Dimensions don't agree");

    double sum = 0.0;
    for (std::size_t i = 0; i < m_d; i++)
        sum = sum + (m_data[i] * that.m_data[i]);

    return sum;
}

double Vector::magnitude() const {
    return std::sqrt(dot(*this));
}

double Vector::distanceTo(const Vector &that) const {
    if (m_d != that.dimension()) throw std::invalid_argument("Dimensions don't agree");

    return (*this - that).magnitude();
}

double Vector::cartesian(std::size_t i) const {
    return m_data[i];
}

Vector Vector::scale(const double alpha) const {
    Vector c(m_d);
    for (int i = 0; i < m_d; i++)
        c.m_data[i] = alpha * m_data[i];
    return c;
}

Vector Vector::direction() const {
    if (magnitude() == 0.0) throw std::domain_error("Zero-vector has no direction");
    return scale(1.0 / magnitude());
}

Vector Vector::operator+(const Vector &that) const {
    if (m_d != that.dimension()) throw std::invalid_argument("Dimensions don't agree");
    Vector c(m_d);
    for (std::size_t i = 0; i < m_d; i++)
        c.m_data[i] = m_data[i] + that.m_data[i];

    return c;
}

Vector Vector::operator-(const Vector &that) const {
    if (m_d != that.dimension()) throw std::invalid_argument("Dimensions don't agree");
    Vector c(m_d);
    for (std::size_t i = 0; i < m_d; i++)
        c.m_data[i] = m_data[i] - that.m_data[i];

    return c;
}

Vector::operator std::string() const {
    std::ostringstream s;
    for (int i = 0; i < m_d; i++)
        s << m_data[i] << ' ';
    return s.str();
}

int Vector::length() const {
    return m_d;
}

Vector Vector::times(const double alpha) const {
    Vector c(m_d);
    for (std::size_t i = 0; i < m_d; i++)
        c.m_data[i] = alpha * m_data[i];
    return c;
}

}
