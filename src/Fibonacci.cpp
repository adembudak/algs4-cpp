#include <algs4/StdOut.h>

namespace algs4 {

long F(const int N) {
    if (N == 0) return 0;
    if (N == 1) return 1;
    return F(N - 1) + F(N - 2);
}

}

int main() {
    for (int N = 0; N < 100; N++)
        algs4::StdOut::printf("%lu %lu\n", N, algs4::F(N));
}
