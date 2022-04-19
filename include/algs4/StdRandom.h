#ifndef STDRANDOM_H
#define STDRANDOM_H

#include <vector>
#include <cstddef>
#include <stdexcept>

namespace algs4 {

namespace StdRandom {

template <typename T>
void validateNotNull(const std::vector<T> &x) {
    if (x.empty()) {
        throw std::domain_error("argument must not be empty");
    }
}

void setSeed(const unsigned long s);
unsigned long getSeed();

double uniform();
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

template <typename T>
void shuffle(std::vector<T> &a) {
    validateNotNull(a);

    auto n = a.size();
    for (int i = 0; i < n; i++) {
        int r = i + uniform(n - i);
        auto temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }
}

template <typename T>
void shuffle(std::vector<T> &a, const std::size_t lo, const std::size_t hi) {
    validateNotNull(a);
    validateSubarrayIndices(lo, hi, a.size());

    for (std::size_t i = lo; i < hi; i++) {
        int r = i + uniform(int(hi - i));
        auto temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }
}

std::vector<int> permuation(const int n);
std::vector<int> permuation(const int n, const int k);
void validateSubarrayIndices(int lo, int hi, int length);

}

}

#endif
