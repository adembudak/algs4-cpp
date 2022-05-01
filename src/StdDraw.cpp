#include <algs4/StdDraw.h>

#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <cassert>

namespace {
// Normalize coordinates before passing ftxui API
// The original (the one on the book) StdDraw uses coordinates between [0, 1]
// e.g [0, 0] is left bottom, [1,1] right top
// this function maps the values [0, 1] to [0, 128]
//
// based on: https://stackoverflow.com/a/5732390
std::vector<int> normalize(const std::vector<double> &inputs) {
    const double input_range_start = 0, input_range_end = 1;
    const double output_range_start = 0, output_range_end = 128;

    std::vector<int> result;
    for (auto input : inputs) {
        double output_start = output_range_start;
        double output_end = output_range_end;

        double input_start = input_range_start;
        double input_end = input_range_end;

        double slope = 1.0 * (output_end - output_start) / (input_end - input_start);
        double output = output_start + slope * (input - input_start);
        result.push_back(static_cast<int>(output));
    }

    return result;
}

}

namespace algs4 {
using namespace ftxui;

void StdDraw::line(double x0, double y0, double x1, double y1, Color c) {
    auto v = normalize({x0, y0, x1, y1});
    m_canvas.DrawPointLine(v[0], y_dim - v[1], v[2], y_dim - v[3], c.data());
}

void StdDraw::point(double x, double y, Color c) {
    auto v = normalize({x, y});
    m_canvas.DrawPoint(v[0], y_dim - v[1], true, c.data());
}

void StdDraw::text(double x, double y, const std::string &s, Color c) {
    auto v = normalize({x, y});
    m_canvas.DrawText(v[0] - int(s.size()), y_dim - v[1], s, c.data());
}

void StdDraw::circle(double x, double y, double r, Color c) {
    auto v = normalize({x, y, r});
    m_canvas.DrawPointCircle(v[0], y_dim - v[1], v[2], c.data());
}

void StdDraw::filledCircle(double x, double y, double r, Color c) {
    auto v = normalize({x, y, r});
    m_canvas.DrawPointCircleFilled(v[0], y_dim - v[1], v[2], c.data());
}

void StdDraw::ellipse(double x, double y, double rw, double rh, Color c) {
    auto v = normalize({x, y, rw, rh});
    m_canvas.DrawPointEllipse(v[0], y_dim - v[1], v[2], v[3], c.data());
}

void StdDraw::filledEllipse(double x, double y, double rw, double rh, Color c) {
    auto v = normalize({x, y, rw, rh});
    m_canvas.DrawPointEllipseFilled(v[0], y_dim - v[1], v[2], v[3], c.data());
}

void StdDraw::square(double x, double y, double r, Color c) {
    auto v = normalize({x, y, r});
    int x_ = v[0];
    int y_ = y_dim - v[1];
    int r_ = v[2];

    m_canvas.DrawPointLine(x_ - r_, y_ + r_, x_ + r_, y_ + r_, c.data());
    m_canvas.DrawPointLine(x_ + r_, y_ + r_, x_ + r_, y_ - r_, c.data());
    m_canvas.DrawPointLine(x_ + r_, y_ - r_, x_ - r_, y_ - r_, c.data());
    m_canvas.DrawPointLine(x_ - r_, y_ - r_, x_ - r_, y_ + r_, c.data());
}

void StdDraw::filledSquare(double x, double y, double r, Color c) {
    auto v = normalize({x, y, r});
    int x_ = v[0];
    int y_ = y_dim - v[1];
    int r_ = v[2];

    for (int i = x_ - r_; i < x_ + r_; ++i)
        for (int j = y_ - r_; j < y_ + r_; ++j)
            m_canvas.DrawPoint(i, j, true, c.data());
}

void StdDraw::rectangle(double x, double y, double rw, double rh, Color c) {
    auto v = normalize({x, y, rw, rh});
    int x_ = v[0];
    int y_ = y_dim - v[1];
    int rw_ = v[2];
    int rh_ = v[3];

    m_canvas.DrawPointLine(x_ - rw_, y_ - rh_, x_ + rw_, y_ - rh_, c.data());
    m_canvas.DrawPointLine(x_ + rw_, y_ - rh_, x_ + rw_, y_ + rh_, c.data());
    m_canvas.DrawPointLine(x_ + rw_, y_ + rh_, x_ - rw_, y_ + rh_, c.data());
    m_canvas.DrawPointLine(x_ - rw_, y_ + rh_, x_ - rw_, y_ - rh_, c.data());
}

void StdDraw::filledRectangle(double x, double y, double rw, double rh, Color c) {
    auto v = normalize({x, y, rw, rh});
    int x_ = v[0];
    int y_ = y_dim - v[1];
    int rw_ = v[2];
    int rh_ = v[3];

    for (int i = x_ - rw_; i < x_ + rw_; ++i)
        for (int j = y_ - rh_; j < y_ + rh_; ++j)
            m_canvas.DrawPoint(i, j, true, c.data());
}

void StdDraw::polygon(std::vector<double> x, std::vector<double> y, Color c) {
    assert(x.size() == y.size() && "arrays must be of the same length");
    auto x_ = normalize(x);
    auto y_ = normalize(y);

    for (size_t i = 0; i < x_.size() - 1; ++i)
        m_canvas.DrawPointLine(x_[i], y_dim - y_[i], x_[i + 1], y_dim - y_[i + 1], c.data());

    m_canvas.DrawPointLine(x_[0], y_dim - y_[0], x_[x.size() - 1], y_dim - y_[x.size() - 1],
                           c.data());
}

void StdDraw::filledPolygon(std::vector<double> x, std::vector<double> y, Color c) {
    (void)x;
    (void)y;
    (void)c;

    assert(x.size() == y.size() && "arrays must be of the same length");
}

void StdDraw::draw() {
    auto document = canvas(&m_canvas) | ftxui::border;
    auto screen = Screen::Create(Dimension::Fit(document));

    Render(screen, document);
    screen.Print();
}

}
