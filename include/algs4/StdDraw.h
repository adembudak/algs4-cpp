#ifndef STDDRAW_H
#define STDDRAW_H

#include <ftxui/screen/color.hpp>
#include <ftxui/dom/canvas.hpp>
#include <vector>

namespace algs4 {

class Color {
  public:
    Color(uint8_t red, uint8_t green, uint8_t blue) : m_color(red, green, blue) {
    }

    auto data() const {
        return m_color;
    }

  private:
    ftxui::Color m_color;
};

const auto BLACK = Color{0, 0, 0};
const auto BLUE = Color{0, 0, 255};
const auto CYAN = Color{0, 255, 255};
const auto DARK_GRAY = Color{169, 169, 169};
const auto GRAY = Color{128, 128, 128};
const auto GREEN = Color{0, 255, 255};
const auto LIGHT_GRAY = Color{211, 211, 211};
const auto MAGENTA = Color{255, 0, 255};
const auto ORANGE = Color{255, 69, 0};
const auto PINK = Color{255, 192, 203};
const auto RED = Color{255, 0, 0};
const auto WHITE = Color{255, 255, 255};
const auto YELLOW = Color{255, 255, 0};
const auto BOOK_BLUE = Color{9, 90, 166};
const auto BOOK_LIGHT_BLUE = Color{103, 198, 243};
const auto BOOK_RED = Color{150, 35, 31};
const auto PRINCETON_ORANGE = Color{245, 128, 37};

class StdDraw {
  private:
    int x_dim = 128;
    int y_dim = 128;
    ftxui::Canvas m_canvas{x_dim, y_dim};

  public:
    void line(double x0, double y0, double x1, double y1, Color c = WHITE);
    void point(double x, double y, Color c = WHITE);
    void text(double x, double y, const std::string &s, Color c = WHITE);

    void circle(double x, double y, double r, Color c = WHITE);
    void filledCircle(double x, double y, double r, Color c = WHITE);

    void ellipse(double x, double y, double rw, double rh, Color c = WHITE);
    void filledEllipse(double x, double y, double rw, double rh, Color c = WHITE);

    void square(double x, double y, double r, Color c = WHITE);
    void filledSquare(double x, double y, double r, Color c = WHITE);

    void rectangle(double x, double y, double rw, double rh, Color c = WHITE);
    void filledRectangle(double x, double y, double rw, double rh, Color c = WHITE);

    void polygon(std::vector<double> x, std::vector<double> y, Color c = WHITE);
    void filledPolygon(std::vector<double> x, std::vector<double> y, Color c = WHITE);

    void draw();
};

inline StdDraw StdDraw;

}

#endif
