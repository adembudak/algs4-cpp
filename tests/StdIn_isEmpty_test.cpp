#include "algs4/StdIn.h"
#include <cstdio>

int main() {
    using namespace algs4;

    while (!StdIn::isEmpty()) {
        puts(StdIn::readLine().c_str());
    }
}
