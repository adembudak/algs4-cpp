#ifndef EUCLIDEAN_VECTOR_H
#define EUCLIDEAN_VECTOR_H

#include <cstdint>
#include <vector>
#include <initializer_list>
#include <string>

// Euclidean vector implementation
namespace algs4 {

class Vector {
  private:
    std::size_t m_d;
    std::vector<double> m_data;

  public:
    Vector(const std::size_t d);
    Vector(const std::initializer_list<double> &a);

    int dimension() const;
    double dot(const Vector &that) const;
    double magnitude() const;
    double distanceTo(const Vector &that) const;
    double cartesian(std::size_t i) const;

    Vector scale(const double alpha) const;
    Vector direction() const;

    Vector operator+(const Vector &that) const;
    Vector operator-(const Vector &that) const;

    operator std::string() const;

    [[deprecated]] int length() const;
    [[deprecated]] Vector times(const double alpha) const;
};
}

#endif
