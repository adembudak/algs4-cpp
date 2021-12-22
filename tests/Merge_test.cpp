#include <algs4/Merge.hpp>
#include <algs4/StdIn.h>

// Merge_test < tiny.txt

int main(int argc, const char *argv[]) {
    using namespace algs4;

    auto a = StdIn::readAllStrings();
    Merge::sort(a);
    Merge::indexSort(a);
    Merge::show(a);
}
