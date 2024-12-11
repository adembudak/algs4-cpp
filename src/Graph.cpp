#include <algs4/Graph.h>
#include <algs4/In.h>
#include <algs4/Stack.hpp>

#include <sstream>

namespace algs4 {

Graph::Graph(int V) : V_(V), E_(0), adj_(V, Bag<int>{}) {
}

Graph::Graph(In &in) {
    V_ = in.readInt();
    E_ = 0;
    adj_.resize(V_, Bag<int>{});

    int E = in.readInt();
    for (int i = 0; i < E; i++) {
        int v = in.readInt();
        int w = in.readInt();
        addEdge(v, w);
    }
}

Graph::Graph(const Graph &other) {
    V_ = other.V();
    E_ = other.E();
    adj_.resize(V_);

    for (int v = 0; v < other.V(); v++) {
        Stack<int> reverse;
        for (int w : other.adj_[v]) {
            reverse.push(w);
        }
        for (int w : reverse) {
            adj_[v].add(w);
        }
    }
}

Graph &Graph::operator=(const Graph &other) {
    V_ = other.V();
    E_ = other.E();
    adj_.resize(V_);

    for (int v = 0; v < other.V(); v++) {
        Stack<int> reverse;
        for (int w : other.adj_[v]) {
            reverse.push(w);
        }
        for (int w : reverse) {
            adj_[v].add(w);
        }
    }
    return *this;
}

int Graph::E() const {
    return E_;
}

int Graph::V() const {
    return V_;
}

void Graph::addEdge(int v, int w) {
    E_++;
    adj_[v].add(w);
    adj_[w].add(v);
}

Bag<int> &Graph::adj(int v) {
    return adj_[v];
}

const Bag<int> &Graph::adj(int v) const {
    return adj_[v];
}

int Graph::degree(int v) const {
    return adj_[v].size();
}

Graph::operator std::string() const {
    std::ostringstream sout;
    sout << V_ << " vertices, " << E_ << " edges \n";

    for (int v = 0; v < V_; v++) {
        sout << v << ": ";
        for (const auto w : adj_[v]) {
            sout << w << " ";
        }
        sout << "\n";
    }

    return sout.str();
}

int maxDegree(const Graph &G) {
    int max = 0;
    for (int v = 0; v < G.V(); v++)
        if (G.degree(v) > max)
            max = G.degree(v);
    return max;
}

int avgDegree(const Graph &G) {
    return 2 * G.E() / G.V();
}

int numberOfSelfLoops(const Graph &G) {
    int count = 0;
    for (int v = 0; v < G.V(); v++)
        for (int w : G.adj(v))
            if (v == w) count++;
    return count / 2;
}

}
