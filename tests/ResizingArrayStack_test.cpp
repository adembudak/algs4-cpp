#include <algs4/ResizingArrayStack.hpp>
#include <algs4/StdIn.h>
#include <algs4/StdOut.h>

#include <string>

// ResizingArrayStack_test < tobe.txt

int main(int argc, const char *argv[]) {
    using namespace algs4;
    ResizingArrayStack<std::string> stack;
    while (!StdIn::isEmpty()) {
        auto item = StdIn::readString();
        if (item != "-") stack.push(item);
        else if (!stack.isEmpty()) StdOut::print(stack.pop() + " ");
    }
    StdOut::println("(" + std::to_string(stack.size()) + " left on stack)");
}
