#ifndef COUNTER_H
#define COUNTER_H

#include <string>

namespace algs4 {
class Counter {
  private:
    std::string m_name;
    int count = 0;

  public:
    Counter() = default;
    Counter(const std::string &id);

    void increment();
    int tally() const;

    std::string name() const;
    operator std::string() const;
    int operator<(const Counter &that) const;
};

}

#endif
