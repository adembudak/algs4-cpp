#include "algs4/In.h"
#include <cassert>

// test: In_readAllLines_test lorem_ipsum.dat

int main(int argc, char *argv[]) {
    using namespace algs4;

    In in(argv[1]);

    const auto lines = in.readAllLines();
    const auto first = lines.begin();
    assert(*first == "What is Lorem Ipsum?");

    const auto last = --lines.end();
    assert(*last == "publishing software like Aldus PageMaker including versions of Lorem Ipsum.");

    return 0;
}
