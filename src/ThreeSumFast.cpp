#include "algs4/StdOut.h"
#include "algs4/BinarySearch.h"

#include <vector>
#include <algorithm>
#include <string>

namespace algs4 {
namespace ThreeSumFast {

bool containsDuplicates(std::vector<int> &a) {
    for (int i = 1; i < a.size(); i++)
        if (a[i] == a[i - 1]) return true;
    return false;
}

void printAll(std::vector<int> &a) {
    int n = a.size();
    std::sort(a.begin(), a.end());

    if (containsDuplicates(a)) {
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = BinarySearch::indexOf(a, -(a[i] + a[j]));
            if (k > j)
                StdOut::println(std::to_string(a[i]) + " " + std::to_string(a[j]) + " " +
                                std::to_string(a[k]));
        }
    }
}

int count(std::vector<int> &a) {
    int n = a.size();
    std::sort(a.begin(), a.end());

    if (containsDuplicates(a)) {
        return -1;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = BinarySearch::indexOf(a, -(a[i] + a[j]));
            if (k > j) count++;
        }
    }

    return count;
}

}

}
