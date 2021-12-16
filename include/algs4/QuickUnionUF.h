#ifndef QUICKUNIONUF_H
#define QUICKUNIONUF_H

#include <cstdint>
#include <vector>

namespace algs4 {

class QuickUnionUF {
  private:
    std::vector<int> m_parent;
    int m_count;

  private:
    void validate(const std::size_t p) const;

  public:
    QuickUnionUF(const std::size_t n);

    int count() const;

    int find(std::size_t p) const;
    [[deprecated]] bool connected(const std::size_t p, const std::size_t q) const;

    void Union(const std::size_t p, const std::size_t q);
};

}

#endif
