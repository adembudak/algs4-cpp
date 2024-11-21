#ifndef BAG_HPP
#define BAG_HPP

#include <cstddef>
#include <iterator>
#include <memory>

namespace algs4 {

template <typename T>
struct Node {
    T item;
    Node *next = nullptr;

    Node(T item, Node *next) : item{item}, next{next} {
    }
};

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

template <typename T>
class Bag {
  public:
    using value_type = T;
    using const_value_type = const value_type;
    using iterator = ForwardIterator<value_type>;
    using const_iterator = ForwardIterator<const_value_type>;

  private:
    using allocator_t = std::allocator<Node<value_type>>;
    allocator_t m_allocator;

    Node<value_type> *first = nullptr;
    std::size_t n = 0;

  public:
    ~Bag() {
        while (first) {
            auto oldfirst = first;
            first = first->next;
            std::allocator_traits<allocator_t>::destroy(m_allocator, oldfirst);
            std::allocator_traits<allocator_t>::deallocate(m_allocator, oldfirst, 1);
        }
    }

    bool isEmpty() const {
        return first == nullptr;
    }

    std::size_t size() const {
        return n;
    }

    void add(const value_type &item) {
        Node<T> *new_node = std::allocator_traits<allocator_t>::allocate(m_allocator, 1);
        std::allocator_traits<allocator_t>::construct(m_allocator, new_node, item, first);
        first = new_node;
        ++n;
    }

    iterator begin() const {
        return iterator{first};
    }

    iterator end() const {
        return iterator{nullptr};
    }
};

}

#endif
