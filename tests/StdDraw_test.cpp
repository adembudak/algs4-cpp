#include <algs4/StdDraw.h>

int main() {
    using namespace algs4;

    StdDraw.square(0.2, 0.8, 0.1);

    StdDraw.filledRectangle(0.8, 0.8, 0.2, 0.1);
    StdDraw.circle(0.8, 0.2, 0.2);

    StdDraw.text(0.2, 0.5, "black text");
    StdDraw.text(0.8, 0.8, "white text");

    std::vector<double> x = {0.1, 0.2, 0.3, 0.2};
    std::vector<double> y = {0.2, 0.3, 0.2, 0.1};
    StdDraw.polygon(x, y);

    StdDraw.draw();
}
