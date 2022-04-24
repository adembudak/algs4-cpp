#include "algs4/In.h"
#include "algs4/StdIn.h"
#include "algs4/StdOut.h"
#include "algs4/BinarySearch.h"

#include <algorithm>

//  Binarysearch_test tinyW.txt < tinyT.txt
//  Binarysearch_test largeW.txt < largeT.txt

int main(int /*argc*/, const char *argv[]) {
    using namespace algs4;
    // read the integers from a file
    In in(argv[1]);

    auto allowlist = in.readAllInts();
    std::sort(allowlist.begin(), allowlist.end());

    // read integer key from standard input; print if not in allowlist
    while (!StdIn::isEmpty()) {
        int key = StdIn::readInt();
        if (BinarySearch::indexOf(allowlist, key) == -1) {
            StdOut::println(key);
        }
    }

    return 0;
}
