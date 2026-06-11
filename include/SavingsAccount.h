#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int id, string name, double bal, double rate, double minBal);

    void withdraw(double amount) override;
    void displayAccount() const override;
    string getAccountType() const override;
    string toFileString() const override;
};

#endif