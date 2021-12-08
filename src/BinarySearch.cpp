#include "algs4/BinarySearch.h"

namespace algs4 {
namespace BinarySearch {

int indexOf(const std::vector<int> &a, int key) {
    int lo = 0;
    int hi = a.size() - 1;

    while (lo <= hi) {
        int mid = lo + ((hi - lo) / 2);
        if (key < a[mid]) hi = mid - 1;
        else if (key > a[mid]) lo = mid + 1;
        else return mid;
    }
    return -1;
}

int rank(int key, const std::vector<int> &a) {
    return BinarySearch::indexOf(a, key);
}

}

}
