#include <algs4/Bag.hpp>
#include <algs4/StdIn.h>
#include <algs4/StdOut.h>

int main(int argc, const char *argv[]) {
    using namespace algs4;

    Bag<std::string> bag;

    while (!StdIn::isEmpty()) {
        std::string item = StdIn::readString();
        bag.add(item);
    }

    StdOut::println("size of bag = " + std::to_string(bag.size()));
    for (const std::string &s : bag) {
        StdOut::println(s);
    }
}
