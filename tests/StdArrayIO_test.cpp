#include "algs4/StdArrayIO.h"
#include "algs4/StdOut.h"

// cat algs4-data/tinyDouble1D.txt algs4-data/tinyDouble2D.txt \
// algs4-data/tinyBoolean2D.txt |  StdArrayIO_test

int main() {
    using namespace algs4;
    // read and print an array of doubles
    auto a = StdArrayIO::readDouble1D();
    StdArrayIO::print(a);
    StdOut::println();

    // read and print a matrix of doubles
    auto b = StdArrayIO::readDouble2D();
    StdArrayIO::print(b);
    StdOut::println();

    // read and print a matrix of doubles
    auto d = StdArrayIO::readBoolean2D();
    StdArrayIO::print(d);
    StdOut::println();

    return 0;
}
