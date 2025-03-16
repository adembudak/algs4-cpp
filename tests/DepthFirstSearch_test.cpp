#include <algs4/DepthFirstSearch.h>
#include <algs4/Graph.h>
#include <algs4/StdOut.h>
#include <algs4/StdIn.h>
#include <algs4/In.h>

int main(int args, const char *argv[]) {
    using namespace algs4;

    In in(argv[1]);

    Graph G(in);
    int s = StdIn::readInt();
    DepthFirstSearch search(G, s);

    for (int v = 0; v < G.V(); v++) {
        if (search.marked(v)) StdOut::printf("%d ", v);
    }

    StdOut::println();
    if (search.count() != G.V()) StdOut::println("NOT connected");
    else StdOut::println("connected");

    return 0;
}
