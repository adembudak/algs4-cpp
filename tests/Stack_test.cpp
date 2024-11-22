#include <algs4/Stack.hpp>
#include <algs4/StdIn.h>
#include <algs4/StdOut.h>

#include <string>

// Stack < tobe.txt

int main(int argc, const char *argv[]) {
    using namespace algs4;

    Stack<std::string> stack;
    while (!StdIn::isEmpty()) {
        std::string item = StdIn::readString();

        if (item != "-") stack.push(item);
        else if (!stack.isEmpty()) StdOut::print(std::string(stack.pop()) + " ");
    }
    StdOut::println("(" + std::to_string(stack.size()) + " left on stack)");
}
