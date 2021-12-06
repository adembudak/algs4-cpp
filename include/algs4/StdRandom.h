#ifndef STDRANDOM_H
#define STDRANDOM_H

#include <vector>

namespace algs4 {

namespace StdRandom {

void setSeed(const long s);
long getSeed();

double uniform();
int uniform(const int n);
long uniform(const long n);

[[deprecated]] double random();

int uniform(const int a, const int b);
double uniform(const double a, const double b);

bool bernoulli(const double p);
bool bernoulli();

double gaussian();
double gaussian(const double mu, const double sigma);

int geometric(const double p);
int poisson(const double lambda);

double pareto();
double pareto(const double alpha);

double cauchy();

int discrete(const std::vector<double> &probabilities);
int discrete(const std::vector<int> &frequencies);

double exp(const double lambda);

void shuffle(std::vector<double> &a);
void shuffle(std::vector<double> &a, const int lo, const int hi);

void shuffle(std::vector<int> &a);
void shuffle(std::vector<int> &a, const int lo, const int hi);

template <typename T> void shuffle(std::vector<T> &a);
template <typename T> void shuffle(std::vector<T> &a, const int lo, const int hi);

void shuffle(std::vector<char> &a);

std::vector<int> permuation(const int n);
std::vector<int> permuation(const int n, const int k);

template <typename T> void validateNotNull(const std::vector<T> &x);

void validateSubarrayIndices(int lo, int hi, int length);

}

}

#endif
