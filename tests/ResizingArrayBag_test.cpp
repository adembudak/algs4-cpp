#include "algs4/ResizingArrayBag.hpp"
#include "algs4/StdOut.h"
#include <string>

int main() {
    using namespace algs4;

    ResizingArrayBag<std::string> bag;
    bag.add("Hello");
    bag.add("World");
    bag.add("how");
    bag.add("are");
    bag.add("you");

    for (const auto &s : bag)
        StdOut::println(s);

    return 0;
}
