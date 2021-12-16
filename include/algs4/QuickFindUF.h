#ifndef QUICKFINDUF_H
#define QUICKFINDUF_H

#include <vector>
#include <cstdint>

namespace algs4 {

class QuickFindUF {
  private:
    std::vector<int> id;
    int m_count;

  private:
    void validate(const std::size_t p);

  public:
    QuickFindUF(const std::size_t n);

    int count() const;
    int find(const std::size_t p);
    [[deprecated]] bool connected(const std::size_t p, const std::size_t q);
    void Union(const std::size_t p, const std::size_t q); // union is reserved word
};
}

#endif
