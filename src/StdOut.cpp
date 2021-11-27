#include "algs4/StdOut.h"

#include <cstdint>
#include <cstdarg>
#include <cstdio>
#include <string>
#include <iostream>
#include <limits>
#include <iomanip>

namespace algs4 {
namespace StdOut {

void println() {
    std::cout << '\n';
}

void println(const std::string x) {
    std::cout << x << '\n';
}

void println(const char *x) {
    std::cout << x << '\n';
}

void println(const bool x) {
    std::cout << std::boolalpha << x << '\n';
}

void println(const char x) {
    std::cout << x << '\n';
}

void println(const int x) {
    std::cout << x << '\n';
}

void println(const double x) {
    std::cout.precision(std::numeric_limits<double>::digits10);
    std::cout << x << '\n';
}

void println(const float x) {
    std::cout.precision(std::numeric_limits<float>::digits10);
    std::cout << x << '\n';
}

void println(const long x) {
    std::cout << x << '\n';
}

void println(const short x) {
    std::cout << x << '\n';
}

void println(const byte x) {
    std::cout << x << '\n';
}

void print() {
    std::cout << std::flush;
}

void print(const std::string x) {
    std::cout << x << std::flush;
}

void print(const char *x) {
    std::cout << x << std::flush;
}

void print(const bool x) {
    std::cout << std::boolalpha << x << std::flush;
}

void print(const char x) {
    std::cout << x << std::flush;
}

void print(const int x) {
    std::cout << x << std::flush;
}

void print(const double x) {
    std::cout << x << std::flush;
}

void print(const float x) {
    std::cout << x << std::flush;
}

void print(const long x) {
    std::cout << x << std::flush;
}

void print(const short x) {
    std::cout << x << std::flush;
}

void print(const byte x) {
    std::cout << x << std::flush;
}

void printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    std::vprintf(format, args);
    va_end(args);
}

}
}
