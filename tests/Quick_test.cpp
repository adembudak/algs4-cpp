#include <algs4/Quick.hpp>
#include <algs4/StdIn.h>
#include <algs4/StdRandom.h>

#include <cassert>

// Quick_test < words3.txt

int main(int argc, const char *argv[]) {
    using namespace algs4;

    auto a = StdIn::readAllStrings();
    StdRandom::shuffle(a);

    Quick::sort(a);

    assert(Quick::isSorted(a));
    Quick::show(a);

    StdOut::println();
    for (std::size_t i = 0; i < a.size(); i++) {
        std::string ith = Quick::select(a, i);
        StdOut::println(ith);
    }

    return 0;
}
