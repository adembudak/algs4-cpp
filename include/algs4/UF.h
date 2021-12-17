#ifndef UF_H
#define UF_H

#include <vector>
#include <cstdint>

namespace algs4 {

class UF {
  private:
    std::vector<int> m_parent;
    std::vector<std::int8_t> m_rank;
    std::size_t m_count;

  private:
    void validate(const std::size_t p) const;

  public:
    UF(const std::size_t n);

    std::size_t find(std::size_t p);
    std::size_t count() const;

    void Union(const std::size_t p, const std::size_t q);

    [[deprecated]] bool connected(const std::size_t p, const std::size_t q);
};

}

#endif
