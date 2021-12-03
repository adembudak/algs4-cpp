#ifndef OUT_H
#define OUT_H

#include <iosfwd>
#include <iostream>
#include <string>

#include <cstdint>

namespace algs4 {
using byte = std::int8_t;

class Out {
  private:
    std::ostream &out;

  public:
    Out(std::ofstream &os);
    Out(std::ostream &os = std::cout);

    void close();

    void println();
    // void println(Object x) // not implmented
    void println(const bool x);
    void println(const char x);
    void println(const double x);
    void println(const float x);
    void println(const int x);
    void println(const long x);
    void println(const byte x);
    void println(const std::string &x);

    void print();
    // void print(Object x) // not implmented
    void print(const bool x);
    void print(const char x);
    void print(const double x);
    void print(const float x);
    void print(const int x);
    void print(const long x);
    void print(const byte x);
    void print(const std::string &x);

    // TODO: implement formatted output to file
    // void printf(const char *format, ...);
};

}

#endif
