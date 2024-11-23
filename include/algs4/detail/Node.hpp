#ifndef NODE_H
#define NODE_H

namespace algs4 {

template <typename T>
struct Node {
    T item;
    Node *next = nullptr;

    Node(T item, Node *next) : item{item}, next{next} {
    }
};

}

#endif
