#include "algs4/StdIn.h"

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

namespace algs4 {
namespace StdIn {

bool isEmpty() {
    return (std::cin >> std::ws).peek() == std::char_traits<char>::eof();
}

bool hasNextLine() {
    return isEmpty() == false;
}

bool hasNextChar() {
    return (std::cin >> std::ws).peek() != std::char_traits<char>::eof();
}

std::string readLine() {
    std::string s;
    std::getline(std::cin >> std::ws, s);
    return s;
}

char readChar() {
    char c;
    std::cin >> c;
    return c;
}

std::string readAll() {
    return std::string(std::istreambuf_iterator<char>(std::cin), std::istreambuf_iterator<char>());
};

std::string readString() {
    std::string s;
    std::cin >> s;
    return s;
}

int readInt() {
    int i;
    std::cin >> i;
    return i;
}

double readDouble() {
    double d;
    std::cin >> d;
    return d;
}

float readFloat() {
    float f;
    std::cin >> f;
    return f;
}

long readLong() {
    long l;
    std::cin >> l;
    return l;
}

short readShort() {
    short s;
    std::cin >> s;
    return s;
}

byte readByte() {
    // There is no overload for std::int8_t
    // on operator>> in istream,
    // so just reading int and assigning it to
    // int8_t, implicit conversion occurs.
    int i;
    std::cin >> i;
    return i;
}

bool readBoolean() {
    bool q;
    std::cin >> q;
    return q;
}

std::vector<std::string> readAllStrings() {
    return std::vector<std::string>(std::istream_iterator<std::string>(std::cin),
                                    std::istream_iterator<std::string>());
}

std::vector<std::string> readAllLines() {
    std::vector<std::string> sv;

    for (std::string s; std::getline(std::cin, s);) {
        sv.emplace_back(s);
    }

    return sv;
}

std::vector<int> readAllInts() {
    return std::vector<int>(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
}

std::vector<long> readAllLongs() {
    return std::vector<long>(std::istream_iterator<long>(std::cin), std::istream_iterator<long>());
}

std::vector<double> readAllDoubles() {
    return std::vector<double>(std::istream_iterator<double>(std::cin),
                               std::istream_iterator<double>());
}

std::vector<int> readInts() {
    return readAllInts();
}

std::vector<double> readDoubles() {
    return readAllDoubles();
}

std::vector<std::string> readStrings() {
    return readAllStrings();
}

}
}
