#ifndef RESIZINGARRAYBAG_HPP
#define RESIZINGARRAYBAG_HPP

#include <cassert>
#include <cstdint>
#include <memory>

namespace algs4 {

template <typename Item>
class ResizingArrayBag {
  public:
    using allocator_type = std::allocator<Item>;
    using allocator = std::allocator_traits<allocator_type>;

  private:
    static constexpr std::size_t INIT_CAPACITY{8};

    allocator_type m_alloc;
    Item *a = nullptr;

    std::size_t n = 0; // number of elements on bag
    std::size_t m_capacity = INIT_CAPACITY;

  private:
    void resize(const std::size_t capacity) {
        assert(capacity >= n);

        std::size_t old_capacity = m_capacity;
        m_capacity = capacity;

        Item *temp = allocator::allocate(m_alloc, m_capacity);
        std::uninitialized_copy(a, a + n, temp);

        for (int i = n - 1; i >= 0; i--)
            allocator::destroy(m_alloc, a + i);

        allocator::deallocate(m_alloc, a, old_capacity);

        a = temp;
    }

  public:
    ResizingArrayBag() : a(allocator::allocate(m_alloc, INIT_CAPACITY)) {
    }

    ~ResizingArrayBag() {
        if (a) {
            for (int i = n - 1; i >= 0; --i)
                allocator::destroy(m_alloc, a + i);

            allocator::deallocate(m_alloc, a, m_capacity);
        }
    }

    bool isEmpty() const {
        return n == 0;
    }

    std::size_t size() const {
        return n;
    }

    void add(const Item &item) {
        if (n == m_capacity) resize(2 * n);

        allocator::construct(m_alloc, a + n, item);
        n++;
    }

    Item *begin() {
        return a;
    }

    Item *end() {
        return a + n;
    }

    const Item *begin() const {
        return a;
    }

    const Item *end() const {
        return a + n;
    }
};

}

#endif
