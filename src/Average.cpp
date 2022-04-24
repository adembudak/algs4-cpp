#include "algs4/StdIn.h"
#include "algs4/StdOut.h"

int main() {
    using namespace algs4;

    int count = 0;
    double sum = 0.0;

    while (!StdIn::isEmpty()) {
        double value = StdIn::readDouble();
        sum += value;
        count++;
    }

    // compute the average
    double average = sum / count;

    // print results
    StdOut::println("Average is " + std::to_string(average));
}
