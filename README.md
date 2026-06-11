# Bank Account Manager

## Project Description

Bank Account Manager is a CLI-based banking system developed in C++ for the OOP II final project.

The system allows users to:

- Create a bank account
- Choose Savings Account or Current Account
- Deposit money
- Withdraw money
- Check balance
- View customer account details
- View all accounts
- Save and reload account data using a file

Each customer has one account type only.

Example:


Customer ID 1 -> Savings Account
Customer ID 2 -> Current Account


---

## Features

- Create account
- Deposit money
- Withdraw money
- Check balance
- Check customer account
- View all accounts
- Save account data to file
- Load account data when the program starts
- Handle errors using custom exception handling

---

## OOP Concepts Used

### Classes and Objects

Main classes used:

- Account
- SavingsAccount
- CurrentAccount
- BankManager
- BankException

---

### Encapsulation

Customer ID, customer name, and balance are stored inside the Account class.

They are accessed using functions such as:


getCustomerId()
getCustomerName()
getBalance()
deposit()
withdraw()

### Inheritance

SavingsAccount and CurrentAccount inherit from the Account base class.


class SavingsAccount : public Account
class CurrentAccount : public Account

### Abstraction

Account is an abstract class because it has pure virtual functions:


virtual void withdraw(double amount) = 0;
virtual void displayAccount() const = 0;
virtual string getAccountType() const = 0;
virtual string toFileString() const = 0;

---

### Runtime Polymorphism

Runtime polymorphism is used through:


vector<unique_ptr<Account>> accounts;

This allows the program to store both SavingsAccount and CurrentAccount objects in one list.

Example:


account->withdraw(amount);


At runtime, C++ decides whether to call:


SavingsAccount::withdraw()


or:
CurrentAccount::withdraw()

### Custom Exception Handling

The project uses a custom exception class named BankException.

It handles errors such as:

- Customer not found
- Invalid deposit amount
- Invalid withdrawal amount
- Savings minimum balance error
- Current account overdraft limit error

---

### File Input/Output

Account data is saved and loaded from:

txt
data/accounts.txt

Example saved data:

txt
Savings|1|Dipesh|1000|3.5|500
Current|2|Ram|2000|1000

---

## Folder Structure

txt
BankAccountManager/
├── app/
│   └── main.cpp
│
├── include/
│   ├── BankException.h
│   ├── Account.h
│   ├── SavingsAccount.h
│   ├── CurrentAccount.h
│   └── BankManager.h
│
├── source/
│   ├── BankException.cpp
│   ├── Account.cpp
│   ├── SavingsAccount.cpp
│   ├── CurrentAccount.cpp
│   └── BankManager.cpp
│
├── data/
│   └── accounts.txt
│
├── run.bat
└── README.md

---

## Build and Run Instructions

Open terminal in the main project folder:

txt
BankAccountManager>

Compile the project:

g++ app\main.cpp source\BankException.cpp source\Account.cpp source\SavingsAccount.cpp source\CurrentAccount.cpp source\BankManager.cpp -Iinclude -o bank.exe

Run the program:

.\bank.exe

---

## Easy Run Using run.bat

Create a file named:

txt
run.bat

Paste this inside:

bat
g++ app\main.cpp source\BankException.cpp source\Account.cpp source\SavingsAccount.cpp source\CurrentAccount.cpp source\BankManager.cpp -Iinclude -o bank.exe
bank.exe
pause

Then run:
.\run.bat


or double-click run.bat.

## Program Menu

========== Bank Account Manager ==========
1. Create Account
2. Deposit Money
3. Withdraw Money
4. Check Balance
5. Check Customer Account
6. View All Accounts
7. Save and Exit
Choose an option:

## How to Reset Data

To start again from Customer ID 1:

1. Open data/accounts.txt
2. Delete everything inside it
3. Save the empty file
4. Run the program again
