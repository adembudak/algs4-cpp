#include "algs4/StdIn.h"
#include <cassert>

int main() {
    using namespace algs4;

    char c = StdIn::readChar();
    assert(c == 'c');

    std::string str = StdIn::readString();
    assert(str == "something");

    std::string line = StdIn::readLine();
    assert(line == "this is a line");

    int i = StdIn::readInt();
    assert(i == 123);

    double d = StdIn::readDouble();
    assert((d - 123.123123) - 0.000001);

    float f = StdIn::readFloat();
    assert((f - 123.123) < 0.001);

    long l = StdIn::readLong();
    assert(l == 1234567890);

    short s = StdIn::readShort();
    assert(s == 12345);

    byte b = StdIn::readByte();
    assert(b == 123);

    bool p = StdIn::readBoolean();
    assert(p == true);

    return 0;
}
