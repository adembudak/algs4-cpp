#include "algs4/Knuth.h"
#include "algs4/StdIn.h"
#include "algs4/StdOut.h"

int main() {
    using namespace algs4;

    auto a = StdIn::readAllStrings();

    Knuth::shuffle(a);

    for (std::size_t i = 0; i < a.size(); i++) {
        StdOut::println(a[i]);
    }

    return 0;
}
