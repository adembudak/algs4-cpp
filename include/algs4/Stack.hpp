#ifndef STACK_H
#define STACK_H

#include <memory>
#include <cstddef>
#include <stdexcept>

#include "detail/Node.hpp"
#include "detail/ForwardIterator.hpp"

namespace algs4 {

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
