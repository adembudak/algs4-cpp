#ifndef STATICSETOFINTS_H
#define STATICSETOFINTS_H

#include <vector>

namespace algs4 {

class StaticSETofInts {
  private:
    std::vector<int> m_a;

  public:
    StaticSETofInts(const std::vector<int> &a);

    bool contains(const int key) const;
    int rank(const int key) const;
};

}

#endif
