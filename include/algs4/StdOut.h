#ifndef STDOUT_H
#define STDOUT_H

#include <cstdint>
#include <string>

namespace algs4 {
using byte = std::int8_t;

namespace StdOut {
// print and terminate line;
void println();
void println(const std::string x);
void println(const char *x);
void println(const bool x);
void println(const char x);
void println(const int x);
void println(const double x);
void println(const float x);
void println(const long x);
void println(const short x);
void println(const byte x);

// print and flush standard output
void print();
void print(const std::string x);
void print(const char *x);
void print(const bool x);
void print(const char x);
void print(const int x);
void print(const double x);
void print(const float x);
void print(const long x);
void print(const short x);
void print(const byte x);

// print formatted string and flush standard output
void printf(const char *format, ...);

}
}

#endif
