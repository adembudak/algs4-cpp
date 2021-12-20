#include <algs4/Selection.hpp>
#include <algs4/StdIn.h>

// Selection_test < tests/algs4-data/tiny.txt

int main(int argc, const char *argv[]) {
    using namespace algs4;

    auto a = StdIn::readAllStrings();
    // Selection::sort(a); // or with custom comparison predicate, like below
    Selection::sort(a, [](const std::string &a, const std::string &b) { return a < b; });
    Selection::show(a);

    return 0;
}
