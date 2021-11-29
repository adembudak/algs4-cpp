#ifndef IN_H
#define IN_H

#include <string>
#include <vector>
#include <fstream>

namespace algs4 {

using byte = std::int8_t;

class In {
  private:
    std::ifstream fin;

  public:
    // todo: implement these
    // In(Socket socket);
    // In(Url url);

    In(const std::string &file);
    In(const char *file);

    bool exists();
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

    std::vector<std::string> readAllStrings();
    std::vector<std::string> readAllLines();
    std::vector<int> readAllInts();
    std::vector<long> readAllLongs();
    std::vector<double> readAllDoubles();
    void close();

    [[deprecated]] std::vector<int> readints(std::string filename);
    [[deprecated]] std::vector<double> readDoubles(std::string filename);
    [[deprecated]] std::vector<std::string> readStrings(std::string filename);
    [[deprecated]] std::vector<int> readInts();
    [[deprecated]] std::vector<double> readDoubles();
    [[deprecated]] std::vector<std::string> readStrings();
};
}

#endif
