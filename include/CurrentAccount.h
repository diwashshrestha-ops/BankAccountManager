#ifndef CURRENT_ACCOUNT_H
#define CURRENT_ACCOUNT_H

#include "Account.h"

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(int id, string name, double bal, double overdraft);

    void withdraw(double amount) override;
    void displayAccount() const override;
    string getAccountType() const override;
    string toFileString() const override;
};

#endif