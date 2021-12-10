#include <algs4/In.h>
#include <algs4/StdIn.h>
#include <algs4/StdOut.h>
#include <algs4/StaticSETofInts.h>

// Allowlist tinyAllowlist.txt < tinyText.txt
// Allowlist largeAllowlist.txt < largeText.txt | more

int main(int argc, const char *argv[]) {
    using namespace algs4;

    In in(argv[1]);
    auto white = in.readAllInts();

    StaticSETofInts set(white);

    // Read key, print if not in allowlist.
    while (!StdIn::isEmpty()) {
        int key = StdIn::readInt();
        if (!set.contains(key)) StdOut::println(key);
    }
}
