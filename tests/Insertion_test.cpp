#include <algs4/Insertion.hpp>
#include <algs4/StdIn.h>

#include <string>

// Insertion_test < tiny.txt
// Insertion_test < words3.txt

int main(int argc, const char *argv[]) {
    using namespace algs4;

    auto a = StdIn::readAllStrings();
    Insertion::sort(a);
    Insertion::show(a);

    return 0;
}
