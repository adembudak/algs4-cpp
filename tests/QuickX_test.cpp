#include <algs4/QuickX.hpp>
#include <algs4/StdIn.h>
#include <algs4/StdRandom.h>

#include <cassert>

// QuickX_test < words3.txt

int main(int argc, const char *argv[]) {
    using namespace algs4;

    auto a = StdIn::readAllStrings();
    StdRandom::shuffle(a);

    QuickX::sort(a);

    assert(QuickX::isSorted(a));
    QuickX::show(a);

    return 0;
}
