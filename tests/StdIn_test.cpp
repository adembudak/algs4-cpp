#include <algs4/StdIn.h>
#include <algs4/StdOut.h>

#include <string>

// $ StdIn_test < test-input/StdIn_test.dat

int main() {
    using namespace algs4;

    StdOut::print("Type a string: ");
    std::string s = StdIn::readString();
    StdOut::println("Your string was: " + s);
    StdOut::println();

    StdOut::print("Type an int: ");
    int a = StdIn::readInt();
    StdOut::println("Your int was: " + std::to_string(a));
    StdOut::println();

    StdOut::print("Type a boolean: ");
    bool b = StdIn::readBoolean();
    StdOut::println("Your boolean was: " + std::to_string(b));
    StdOut::println();

    StdOut::print("Type a double: ");
    double c = StdIn::readDouble();
    StdOut::println("Your double was: " + std::to_string(c));
    StdOut::println();

    return 0;
}
