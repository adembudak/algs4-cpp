#include "algs4/StdIn.h"
#include "algs4/StdOut.h"

// $ StdIn_readAllLines_test < loremIpsum.dat

int main() {
    using namespace algs4;

    std::vector<std::string> allLines = StdIn::readAllLines();

    for (auto &s : allLines)
        StdOut::println(s);

    return 0;
}
