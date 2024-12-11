#include "algs4/Graph.h"
#include "algs4/In.h"
#include "algs4/StdOut.h"

#include <string>

// Graph_test tests/algs4-data/algs4-data/tinyG.txt
// Graph_test tests/algs4-data/algs4-data/mediumG.txt

int main(int argc, const char *argv[]) {
    using namespace algs4;
    In in(argv[1]);

    Graph G(in);
    StdOut::println(G);

    StdOut::println("vertex of maximum degree = " + std::to_string(maxDegree(G)));
    StdOut::println("average degree           = " + std::to_string(avgDegree(G)));
    StdOut::println("number of self loops     = " + std::to_string(numberOfSelfLoops(G)));
}
