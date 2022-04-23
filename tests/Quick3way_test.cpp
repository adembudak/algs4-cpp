#include <algs4/Quick3way.hpp>
#include <algs4/StdIn.h>

//  Quick3way_test < words3.txt

int main() {
    using namespace algs4;
    auto a = StdIn::readAllStrings();
    Quick3way::sort(a);
    Quick3way::show(a);
}
