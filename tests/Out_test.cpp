#include <algs4/Out.h>

#include <fstream>

int main() {
    using namespace algs4;
    Out out;

    // write to stdout
    out.println("Test 1");
    out.close();

    // write to a file
    std::ofstream fout{"test.txt"};
    Out out2(fout);
    out2.println("Test 2");
    out2.close();

    return 0;
}
