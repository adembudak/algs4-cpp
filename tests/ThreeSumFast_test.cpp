#include "algs4/ThreeSumFast.h"
#include "algs4/StdOut.h"
#include "algs4/In.h"

int main(int argc, const char *argv[]) {
    using namespace algs4;
    In in(argv[1]);

    auto a = in.readAllInts();
    int count = ThreeSumFast::count(a);
    StdOut::println(count);

    return 0;
}
