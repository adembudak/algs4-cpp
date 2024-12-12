#include <algs4/DepthFirstSearch.h>
#include <algs4/Graph.h>

namespace algs4 {

void DepthFirstSearch::dfs(const Graph &G, int v) {
    count_++;
    marked_[v] = true;
    for (int w : G.adj(v)) {
        if (!marked_[w]) {
            dfs(G, w);
        }
    }
}

DepthFirstSearch::DepthFirstSearch(const Graph &G, int s) : marked_(G.V(), bool{}), count_{0} {
    dfs(G, s);
}

bool DepthFirstSearch::marked(int v) const {
    return marked_[v];
}
int DepthFirstSearch::count() const {
    return count_;
}

}
