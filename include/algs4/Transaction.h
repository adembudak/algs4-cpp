#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <algs4/Date.h>
#include <string>

namespace algs4 {

class Transaction {
  private:
    std::string m_who;
    Date m_when;
    double m_amount;

  public:
    Transaction() = default;
    Transaction(const std::string &who, const Date &when, const double amount);

    std::string who() const;
    Date when() const;
    double amount() const;

    int operator<(const Transaction &that) const;
    bool operator==(const Transaction &that) const;

    int hashCode() const;
    operator std::string() const;
};

bool WhoOrder(const Transaction &left, const Transaction &right);
bool WhenOrder(const Transaction &left, const Transaction &right);
bool HowMuchOrder(const Transaction &left, const Transaction &right);

}

#endif
