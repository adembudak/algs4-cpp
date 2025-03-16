#include <algs4/BinaryIn.h>

#include <iostream>

int main() {
    using namespace algs4;

    BinaryIn bin;

    try {
        bin.open("Nonexisted file");
    } catch (const std::exception &e) {
        std::cout << "Nonexisted file : " << e.what() << '\n';
    }
}
