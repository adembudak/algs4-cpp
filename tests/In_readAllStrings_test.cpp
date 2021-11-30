#include "algs4/In.h"
#include <cassert>

// test: In_readAllStrings_test lorem_ipsum.dat

int main(int argc, char *argv[]) {
    using namespace algs4;

    In in(argv[1]);

    const auto strings = in.readAllStrings();
    const auto first = strings.begin();
    assert(*first == "What");

    const auto last = --strings.end();
    assert(*last == "Ipsum.");

    return 0;
}
