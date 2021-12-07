#include "algs4/Date.h"
#include <stdexcept>

namespace algs4 {

Date::Date(const int month, const int day, const int year) {
    if (!isValid(month, day, year)) throw std::invalid_argument("Invalid date");
    m_month = month;
    m_day = day;
    m_year = year;
}

int Date::month() const {
    return m_month;
}

int Date::day() const {
    return m_day;
}

int Date::year() const {
    return m_year;
}

bool Date::isValid(const int m, const int d, const int y) const {
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > DAYS[m]) return false;
    if (m == 2 && d == 29 && !isLeapYear(y)) return false;
    return true;
}

bool Date::isLeapYear(const int y) const {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return y % 4 == 0;
}

Date Date::next() const {
    if (isValid(m_month, m_day + 1, m_year)) return Date(m_month, m_day + 1, m_year);
    else if (isValid(m_month + 1, 1, m_year)) return Date(m_month + 1, 1, m_year);
    else return Date(1, 1, m_year + 1);
}

bool Date::isAfter(const Date &that) const {
    return (*this < that) > 0;
}

bool Date::isBefore(const Date &that) const {
    return (*this < that) < 0;
}

Date::operator std::string() const {
    return std::to_string(m_month) + "/" + std::to_string(m_day) + "/" + std::to_string(m_year);
}

int Date::operator<(const Date &that) const {
    // clang-format off
    if (m_year  < that.year())  return -1;
    if (m_year  > that.year())  return +1;
    if (m_month < that.month()) return -1;
    if (m_month > that.month()) return +1;
    if (m_day   < that.day())   return -1;
    if (m_day   > that.day())   return +1;
    return 0;
    // clang-format on
}

bool Date::operator==(const Date &that) const {
    return (m_month == that.month()) && (m_day == that.day()) && (m_year == that.year());
}

int Date::hashCode() const {
    return m_day + 31 * m_month + 31 * 12 * m_year;
}

}
