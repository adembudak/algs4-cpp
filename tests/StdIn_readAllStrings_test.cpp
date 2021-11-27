#include "algs4/StdIn.h"
#include "algs4/StdOut.h"

int main() {
    using namespace algs4;

    std::vector<std::string> allStrings = StdIn::readAllStrings();

    for (auto &s : allStrings)
        StdOut::println(s);

    return 0;
}
