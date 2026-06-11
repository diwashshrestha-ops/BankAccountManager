#include "Account.h"

Account::Account(int id, string name, double bal) {
    customerId = id;
    customerName = name;
    balance = bal;
}

Account::~Account() {
}

int Account::getCustomerId() const {
    return customerId;
}

string Account::getCustomerName() const {
    return customerName;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    if (amount <= 0) {
        throw BankException("Deposit amount must be greater than 0.");
    }

    balance += amount;
}