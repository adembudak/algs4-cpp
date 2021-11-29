#include "algs4/StdIn.h"
#include "algs4/StdOut.h"

int main() {
    using namespace algs4;

    std::vector<double> allDoubles = StdIn::readAllDoubles();

    for (auto n : allDoubles)
        StdOut::println(n);

    return 0;
}
