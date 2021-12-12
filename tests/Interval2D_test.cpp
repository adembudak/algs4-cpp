#include <algs4/Interval2D.h>
#include <algs4/Interval1D.h>
#include <algs4/Point2D.h>
#include <algs4/Counter.h>
#include <algs4/StdRandom.h>
#include <algs4/StdOut.h>

// Interval2D_test  box_x0 box_x1 box_y0 box_y1 trials
// Interval2D_test .2 .5 .5 .6 1000

#include <cstdlib>

int main(int argc, const char *argv[]) {
    using namespace algs4;
    double xmin = std::atof(argv[1]);
    double xmax = std::atof(argv[2]);
    double ymin = std::atof(argv[3]);
    double ymax = std::atof(argv[4]);
    int trials = std::atoi(argv[5]);

    Interval1D xInterval(xmin, xmax);
    Interval1D yInterval(ymin, ymax);
    Interval2D box(xInterval, yInterval);

    box.draw();

    Counter counter("hits");

    for (int t = 0; t < trials; t++) {
        double x = StdRandom::uniform(0.0, 1.0);
        double y = StdRandom::uniform(0.0, 1.0);
        Point2D point(x, y);

        if (box.contains(point)) counter.increment();
        else point.draw();
    }

    StdOut::println(counter);
    StdOut::printf("box area = %.2f\n", box.area());

    return 0;
}
