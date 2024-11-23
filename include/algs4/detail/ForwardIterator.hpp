#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "Node.hpp"
#include <iterator>

namespace algs4 {
template <typename T>
class ForwardIterator {
  public:
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T *;
    using reference = T &;
    using iterator_category = std::forward_iterator_tag;

  private:
    Node<T> *iter = nullptr;

  public:
    explicit ForwardIterator(Node<T> *iter) : iter{iter} {
    }

    ForwardIterator &operator++() {
        iter = iter->next;
        return *this;
    }

    ForwardIterator operator++(int) {
        ForwardIterator temp = *this;
        iter = iter->next;
        return temp;
    }

    template <typename U>
    bool operator==(const ForwardIterator<U> &other) const {
        return iter == other.iter;
    }

    template <typename U>
    bool operator!=(const ForwardIterator<U> &other) const {
        return iter != other.iter;
    }

    T &operator*() {
        return iter->item;
    }

    const T &operator*() const {
        return iter->item;
    }

    T *operator->() {
        return &iter->item;
    }

    const T *operator->() const {
        return &iter->item;
    }
};

}

#endif
