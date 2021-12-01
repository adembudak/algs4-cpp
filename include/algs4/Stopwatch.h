#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

namespace algs4 {

class Stopwatch {
  private:
    std::chrono::time_point<std::chrono::steady_clock> start;

  public:
    Stopwatch();
    double elapsedTime();
};

}

#endif
