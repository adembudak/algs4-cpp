#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <vector>

namespace algs4 {

namespace BinarySearch {

int indexOf(const std::vector<int> &a, int key);
[[deprecated]] int rank(int key, const std::vector<int> &a);

}
}

#endif
