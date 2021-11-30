#include "algs4/In.h"
#include <cassert>

// test: In_readString_test lorem_ipsum.dat

int main(int argc, char *argv[]) {
    using namespace algs4;

    In in(argv[1]);

    auto str = in.readString();
    assert(str == "What");

    str = in.readString();
    assert(str == "is");

    str = in.readString();
    assert(str == "Lorem");

    str = in.readString();
    assert(str == "Ipsum?");

    return 0;
}
