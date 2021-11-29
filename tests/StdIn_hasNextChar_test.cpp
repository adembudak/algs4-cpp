#include "algs4/StdIn.h"
#include <cstdio>

int main() {
    using namespace algs4;

    while (StdIn::hasNextChar()) {
        putchar(StdIn::readChar());
    }
}
