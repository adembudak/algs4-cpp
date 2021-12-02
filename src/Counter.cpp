#include "algs4/Counter.h"

#include <string>

namespace algs4 {

Counter::Counter(const std::string &id) : name(id) {
}

void Counter::increment() {
    ++count;
}

int Counter::tally() const {
    return count;
}

Counter::operator std::string() const {
    return std::to_string(count) + " " + name;
}

int Counter::operator<(const Counter &that) const {
    if (count < that.count) return -1;
    else if (count > that.count) return +1;
    else return 0;
}

}
