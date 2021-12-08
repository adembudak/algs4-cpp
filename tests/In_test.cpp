#include <algs4/In.h>

#include <string>
#include <iostream>
#include <stdexcept>

int main() {
    using namespace algs4;

    In in("file");

    std::string urlName = "https://introcs.cs.princeton.edu/java/stdlib/InTest.txt";
    std::cout << "readAll() from URL " + urlName;
    std::cout << "---------------------------------------------------------------------------\n";

    try {
        in = urlName;
        std::cout << in.readAll();
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << '\n';
    }

    std::cout << '\n';

    // read one line at a time from URL
    std::cout << "readLine() from URL " + urlName;
    std::cout << "---------------------------------------------------------------------------\n";
    try {
        in = In(urlName);
        while (!in.isEmpty()) {
            std::string s = in.readLine();
            std::cout << s << '\n';
        }
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << '\n';
    }
    std::cout << '\n';

    // read one string at a time from URL
    std::cout << "readString() from URL " + urlName;
    std::cout << "---------------------------------------------------------------------------\n";
    try {
        in = In(urlName);
        while (!in.isEmpty()) {
            std::string s = in.readString();
            std::cout << s << '\n';
        }
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << '\n';
    }
    std::cout << '\n';

    // read one line at a time from file in current directory
    std::cout << "readLine() from current directory";
    std::cout << "---------------------------------------------------------------------------\n";
    try {
        in = In("./InTest.txt");
        while (!in.isEmpty()) {
            std::string s = in.readLine();
            std::cout << s << '\n';
        }
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << '\n';
    }
    std::cout << '\n';

    // read one line at a time from file using relative path
    std::cout << "readLine() from relative path";
    std::cout << "---------------------------------------------------------------------------\n";
    try {
        in = In("../stdlib/InTest.txt");
        while (!in.isEmpty()) {
            std::string s = in.readLine();
            std::cout << s << '\n';
        }
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << '\n';
    }
    std::cout << '\n';

    // read one char at a time
    std::cout << "readChar() from file";
    std::cout << "---------------------------------------------------------------------------\n";
    try {
        in = In("InTest.txt");
        while (!in.isEmpty()) {
            char c = in.readChar();
            std::cout << c;
        }
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << '\n';
    }
    std::cout << '\n';

    // read one line at a time from absolute OS X / Linux path
    std::cout << "readLine() from absolute OS X / Linux path";
    std::cout << "---------------------------------------------------------------------------\n";
    try {
        in = In("/n/fs/introcs/www/java/stdlib/InTest.txt");
        while (!in.isEmpty()) {
            std::string s = in.readLine();
            std::cout << s << '\n';
        }
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << '\n';
    }
    std::cout << '\n';

    // read one line at a time from absolute Windows path
    std::cout << "readLine() from absolute Windows path\n";
    std::cout << "---------------------------------------------------------------------------\n";
    try {
        in = In("G:\\www\\introcs\\stdlib\\InTest.txt");
        while (!in.isEmpty()) {
            std::string s = in.readLine();
            std::cout << s << '\n';
        }
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << '\n';
    }
    std::cout << '\n';
}
