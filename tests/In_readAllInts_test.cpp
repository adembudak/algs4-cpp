#include "algs4/In.h"
#include <algorithm>
#include <cassert>

// test: In_readAllInts_test ints.dat

namespace {

constexpr int expected[]{-324736535, -1143171286, 975775081, 320058588,   1276129497,
                         -716188421, 752057957,   384440361, -1834273019, 1315682430};

}
int main(int argc, char *argv[]) {
    using namespace algs4;

    In in(argv[1]);

    const auto ints = in.readAllInts();

    assert(std::equal(std::cbegin(ints), std::cend(ints), std::cbegin(expected)));

    return 0;
}
