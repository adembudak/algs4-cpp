#ifndef RECTHV_H
#define RECTHV_H

#include <string>

namespace algs4 {
class Point2D;

class RectHV {
  private:
    double m_xmin, m_ymin;
    double m_xmax, m_ymax;

  public:
    RectHV(const double xmin, const double ymin, const double xmax, const double ymax);

    double xmin() const;
    double xmax() const;

    double ymin() const;
    double ymax() const;

    double width() const;
    double height() const;

    bool intersects(const RectHV &that) const;
    bool contains(const Point2D &p) const;

    double distanceTo(const Point2D &p) const;
    double distanceSquaredTo(const Point2D &p) const;

    bool operator==(const RectHV &other) const;

    int hashCode() const;
    operator std::string() const;

    void draw() const;
};

}

#endif
