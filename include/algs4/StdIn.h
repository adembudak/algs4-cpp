#ifndef STDIN_H
#define STDIN_H

#include <string>
#include <vector>

namespace algs4 {
using byte = std::int8_t;

namespace StdIn {
// from standard input one at a time:

bool isEmpty();
bool hasNextLine();
bool hasNextChar();

std::string readLine();
char readChar();
std::string readAll();
std::string readString();

int readInt();
double readDouble();
float readFloat();

long readLong();
short readShort();
byte readByte();
bool readBoolean();

// Reading a sequence of values of the same type from standard input.

std::vector<std::string> readAllStrings();
std::vector<std::string> readAllLines();
std::vector<int> readAllInts();
std::vector<double> readAllDoubles();
std::vector<long> readAllLongs();

[[deprecated]] std::vector<int> readInts();
[[deprecated]] std::vector<double> readDoubles();
[[deprecated]] std::vector<std::string> readStrings();

}

}

#endif
