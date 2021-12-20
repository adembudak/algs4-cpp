#include <algs4/InsertionX.hpp>
#include <algs4/StdIn.h>

// InsertionX_test < tiny.txt
// InsertionX_test < words3.txt

int main(int argc, const char *argv[]) {
    using namespace algs4;

    auto a = StdIn::readAllStrings();
    InsertionX::sort(a);
    InsertionX::show(a);

    return 0;
}
