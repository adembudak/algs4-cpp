#include "algs4/Out.h"

#include <fstream>
#include <ostream>
#include <string>
#include <cstdarg>
#include <limits>
#include <iomanip>

namespace algs4 {

Out::Out(std::ofstream &os) : out(os) {
}

Out::Out(std::ostream &os) : out(os) {
}

void Out::close() {
}

void Out::println() {
    out << '\n';
}

void Out::println(const bool x) {
    out << std::boolalpha << x << '\n';
}

void Out::println(const char x) {
    out << x << '\n';
}

void Out::println(const double x) {
    out << x << std::setprecision(std::numeric_limits<double>::digits10) << '\n';
}

void Out::println(const float x) {
    out << x << std::setprecision(std::numeric_limits<double>::digits10) << '\n';
}

void Out::println(const int x) {
    out << x << '\n';
}

void Out::println(const long x) {
    out << x << '\n';
}

void Out::println(const byte x) {
    // casting to int makes value of x printable
    out << int(x) << '\n';
}

void Out::println(const std::string &x) {
    out << x << '\n';
}

void Out::println(const char *x) {
    out << x << '\n';
}

void Out::print() {
    out << std::flush;
}

void Out::print(const bool x) {
    out << std::boolalpha << x << std::flush;
}

void Out::print(const char x) {
    out << x << std::flush;
}

void Out::print(const double x) {
    out << x << std::setprecision(std::numeric_limits<double>::digits10) << std::flush;
}

void Out::print(const float x) {
    out << x << std::setprecision(std::numeric_limits<float>::digits10) << std::flush;
}

void Out::print(const int x) {
    out << x << std::flush;
}

void Out::print(const long x) {
    out << x << std::flush;
}

void Out::print(const byte x) {
    out << int(x) << std::flush;
}

void Out::print(const std::string &x) {
    out << x << std::flush;
}

void Out::print(const char *x) {
    out << x << std::flush;
}
}
