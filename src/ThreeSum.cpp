#include "algs4/ThreeSum.h"
#include "algs4/StdOut.h"

#include <vector>
#include <string>

namespace algs4 {
namespace ThreeSum {

void printAll(const std::vector<int> &a) {
    const std::size_t n = a.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] + a[j] + a[k] == 0) {
                    StdOut::println(std::to_string(a[i]) + " " + std::to_string(a[j]) + " " +
                                    std::to_string(a[k]));
                }
            }
        }
    }
}

int count(const std::vector<int> &a) {
    const std::size_t n = a.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] + a[j] + a[k] == 0) {
                    count++;
                }
            }
        }
    }
    return count;
}

}
}
