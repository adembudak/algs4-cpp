#ifndef GRAPH_H
#define GRAPH_H

#include <algs4/Bag.hpp>
#include <vector>

namespace algs4 {
class In;

class Graph {
    int V_;
    int E_;
    std::vector<Bag<int>> adj_;

  public:
    Graph(int V);
    Graph(In &in);
    Graph(const Graph &other);

    int E() const;
    int V() const;

    void addEdge(int v, int w);

    Bag<int> &adj(int v);
    const Bag<int> &adj(int v) const;

    int degree(int v) const;

    operator std::string() const;
};

}

#endif
