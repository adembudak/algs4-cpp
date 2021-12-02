#ifndef STDARRAYIO_H
#define STDARRAYIO_H

#include <vector>

namespace algs4 {
namespace StdArrayIO {

std::vector<double> readDouble1D();
void print(const std::vector<double> &a);

// should i use valarray instead of vector of vector?
// TODO: check perf trade offs, benchmark?
std::vector<std::vector<double>> readDouble2D();
void print(const std::vector<std::vector<double>> &a);

std::vector<int> readInt1D();
void print(const std::vector<int> &a);

std::vector<std::vector<int>> readInt2D();
void print(const std::vector<std::vector<int>> &a);

// vector of bool :(
std::vector<bool> readBoolean1D();
void print(const std::vector<bool> &a);

std::vector<std::vector<bool>> readBoolean2D();
void print(const std::vector<std::vector<bool>> &a);

}

}

#endif
