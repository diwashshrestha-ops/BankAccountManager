#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include "BankException.h"

using namespace std;

class Account {
protected:
    int customerId;
    string customerName;
    double balance;

public:
    Account(int id, string name, double bal);

    virtual ~Account();

    int getCustomerId() const;
    string getCustomerName() const;
    double getBalance() const;

    void deposit(double amount);

    virtual void withdraw(double amount) = 0;
    virtual void displayAccount() const = 0;
    virtual string getAccountType() const = 0;
    virtual string toFileString() const = 0;
};

#endif