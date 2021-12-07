#include "algs4/Knuth.h"

#include <vector>
#include <random>

namespace algs4 {
namespace Knuth {

std::random_device rd;
std::mt19937 engine{rd()};

using int_distrib_t = std::uniform_int_distribution<int>;
using param_type = int_distrib_t::param_type;
int_distrib_t uniform;

void shuffle(std::vector<std::string> &a) {
    const int n = a.size();
    for (int i = 0; i < n; i++) {
        // choose index uniformly in [0, i]
        const int r = uniform(engine, param_type{0, i + 1});
        auto swap = a[r];
        a[r] = a[i];
        a[i] = swap;
    }
}

void shuffleAlternate(std::vector<std::string> &a) {
    const int n = a.size();
    for (int i = 0; i < n; i++) {
        // choose index uniformly in [i, n-1]
        const int r = i + uniform(engine, param_type{0, n - i});
        auto swap = a[r];
        a[r] = a[i];
        a[i] = swap;
    }
}

}
}
