#include <algs4/Shell.hpp>
#include <algs4/StdIn.h>

// Shell_test < tests/algs4-data/tiny.txt

int main(int argc, const char *argv[]) {
    using namespace algs4;

    auto a = StdIn::readAllStrings();
    Shell::sort(a);
    Shell::show(a);

    return 0;
}
