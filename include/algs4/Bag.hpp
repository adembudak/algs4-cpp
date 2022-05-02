#ifndef BAG_HPP
#define BAG_HPP

#include <cstdint>
#include <iterator>

namespace algs4 {

template <typename T>
struct Node {
    T item;
    Node *next = nullptr;
};

template <typename T, class UnqualifedT = std::remove_cv<T>>
class ForwardIterator
    : public std::iterator<std::forward_iterator_tag, UnqualifedT, std::ptrdiff_t, T *, T &>

{
  public:
    using value_type = T;
    using distance_type = std::ptrdiff_t;

  private:
    Node<T> *iter = nullptr;

  public:
    explicit ForwardIterator(Node<T> *iter) : iter(iter) {
    }

    ForwardIterator &operator++() {
        iter = iter->next;
        return *this;
    }

    const ForwardIterator operator++(int) {
        const auto temp = *this;
        iter = iter->next;
        return temp;
    }

    template <typename Other>
    bool operator==(const ForwardIterator<Other> &other) {
        return iter == other.iter;
    }

    template <typename Other>
    bool operator!=(const ForwardIterator<Other> &other) {
        return iter != other.iter;
    }

    T &operator*() {
        return iter->item;
    }

    T &operator->() {
        return iter->item;
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
    Bag() = default;

    ~Bag() {
        while (first->next) {
            auto oldfirst = first;
            first = first->next;
            delete oldfirst;
        }
        delete first;
    }

    bool isEmpty() const {
        return first == nullptr;
    }

    std::size_t size() const {
        return n;
    }

    void add(const value_type &item) {
        if (!first) {
            first = new Node<T>;
            first->item = item;
        } else {
            auto oldfirst = first;

            first = new Node<T>;
            first->item = item;
            first->next = oldfirst;
        }
        n++;
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
