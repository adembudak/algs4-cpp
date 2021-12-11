#include <algs4/Counter.h>
#include <algs4/StdRandom.h>
#include <algs4/StdOut.h>

namespace algs4 {

Counter max(const Counter &x, const Counter &y) {
    if (x.tally() > y.tally()) return x;
    else return y;
}

}

int main(int argc, const char *argv[]) {
    using namespace algs4;

    const int n = std::atoi(argv[1]);

    Counter heads("heads");
    Counter tails("tails");

    for (int i = 0; i < n; i++) {
        if (StdRandom::bernoulli(0.5)) heads.increment();
        else tails.increment();
    }

    if (heads.tally() == tails.tally()) StdOut::println("Tie");
    else StdOut::println(algs4::max(heads, tails).name() + " wins");
}
