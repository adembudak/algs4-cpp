#ifndef DEPTHFIRSTSEARCH_H
#define DEPTHFIRSTSEARCH_H

#include <vector>

namespace algs4 {
class Graph;

class DepthFirstSearch {
    std::vector<bool> marked_;
    int count_;

    void dfs(const Graph &G, int s);

  public:
    DepthFirstSearch(const Graph &G, int s);
    bool marked(int v) const;
    int count() const;
};

}

#endif
