#include "algs4/Out.h"
#include <fstream>

int main() {
    using namespace algs4;

    Out consoleOut;

    consoleOut.println();
    consoleOut.println(false);
    consoleOut.println('c');
    consoleOut.println(123.123123123123);
    consoleOut.println(123.123123);
    consoleOut.println(123);
    consoleOut.println(1234567890);
    consoleOut.println(123);

    consoleOut.print();
    consoleOut.print(false);
    consoleOut.print('c');
    consoleOut.print(123.123123123123);
    consoleOut.print(123.123123);
    consoleOut.print(123);
    consoleOut.print(1234567890);
    consoleOut.print(123);

    std::ofstream fout{"Out_test.out"};
    Out fileOut(fout);

    fileOut.println();
    fileOut.println(false);
    fileOut.println('c');
    fileOut.println(123.123123123123);
    fileOut.println(123.123123);
    fileOut.println(123);
    fileOut.println(1234567890);
    fileOut.println(123);

    fileOut.print();
    fileOut.print(false);
    fileOut.print('c');
    fileOut.print(123.123123123123);
    fileOut.print(123.123123);
    fileOut.print(123);
    fileOut.print(1234567890);
    fileOut.print(123);

    return 0;
}
