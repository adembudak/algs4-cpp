#ifndef RESIZINGARRAYSTACK_HPP
#define RESIZINGARRAYSTACK_HPP

#include <memory>
#include <cassert>
#include <stdexcept>

namespace algs4 {

template <typename Item>
class ResizingArrayStack {
  public:
    using allocator_type = std::allocator<Item>;
    using allocator = std::allocator_traits<allocator_type>;

  private:
    static constexpr int INIT_CAPACITY{8};

    std::size_t m_size = 0;
    std::size_t m_capacity = INIT_CAPACITY;
    allocator_type m_alloc;

    Item *m_data = nullptr;

  private:
    void resize(int capacity) {
        assert(capacity >= m_size);
        std::size_t old_capacity = m_capacity;
        m_capacity = capacity;

        Item *temp = allocator::allocate(m_alloc, m_capacity);
        std::uninitialized_copy(m_data, m_data + m_size, temp);

        for (int i = m_size - 1; i >= 0; i--)
            allocator::destroy(m_alloc, m_data + i);

        allocator::deallocate(m_alloc, m_data, old_capacity);

        m_data = temp;
    }

  public:
    ~ResizingArrayStack() {
        if (m_data) {
            for (int i = m_size - 1; i >= 0; --i)
                allocator::destroy(m_alloc, m_data + i);

            allocator::deallocate(m_alloc, m_data, m_capacity);
        }
    }

    ResizingArrayStack() : m_data(allocator::allocate(m_alloc, m_capacity)) {
    }

    bool isEmpty() const noexcept {
        return m_size == 0;
    }

    std::size_t size() const noexcept {
        return m_size;
    }

    void push(Item item) {
        if (m_size == m_capacity) resize(2 * m_size);

        allocator::construct(m_alloc, m_data + m_size, item);
        ++m_size;
    }

    Item pop() {
        if (isEmpty()) throw std::runtime_error("No Such Element");

        --m_size;
        Item item = m_data[m_size];
        allocator::destroy(m_alloc, m_data + m_size);

        if (m_size > 0 && m_size == (size() / 4)) resize(size() / 2);

        return item;
    }

    Item peek() {
        if (isEmpty()) throw std::runtime_error("Stack underflow");

        return m_data[m_size - 1];
    }

    Item *begin() {
        return m_data;
    }

    Item *end() {
        return m_data + m_size;
    }
};

}

#endif
