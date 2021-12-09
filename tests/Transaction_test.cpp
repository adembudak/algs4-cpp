#include <algs4/Transaction.h>
#include <algs4/StdOut.h>

#include <vector>
#include <string>
#include <algorithm>

int main() {
    using namespace algs4;
    using namespace std::string_literals;
    std::vector<Transaction> a(4);

    a[0] = Transaction("Turing"s, Date("6/17/1990"), 644.08);
    a[1] = Transaction("Tarjan"s, Date("3/26/2002"), 4121.85);
    a[2] = Transaction("Knuth"s, Date("6/14/1999"), 288.34);
    a[3] = Transaction("Dijkstra"s, Date("8/22/2007"), 2678.40);

    StdOut::println("Unsorted");
    for (int i = 0; i < a.size(); i++)
        StdOut::println(a[i]);
    StdOut::println();

    StdOut::println("Sort by date");
    std::sort(a.begin(), a.end(), WhenOrder);
    for (int i = 0; i < a.size(); i++)
        StdOut::println(a[i]);
    StdOut::println();

    StdOut::println("Sort by customer");
    std::sort(a.begin(), a.end(), WhoOrder);
    for (int i = 0; i < a.size(); i++)
        StdOut::println(a[i]);
    StdOut::println();

    StdOut::println("Sort by amount");
    std::sort(a.begin(), a.end(), HowMuchOrder);
    for (int i = 0; i < a.size(); i++)
        StdOut::println(a[i]);
    StdOut::println();

    return 0;
}
