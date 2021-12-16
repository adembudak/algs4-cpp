#ifndef QUICKFINDUF_H
#define QUICKFINDUF_H

#include <vector>

namespace algs4 {

class QuickFindUF {
  private:
    std::vector<int> id;
    int m_count;

  private:
    void validate(const int p);

  public:
    QuickFindUF(const int n);

    int count() const;
    int find(const int p);
    [[deprecated]] bool connected(const int p, const int q);
    void Union(const int p, const int q); // union is reserved word
};
}

#endif
