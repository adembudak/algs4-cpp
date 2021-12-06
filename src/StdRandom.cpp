#include "algs4/StdRandom.h"

#include <vector>
#include <random>
#include <cmath>
#include <cassert>
#include <limits>
#include <stdexcept>

namespace algs4 {

namespace StdRandom {

constexpr auto PI = 3.141592653589793238462643383279502884L;

std::random_device rd;
std::mt19937 engine{rd()};

using int_distrib_t = std::uniform_int_distribution<int>;
using param_type_i = int_distrib_t::param_type;
int_distrib_t int_distrib;

using long_distrib_t = std::uniform_int_distribution<long>;
using param_type_l = long_distrib_t::param_type;
long_distrib_t long_distrib;

using double_distrib_t = std::uniform_real_distribution<double>;
double_distrib_t double_distrib;

constexpr int int_MAX = std::numeric_limits<int>::max();
constexpr int int_MIN = std::numeric_limits<int>::min();

long seed;

//////////////////////////////

void setSeed(const long s) {
    seed = s;
    engine.seed(s);
}

long getSeed() {
    return seed;
}

double uniform() {
    return double_distrib(engine);
}

int uniform(const int n) {
    if (n <= 0) std::domain_error("argument must be positive");
    return int_distrib(engine, param_type_i{0, n - 1});
}

long uniform(const long n) {
    if (n <= 0L) std::domain_error("argument must be positive");
    return long_distrib(engine, param_type_l{0, n - 1});
}

[[deprecated]] double random() {
    return uniform();
}

int uniform(const int a, const int b) {
    if ((b <= a) || ((long)b - a >= int_MAX)) {
        throw std::domain_error("invalid range: [" + std::to_string(a) + ", " + std::to_string(b) +
                                ")");
    }
    return a + uniform(b - a);
}

double uniform(const double a, const double b) {
    if (!(a < b)) {
        throw std::domain_error("invalid range: [" + std::to_string(a) + ", " + std::to_string(b) +
                                ")");
    }

    return a + uniform() * (b - a);
}

bool bernoulli(const double p) {
    if (!(p >= 0.0 && p <= 1.0))
        throw std::domain_error("probability p must be between 0.0 and 1.0: " + std::to_string(p));
    return uniform() < p;
}

bool bernoulli() {
    return bernoulli(0.5);
}

double gaussian() {
    double r, x, y;
    do {
        x = uniform(-1.0, 1.0);
        y = uniform(-1.0, 1.0);
        r = x * x + y * y;
    } while (r >= 1 || r == 0);
    return x * std::sqrt(-2 * std::log(r) / r);
}

double gaussian(const double mu, const double sigma) {
    return mu + sigma * gaussian();
}

int geometric(const double p) {
    if (!(p >= 0)) {
        throw std::domain_error("probability p must be greater than 0: " + std::to_string(p));
    }
    if (!(p <= 1.0)) {
        throw std::domain_error("probability p must not be larger than 1: " + std::to_string(p));
    }

    return (int)std::ceil(std::log(uniform()) / std::log(1.0 - p));
}

int poisson(const double lambda) {
    if (!(lambda > 0.0))
        throw std::domain_error("lambda must be positive: " + std::to_string(lambda));

    if (std::isinf(lambda))
        throw std::domain_error("lambda must not be infinite: " + std::to_string(lambda));

    // using algorithm given by Knuth
    // see http://en.wikipedia.org/wiki/Poisson_distribution
    int k = 0;
    double p = 1.0;
    double expLambda = std::exp(-lambda);
    do {
        k++;
        p *= uniform();
    } while (p >= expLambda);
    return k - 1;
}

double pareto() {
    return pareto(1.0);
}

double pareto(const double alpha) {
    if (!(alpha > 0.0)) {
        throw std::domain_error("alpha must be positive: " + std::to_string(alpha));
    }

    return std::pow(1 - uniform(), -1.0 / alpha) - 1.0;
}

double cauchy() {
    return std::tan(PI * (uniform() - 0.5));
}

int discrete(const std::vector<double> &probabilities) {
    if (probabilities.empty()) std::domain_error("argument array must not be null");

    const double EPSILON = 1.0E-14;
    double sum = 0.0;
    for (int i = 0; i < probabilities.size(); i++) {
        if (!(probabilities[i] >= 0.0))
            throw std::domain_error("array entry " + std::to_string(i) +
                                    " must be non-negative: " + std::to_string(probabilities[i]));
        sum += probabilities[i];
    }

    if (sum > 1.0 + EPSILON || sum < 1.0 - EPSILON)
        throw std::domain_error("sum of array entries does not approximately equal 1.0: " +
                                std::to_string(sum));

    while (true) {
        double r = uniform();
        sum = 0.0;
        for (int i = 0; i < probabilities.size(); i++) {
            sum = sum + probabilities[i];
            if (sum > r) return i;
        }
    }
}

int discrete(const std::vector<int> &frequencies) {
    if (frequencies.empty()) throw std::domain_error("argument array must not be null");

    long sum = 0;
    for (int i = 0; i < frequencies.size(); i++) {
        if (frequencies[i] < 0)
            throw std::domain_error("array entry " + std::to_string(i) +
                                    " must be non-negative: " + std::to_string(frequencies[i]));
        sum += frequencies[i];
    }

    if (sum == 0) throw std::domain_error("at least one array entry must be positive");
    if (sum >= int_MAX) throw std::domain_error("sum of frequencies overflows an int");

    // pick index i with probabilitity proportional to frequency
    double r = uniform((int)sum);
    sum = 0;
    for (int i = 0; i < frequencies.size(); i++) {
        sum += frequencies[i];
        if (sum > r) return i;
    }

    // can't reach here
    assert(false);
    return -1;
}

double exp(const double lambda) {
    if (!(lambda > 0.0))
        throw std::domain_error("lambda must be positive: " + std::to_string(lambda));

    return -std::log(1 - uniform()) / lambda;
}

void shuffle(std::vector<double> &a) {
    validateNotNull(a);
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int r = i + uniform(n - i);
        double temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }
}

void shuffle(std::vector<double> &a, const int lo, const int hi) {
    validateNotNull(a);
    validateSubarrayIndices(lo, hi, a.size());

    for (int i = lo; i < hi; i++) {
        int r = i + uniform(hi - i);
        double temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }
}

void shuffle(std::vector<int> &a) {
    validateNotNull(a);
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int r = i + uniform(n - i);
        int temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }
}

