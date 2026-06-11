#include "CurrentAccount.h"
#include <sstream>

CurrentAccount::CurrentAccount(int id, string name, double bal, double overdraft)
    : Account(id, name, bal) {
    overdraftLimit = overdraft;
}

void CurrentAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw BankException("Withdraw amount must be greater than 0.");
    }

    if (amount > balance + overdraftLimit) {
        throw BankException("Withdrawal failed. Amount exceeds balance and overdraft limit.");
    }

    balance -= amount;
}

void CurrentAccount::displayAccount() const {
    cout << "\n--- Current Account ---" << endl;
    cout << "Customer ID      : " << customerId << endl;
    cout << "Customer Name    : " << customerName << endl;
    cout << "Balance          : " << balance << endl;
    cout << "Overdraft Limit  : " << overdraftLimit << endl;
}

string CurrentAccount::getAccountType() const {
    return "Current";
}

string CurrentAccount::toFileString() const {
    stringstream ss;

    ss << "Current" << "|"
       << customerId << "|"
       << customerName << "|"
       << balance << "|"
       << overdraftLimit;

    return ss.str();
}