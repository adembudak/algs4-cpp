#include "algs4/BinaryIn.h"

#include <fstream>
#include <string>
#include <stdexcept>

namespace algs4 {

BinaryIn::BinaryIn(const std::string &name) {
    fin.open(name, std::ios::binary);
    fin.exceptions(std::ios::failbit | std::ios::badbit);
}

void BinaryIn::open(const std::string &name) {
    if (fin.is_open()) this->close();

    fin.open(name, std::ios::binary);
    fin.exceptions(std::ios::failbit | std::ios::badbit);
}

void BinaryIn::close() {
    fin.close();
}

bool BinaryIn::exists() const {
    return fin.good();
}

bool BinaryIn::isEmpty() {
    return fin.peek() == decltype(fin)::traits_type::eof();
}

bool BinaryIn::readBoolean() {
    bool b;
    fin.read(reinterpret_cast<char *>(&b), sizeof(decltype(b)));
    return b;
}

char BinaryIn::readChar() {
    char c;
    fin.read(&c, sizeof(decltype(c)));
    return c;
}

char BinaryIn::readChar(int r) {
    using namespace std::string_literals;
    if (r < 1 || r > 8)
        throw std::invalid_argument("Illegal value of r = "s.append(std::to_string(r)));

    if (r == 8) return readChar();

    char ret = 0;
    for (int i = 0; i < r; i++) {
        ret <<= 1;
        bool bit = readBoolean();
        if (bit) ret |= 1;
    }
    return ret;
}

std::string BinaryIn::readString() {
    std::string s;

    while (!isEmpty())
        s += readChar();

    return s;
}

short BinaryIn::readShort() {
    short sh;
    fin.read(reinterpret_cast<char *>(&sh), sizeof(decltype(sh)));
    return sh;
}

int BinaryIn::readInt() {
    int i;
    fin.read(reinterpret_cast<char *>(&i), sizeof(decltype(i)));
    return i;
}

int BinaryIn::readInt(int r) {
    int x = readInt();

    int ret = 0;
    for (int i = 0; i < r; i++) {
        ret <<= 1;
        bool bit = readBoolean();
        if (bit) ret |= 1;
    }

    return ret;
}

long BinaryIn::readLong() {
    long l;
    fin.read(reinterpret_cast<char *>(&l), sizeof(decltype(l)));
    return l;
}

double BinaryIn::readDouble() {
    double d;
    fin.read(reinterpret_cast<char *>(&d), sizeof(decltype(d)));
    return d;
}

float BinaryIn::readFloat() {
    float f;
    fin.read(reinterpret_cast<char *>(&f), sizeof(decltype(f)));
    return f;
}

unsigned char BinaryIn::readByte() {
    unsigned char uc;
    fin.read(reinterpret_cast<char *>(&uc), sizeof(decltype(uc)));
    return uc;
}

}
