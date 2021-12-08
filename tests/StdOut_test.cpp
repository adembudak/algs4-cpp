#include <algs4/StdOut.h>

// $ StdOut_test

int main() {
    using namespace algs4;

    // write to stdout
    StdOut::println("Test");
    StdOut::println(17);
    StdOut::println(true);
    StdOut::printf("%.6f\n", 1.0 / 7.0);

    return 0;
}
