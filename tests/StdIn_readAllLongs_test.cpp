#include "algs4/StdIn.h"
#include "algs4/StdOut.h"

int main() {
    using namespace algs4;

    std::vector<long> allLongs = StdIn::readAllLongs();

    for (auto n : allLongs)
        StdOut::println(n);

    return 0;
}
