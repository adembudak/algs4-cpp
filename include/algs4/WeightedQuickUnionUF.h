#ifndef WEIGHTEDQUICKUNIONUF_H
#define WEIGHTEDQUICKUNIONUF_H

#include <vector>
#include <cstdint>

namespace algs4 {

class WeightedQuickUnionUF {
  private:
    std::vector<int> m_parent;
    std::vector<int> m_size;
    int m_count;

  private:
    void validate(const std::size_t p) const;

  public:
    WeightedQuickUnionUF(const std::size_t n);

    int count() const;
    int find(int p) const;
    void Union(const std::size_t p, const std::size_t q);

    [[deprecated]] bool connected(const std::size_t p, const std::size_t q) const;
};

}

#endif
