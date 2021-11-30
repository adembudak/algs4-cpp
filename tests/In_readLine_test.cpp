#include "algs4/In.h"
#include <cassert>

// test: In_readLine_test lorem_ipsum.dat

int main(int argc, char *argv[]) {
    using namespace algs4;

    In in(argv[1]);

    const auto str = in.readLine();
    assert(str == "What is Lorem Ipsum?");

    return 0;
}
