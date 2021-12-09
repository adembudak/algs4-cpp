#include <algs4/Transaction.h>
#include <functional> // std::hash<>()
#include <cmath>
#include <stdexcept>

namespace algs4 {
Transaction::Transaction(const std::string &who, const Date &when, const double amount) {

    if (std::isnan(amount) || std::isinf(amount)) {
        throw std::invalid_argument("Amount cannot be NaN or infinite");
    }

    m_who = who, m_when = when, m_amount = amount;
}

std::string Transaction::who() const {
    return m_who;
}

Date Transaction::when() const {
    return m_when;
}

double Transaction::amount() const {
    return m_amount;
}

int Transaction::operator<(const Transaction &that) const {
    if (m_amount < that.amount()) return -1;
    if (m_amount > that.amount()) return 1;
    return 0;
}

bool Transaction::operator==(const Transaction &that) const {
    return (m_amount == that.amount()) && (m_who == that.who()) && (m_when == that.when());
}

int Transaction::hashCode() const {
    int hash = 1;
    hash = 31 * hash + std::hash<std::string>{}(m_who);
    hash = 31 * hash + m_when.hashCode();
    hash = 31 * hash + std::hash<double>{}(m_amount);
    return hash;
}

Transaction::operator std::string() const {
    return m_who + ' ' + std::string(m_when) + ' ' + std::to_string(m_amount);
}

bool WhoOrder(const Transaction &left, const Transaction &right) {
    return left.who() < right.who();
}

bool WhenOrder(const Transaction &left, const Transaction &right) {
    return (left.when() < right.when()) < 0;
}

bool HowMuchOrder(const Transaction &left, const Transaction &right) {
    return left.amount() < right.amount();
}

}
