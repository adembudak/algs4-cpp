#include <algs4/Bag.hpp>
#include <algs4/StdIn.h>
#include <algs4/StdOut.h>

/*
   public static void main(String[] args) {
        Bag<String> bag = new Bag<String>();
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            bag.add(item);
        }

        StdOut.println("size of bag = " + bag.size());
        for (String s : bag) {
            StdOut.println(s);
        }
    }
}
*/

int main() {
    using namespace algs4;

    Bag<std::string> bag;

    while (!StdIn::isEmpty()) {
        std::string item = StdIn::readString();
        bag.add(item);
    }

    for (const std::string &s : bag) {
        StdOut::println(s);
    }
}
