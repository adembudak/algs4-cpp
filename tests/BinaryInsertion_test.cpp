#include <algs4/BinaryInsertion.hpp>
#include <algs4/StdIn.h>

// BinaryInsertion_test < tiny.txt
// BinaryInsertion_test < words3.txt

int main() {
    using namespace algs4;

    auto a = StdIn::readAllStrings();
    BinaryInsertion::sort(a);
    BinaryInsertion::show(a);

    return 0;
}
