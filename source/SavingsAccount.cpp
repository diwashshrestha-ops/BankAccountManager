#include "SavingsAccount.h"
#include <sstream>

SavingsAccount::SavingsAccount(int id, string name, double bal, double rate, double minBal)
    : Account(id, name, bal) {
    interestRate = rate;
    minimumBalance = minBal;
}

void SavingsAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw BankException("Withdraw amount must be greater than 0.");
    }

    if (balance - amount < minimumBalance) {
        throw BankException("Withdrawal failed. Savings account must keep minimum balance of 500.");
    }

    balance -= amount;
}

void SavingsAccount::displayAccount() const {
    cout << "\n--- Savings Account ---" << endl;
    cout << "Customer ID      : " << customerId << endl;
    cout << "Customer Name    : " << customerName << endl;
    cout << "Balance          : " << balance << endl;
    cout << "Interest Rate    : " << interestRate << "%" << endl;
    cout << "Minimum Balance  : " << minimumBalance << endl;
}

string SavingsAccount::getAccountType() const {
    return "Savings";
}

string SavingsAccount::toFileString() const {
    stringstream ss;

    ss << "Savings" << "|"
       << customerId << "|"
       << customerName << "|"
       << balance << "|"
       << interestRate << "|"
       << minimumBalance;

    return ss.str();
}