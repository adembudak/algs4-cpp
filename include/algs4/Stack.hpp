#ifndef STACK_H
#define STACK_H

#include <iterator>
#include <memory>
#include <cstddef>
#include <stdexcept>

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
class Stack {
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
    ~Stack() {
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

    void push(const value_type &item) {
        Node<T> *oldfirst = first;
        first = std::allocator_traits<allocator_t>::allocate(m_allocator, 1);
        std::allocator_traits<allocator_t>::construct(m_allocator, first, item, oldfirst);

        n++;
    }

    value_type pop() {
        if (isEmpty()) throw std::underflow_error("Stack underflow");

        value_type item = first->item;
        Node<T> *oldfirst = first;
        first = first->next;

        std::allocator_traits<allocator_t>::destroy(m_allocator, oldfirst);
        std::allocator_traits<allocator_t>::deallocate(m_allocator, oldfirst, 1);

        n--;

        return item;
    }

    value_type peek() const {
        if (isEmpty()) throw std::underflow_error("Stack underflow");
        return first->item;
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
