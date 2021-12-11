#ifndef INTERVAL1D_H
#define INTERVAL1D_H

#include <string>

namespace algs4 {

class Interval1D {
  private:
    double m_min;
    double m_max;

  public:
    Interval1D() = default;
    Interval1D(const double min, const double max);

    [[deprecated]] double left() const;
    [[deprecated]] double right() const;

    double min() const;
    double max() const;

    bool intersects(const Interval1D &that) const;
    bool contains(const double x) const;
    double length() const;

    operator std::string() const;
    bool operator==(const Interval1D &other) const;
    int hashCode() const;
};

bool MinEndpointComparator(const Interval1D &a, const Interval1D &b);
bool MaxEndpointComparator(const Interval1D &a, const Interval1D &b);
bool LengthComparator(const Interval1D &a, const Interval1D &b);

}

#endif
