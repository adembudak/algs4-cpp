#include "algs4/Graph.h"
#include "algs4/In.h"
#include "algs4/StdOut.h"

// Graph_test tests/algs4-data/algs4-data/tinyG.txt
// Graph_test tests/algs4-data/algs4-data/mediumG.txt

int main(int argc, const char *argv[]) {
    using namespace algs4;
    In in(argv[1]);

    Graph G(in);
    StdOut::println(G);
}
