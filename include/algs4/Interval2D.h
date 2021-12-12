#ifndef INTERVAL2D_H
#define INTERVAL2D_H

#include <algs4/Interval1D.h>
#include <string>

namespace algs4 {

class Point2D;

class Interval2D {
  private:
    Interval1D m_x;
    Interval1D m_y;

  public:
    Interval2D(const Interval1D &x, const Interval1D &y);

    bool intersects(const Interval2D &that);
    bool contains(const Point2D &p);
    double area() const;

    operator std::string() const;
    bool operator==(const Interval2D &other) const;
    int hashCode() const;

    void draw() const;
};

}
#endif
