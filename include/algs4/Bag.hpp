#ifndef BAG_HPP
#define BAG_HPP

#include <cstddef>
#include <iterator>
#include <type_traits>

namespace algs4 {

template <typename T>
struct Node {
    T item;
    Node *next = nullptr;
};

template <typename T>
class ForwardIterator {
  public:
    using value_type = std::remove_cv_t<T>;
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

template <typename T>
class Bag {
  public:
    using value_type = T;
    using const_value_type = const value_type;
    using iterator = ForwardIterator<value_type>;
    using const_iterator = ForwardIterator<const_value_type>;

  private:
    Node<value_type> *first = nullptr;
    std::size_t n = 0;

  public:
    ~Bag() {
        while (first) {
            auto oldfirst = first;
            first = first->next;
            delete oldfirst;
        }
    }

    bool isEmpty() const {
        return first == nullptr;
    }

    std::size_t size() const {
        return n;
    }

    void add(const value_type &item) {
        Node<T> *new_node = new Node<T>{item};
        new_node->next = first;
        first = new_node;
        ++n;
    }

    iterator begin() {
        return iterator{first};
    }

    const_iterator begin() const {
        return const_iterator{first};
    }

    iterator end() {
        return iterator{nullptr};
    }

    const_iterator end() const {
        return const_iterator{nullptr};
    }
};

}

#endif
