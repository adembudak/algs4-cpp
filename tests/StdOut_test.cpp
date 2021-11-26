#include "algs4/In.h"
#include "algs4/StdOut.h"

int main() {
    using namespace algs4;
    using namespace std::string_literals;

    // write to stdout
    StdOut::println();
    StdOut::println("Test string"s);
    StdOut::println("Test c-string");
    StdOut::println(true);
    StdOut::println('T');
    StdOut::println(17);
    StdOut::println(17.0);
    StdOut::println(17.0f);
    StdOut::println(short(17));
    StdOut::println(byte(17));

    StdOut::print();
    StdOut::print("Test string"s);
    StdOut::print("Test c-string");
    StdOut::print(true);
    StdOut::print('T');
    StdOut::print(17);
    StdOut::print(17.0);
    StdOut::print(17.0f);
    StdOut::print(short(17));
    StdOut::print(byte(17));
    StdOut::printf("%.6f\n", 1.0 / 7.0);
}
