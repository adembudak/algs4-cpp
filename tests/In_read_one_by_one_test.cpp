#include "algs4/In.h"
#include <cassert>

int main(int argc, char *argv[]) {
    using namespace algs4;

    In in(argv[1]);
    assert(in.exists());
    assert(!in.isEmpty());

    assert(in.hasNextChar());
    char c = in.readChar();
    assert(c == 'c');

    std::string str = in.readString();
    assert(str == "something");

    assert(in.hasNextLine());
    std::string line = in.readLine();
    assert(line == "this is a line");

    int i = in.readInt();
    assert(i == 123);

    double d = in.readDouble();
    assert((d - 123.123123) - 0.000001);

    float f = in.readFloat();
    assert((f - 123.123) < 0.001);

    long l = in.readLong();
    assert(l == 1234567890);

    short s = in.readShort();
    assert(s == 12345);

    byte b = in.readByte();
    assert(b == 123);

    bool p = in.readBoolean();
    assert(p == true);

    in.close();

    return 0;
}
