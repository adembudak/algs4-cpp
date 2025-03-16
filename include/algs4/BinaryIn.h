#ifndef BINARY_IN_H
#define BINARY_IN_H

#include <fstream>
#include <string>

namespace algs4 {

class BinaryIn {
  private:
    std::ifstream fin;

  public:
    BinaryIn() = default;
    BinaryIn(const std::string &name);

    void open(const std::string &name);
    void close();

    bool exists() const;
    bool isEmpty();

    bool readBoolean();
    char readChar();
    char readChar(int r);

    std::string readString();
    short readShort();
    int readInt();
    int readInt(int r);
    long readLong();
    double readDouble();
    float readFloat();
    unsigned char readByte();
};

}

#endif
