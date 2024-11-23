#ifndef BAG_HPP
#define BAG_HPP

#include <cstddef>
#include <memory>

#include "detail/ForwardIterator.hpp"
#include "detail/Node.hpp"

namespace algs4 {

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
