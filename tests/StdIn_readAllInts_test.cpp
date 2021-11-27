#include "algs4/StdIn.h"
#include "algs4/StdOut.h"

int main() {
    using namespace algs4;

    std::vector<int> allInts = StdIn::readAllInts();

    for (int i : allInts)
        StdOut::println(i);

    return 0;
}
