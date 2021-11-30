#include "algs4/In.h"
#include <algorithm>
#include <cassert>

// test: In_readAllDoubles_test doubles.dat

namespace {

constexpr double expected[]{50.4694713085557, 97.2109697564375, 42.8558717206063, 75.7925626805385,
                            62.1267417918643, 23.8970631105565, 55.2080193484384, 3.28981324421059,
                            77.419678427009,  72.7149655578542};

}
int main(int argc, char *argv[]) {
    using namespace algs4;

    In in(argv[1]);

    const auto doubles = in.readAllDoubles();

    assert(std::equal(std::cbegin(doubles), std::cend(doubles), std::cbegin(expected)));

    return 0;
}
