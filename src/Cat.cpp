#include "algs4/In.h"
#include "algs4/Out.h"

#include <fstream>

/*
 *  Reads in text files specified as the first command-line
 *  arguments, concatenates them, and writes the result to
 *  filename specified as the last command-line arguments.
 *
 *  % more in1.txt
 *  This is
 *
 *  % more in2.txt
 *  a tiny
 *  test.
 *
 *  % cat in1.txt in2.txt out.txt
 *
 *  % more out.txt
 *  This is
 *  a tiny
 *  test.
 */

int main(int argc, const char *argv[]) {
    using namespace algs4;

    std::ofstream fout(argv[argc - 1]);
    Out out(fout);

    for (int i = 1; i < argc - 1; i++) {
        In in(argv[i]);

        auto s = in.readAll();
        out.println(s);
        in.close();
    }

    out.close();
}
