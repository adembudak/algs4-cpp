#include "algs4/Date.h"
#include "algs4/StdOut.h"

int main() {
    using namespace algs4;

    Date today(2, 25, 2004);
    StdOut::println(today);

    for (int i = 0; i < 10; i++) {
        today = today.next();
        StdOut::println(today);
    }

    StdOut::println(today.isAfter(today.next()));
    StdOut::println(today.isAfter(today));
    StdOut::println(today.next().isAfter(today));

    Date birthday(10, 16, 1971);
    StdOut::println(birthday);
    for (int i = 0; i < 10; i++) {
        birthday = birthday.next();
        StdOut::println(birthday);
    }
}
