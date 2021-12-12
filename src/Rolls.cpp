#include <algs4/StdRandom.h>
#include <algs4/Counter.h>
#include <algs4/StdOut.h>

#include <vector>
#include <cstdlib>

// Rolls 1000000

int main(int argc, const char *argv[]) {
    using namespace algs4;
    const int T = std::atoi(argv[1]);
    const int SIDES = 6;

    std::vector<Counter> rolls(SIDES + 1);
    for (int i = 1; i <= SIDES; i++) {
        rolls[i] = Counter(std::to_string(i) + "'s");
    }

    for (int t = 0; t < T; t++) {
        int result = StdRandom::uniform(1, SIDES + 1);
        rolls[result].increment();
    }

    for (int i = 1; i <= SIDES; i++) {
        StdOut::println(rolls[i]);
    }
}
