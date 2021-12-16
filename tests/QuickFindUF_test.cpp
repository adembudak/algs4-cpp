#include <algs4/QuickFindUF.h>
#include <algs4/StdIn.h>
#include <algs4/StdOut.h>

// QuickFindUF_test < tinyUF.txt

int main(int argc, const char *argv[]) {
    using namespace algs4;

    int n = StdIn::readInt();
    QuickFindUF uf(n);

    while (!StdIn::isEmpty()) {
        int p = StdIn::readInt();
        int q = StdIn::readInt();
        if (uf.find(p) == uf.find(q)) continue;
        uf.Union(p, q);
        StdOut::printf("%d %d\n", p, q);
    }

    StdOut::printf("%d components\n", uf.count());
}
