#ifndef BANK_MANAGER_H
#define BANK_MANAGER_H

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>

#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include "BankException.h"

using namespace std;

class BankManager {
private:
    vector<unique_ptr<Account>> accounts;
    int nextCustomerId;

public:
    BankManager();

    void loadFromFile();
    void saveToFile() const;

    Account* findCustomer(int customerId);

    void createAccount(string name, int accountChoice, double initialBalance);
    void depositMoney(int customerId, double amount);
    void withdrawMoney(int customerId, double amount);
    void checkBalance(int customerId);
    void checkCustomerAccount(int customerId);
    void viewAllAccounts();
};

#endif