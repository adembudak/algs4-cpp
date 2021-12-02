#include "algs4/StdArrayIO.h"
#include "algs4/StdIn.h"
#include "algs4/StdOut.h"

#include <vector>

namespace algs4 {
namespace StdArrayIO {

std::vector<double> readDouble1D() {
    const std::size_t n = StdIn::readInt();

    std::vector<double> a;
    for (int i = 0; i < n; i++) {
        double val = StdIn::readDouble();
        a.push_back(val);
    }
    return a;
}

void print(const std::vector<double> &a) {
    const auto n = a.size();
    StdOut::println(n);
    for (int i = 0; i < n; i++) {
        StdOut::printf("%9.5f ", a[i]);
    }

    StdOut::println();
}

std::vector<std::vector<double>> readDouble2D() {
    const std::size_t m = StdIn::readInt();
    const std::size_t n = StdIn::readInt();

    std::vector<std::vector<double>> a(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            double val = StdIn::readDouble();
            a[i].push_back(val);
        }
    }

    return a;
}

void print(const std::vector<std::vector<double>> &a) {
    const auto m = a.size();
    const auto n = a[0].size();

    StdOut::printf("%d %d\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            StdOut::printf("%9.5f ", a[i][j]);
        }
        StdOut::println();
    }
}

std::vector<int> readInt1D() {
    const std::size_t n = StdIn::readInt();

    std::vector<int> a;
    for (int i = 0; i < n; i++) {
        int val = StdIn::readInt();
        a.push_back(val);
    }
    return a;
}

void print(const std::vector<int> &a) {
    const auto n = a.size();
    StdOut::println(n);
    for (int i = 0; i < n; i++) {
        StdOut::printf("%9d ", a[i]);
    }
    StdOut::println();
}

std::vector<std::vector<int>> readInt2D() {
    const std::size_t m = StdIn::readInt();
    const std::size_t n = StdIn::readInt();

    std::vector<std::vector<int>> a(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val = StdIn::readInt();
            a[i].push_back(val);
        }
    }
    return a;
}

void print(const std::vector<std::vector<int>> &a) {
    const auto m = a.size();
    const auto n = a[0].size();

    StdOut::printf("%d %d\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            StdOut::printf("%9d ", a[i][j]);
        }
        StdOut::println();
    }
}

std::vector<bool> readBoolean1D() {
    const std::size_t n = StdIn::readInt();

    std::vector<bool> a;
    for (int i = 0; i < n; i++) {
        bool val = StdIn::readBoolean();
        a.push_back(val);
    }
    return a;
}

void print(const std::vector<bool> &a) {
    const auto n = a.size();
    StdOut::println(n);
    for (int i = 0; i < n; i++) {
        StdOut::printf("%d ", a[i]);
    }
    StdOut::println();
}

std::vector<std::vector<bool>> readBoolean2D() {
    const std::size_t m = StdIn::readInt();
    const std::size_t n = StdIn::readInt();

    std::vector<std::vector<bool>> a(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            bool val = StdIn::readBoolean();
            a[i].push_back(val);
        }
    }
    return a;
}

void print(const std::vector<std::vector<bool>> &a) {
    const auto m = a.size();
    const auto n = a[0].size();

    StdOut::printf("%d %d\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            StdOut::printf("%1d ", a[i][j]);
        }
        StdOut::println();
    }
}

}

}
