#ifndef DATE_H
#define DATE_H

#include <string>

namespace algs4 {

class Date {
  private:
    int DAYS[13]{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int m_month;
    int m_day;
    int m_year;

  public:
    Date(const int month, const int day, const int year);
    Date(const std::string &date);

    int month() const;
    int day() const;
    int year() const;

    bool isValid(const int m, const int d, const int y) const;
    bool isLeapYear(const int y) const;

    Date next() const;
    // bool isAfter() const;
    bool isAfter(const Date &that) const;
    bool isBefore(const Date &that) const;

    operator std::string() const;
    int operator<(const Date &that) const;
    bool operator==(const Date &that) const;

    int hashCode() const;
};

}

#endif
