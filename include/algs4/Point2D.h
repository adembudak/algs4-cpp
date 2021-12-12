#ifndef POINT2D_H
#define POINT2D_H

#include <string>

namespace algs4 {

class Point2D {
  private:
    double m_x;
    double m_y;

  public:
    Point2D() = default;
    Point2D(const double x, const double y);

    double x() const;
    double y() const;

    double r() const;
    double theta() const;

    double angleTo(const Point2D &that) const;
    double distanceTo(const Point2D &that) const;
    double distanceSquaredTo(const Point2D &that) const;

    int operator<(const Point2D &that) const;
    bool operator==(const Point2D &that) const;
    operator std::string() const;
    int hashCode() const;

    void draw() const;
    void drawTo() const;

    bool Atan2Order(const Point2D &q1, const Point2D &q2);
    bool PolarOrder(const Point2D &q1, const Point2D &q2);
    bool DistanceToOrder(const Point2D &p, const Point2D &q);
};

int ccw(const Point2D &a, const Point2D &b, const Point2D &c);
double area2(const Point2D &a, const Point2D &b, const Point2D &c);

bool XOrder(const Point2D &p, const Point2D &q);
bool YOrder(const Point2D &p, const Point2D &q);
bool ROrder(const Point2D &p, const Point2D &q);

}

#endif
