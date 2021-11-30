#include "algs4/In.h"
#include <algorithm>
#include <cassert>

// test: In_readAllLongs_test longs.dat

namespace {

constexpr long expected[]{-1143269017092291858, -5774791429818702767, 6596800808676048577,
                          -3554804805519196950, 3394331672868859842,  8522642482859791567,
                          -2832413606890753153, -373069588177637901,  2698855975664421269,
                          8734239878306445363};

}

int main(int argc, char *argv[]) {
    using namespace algs4;

    In in(argv[1]);

    const auto longs = in.readAllLongs();

    assert(std::equal(std::cbegin(longs), std::cend(longs), std::cbegin(expected)));

    return 0;
}
