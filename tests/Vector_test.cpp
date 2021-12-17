#include <algs4/Vector.h>
#include <algs4/StdOut.h>

#include <string>

// $ Vector_test

int main() {
    using namespace algs4;

    auto xdata = {1.0, 2.0, 3.0, 4.0};
    auto ydata = {5.0, 2.0, 4.0, 1.0};
    Vector x(xdata);
    Vector y(ydata);

    StdOut::println("   x       = " + std::string(x));
    StdOut::println("   y       = " + std::string(y));

    Vector z = x + y;
    StdOut::println("   z       = " + std::string(z));

    z = z.scale(10.0);
    StdOut::println(" 10z       = " + std::string(z));

    StdOut::printf("  |x|      = %f\n", x.magnitude());
    StdOut::printf(" <x, y>    = %f\n", x.dot(y));
    StdOut::printf("dist(x, y) = %f\n", x.distanceTo(y));
    StdOut::println("dir(x)     = " + std::string(x.direction()));
}
