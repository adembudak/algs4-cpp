#include "algs4/In.h"

#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <cassert>

namespace algs4 {

In::In(const std::string &file) {
    fin.open(file);
    assert(fin.is_open());
}

In::In(const char *file) {
    fin.open(file);
    assert(fin.is_open());
}

bool In::exists() {
    return fin.good();
}

bool In::isEmpty() {
    return (fin >> std::ws).peek() == std::char_traits<char>::eof();
}

bool In::hasNextChar() {
    return (fin >> std::ws).peek() != std::char_traits<char>::eof();
}

bool In::hasNextLine() {
    return isEmpty() == false;
}

std::string In::readString() {
    std::string str;
    fin >> str;
    return str;
}

std::string In::readLine() {
    std::string s;
    std::getline(fin >> std::ws, s);
    return s;
}

std::string In::readAll() {
    return std::string(std::istreambuf_iterator<char>(fin), std::istreambuf_iterator<char>());
}

char In::readChar() {
    char c;
    fin >> c;
    return c;
}

int In::readInt() {
    int i;
    fin >> i;
    return i;
}

double In::readDouble() {
    double d;
    fin >> d;
    return d;
}

float In::readFloat() {
    float f;
    fin >> f;
    return f;
}

long In::readLong() {
    long l;
    fin >> l;
    return l;
}

short In::readShort() {
    short s;
    fin >> s;
    return s;
}

byte In::readByte() {
    int i;
    fin >> i;
    return i;
}

bool In::readBoolean() {
    bool q;
    fin >> std::boolalpha >> q;
    return q;
}

std::vector<std::string> In::readAllStrings() {
    return std::vector<std::string>(std::istream_iterator<std::string>(fin),
                                    std::istream_iterator<std::string>());
}

std::vector<std::string> In::readAllLines() {
    std::vector<std::string> sv;

    for (std::string s; std::getline(fin, s);) {
        sv.emplace_back(s);
    }

    return sv;
}

std::vector<int> In::readAllInts() {
    return std::vector<int>(std::istream_iterator<int>(fin), std::istream_iterator<int>());
}

std::vector<long> In::readAllLongs() {
    return std::vector<long>(std::istream_iterator<long>(fin), std::istream_iterator<long>());
}

std::vector<double> In::readAllDoubles() {
    return std::vector<double>(std::istream_iterator<double>(fin), std::istream_iterator<double>());
}

void In::close() {
    if (fin.is_open()) {
        fin.close();
    }
}

std::vector<int> In::readints(std::string filename) {
    fin.open(filename);
    return readAllInts();
}

std::vector<double> In::readDoubles(std::string filename) {
    fin.open(filename);
    return readAllDoubles();
}

std::vector<std::string> In::readStrings(std::string filename) {
    fin.open(filename);
    return readAllStrings();
}

std::vector<int> In::readInts() {
    return readAllInts();
}

std::vector<double> In::readDoubles() {
    return readAllDoubles();
}

std::vector<std::string> In::readStrings() {
    return readAllStrings();
}
}