void shuffle(std::vector<int> &a, const int lo, const int hi) {
    validateNotNull(a);
    validateSubarrayIndices(lo, hi, a.size());

    for (int i = lo; i < hi; i++) {
        int r = i + uniform(hi - i);
        int temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }
}

template <typename T> void shuffle(std::vector<T> &a) {
    validateNotNull(a);

    int n = a.length;
    for (int i = 0; i < n; i++) {
        int r = i + uniform(n - i);
        auto temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }
}

template <typename T> void shuffle(std::vector<T> &a, const int lo, const int hi) {
    validateNotNull(a);
    validateSubarrayIndices(lo, hi, a.length);

    for (int i = lo; i < hi; i++) {
        int r = i + uniform(hi - i);
        auto temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }
}

void shuffle(std::vector<char> &a) {
    validateNotNull(a);
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int r = i + uniform(n - i);
        char temp = a[i];
        a[i] = a[r];
        a[r] = temp;
    }
}

std::vector<int> permutation(const int n) {
    if (n < 0) throw std::domain_error("n must be non-negative: " + std::to_string(n));

    std::vector<int> perm(n);
    for (int i = 0; i < n; i++)
        perm[i] = i;
    shuffle(perm);
    return perm;
}

std::vector<int> permutation(const int n, const int k) {
    if (n < 0) throw std::domain_error("n must be non-negative: " + std::to_string(n));
    if (k < 0 || k > n) throw std::domain_error("k must be between 0 and n: " + std::to_string(k));

    std::vector<int> perm(k);
    for (int i = 0; i < k; i++) {
        int r = uniform(i + 1); // between 0 and i
        perm[i] = perm[r];
        perm[r] = i;
    }
    for (int i = k; i < n; i++) {
        int r = uniform(i + 1); // between 0 and i
        if (r < k) perm[r] = i;
    }
    return perm;
}

template <typename T> void validateNotNull(const std::vector<T> &x) {
    if (x.empty()) {
        throw std::domain_error("argument must not be null");
    }
}

void validateSubarrayIndices(int lo, int hi, int length) {
    if (lo < 0 || hi > length || lo > hi) {
        throw std::domain_error("subarray indices out of bounds: [" + std::to_string(lo) + ", " +
                                std::to_string(hi) + ")");
    }
}

}
}
