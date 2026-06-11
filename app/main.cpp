#include <iostream>
#include <limits>
#include "BankManager.h"
#include "BankException.h"

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void showAccountTypeMenu() {
    cout << "\nChoose account type:" << endl;
    cout << "1. Savings Account" << endl;
    cout << "2. Current Account" << endl;
    cout << "Enter choice: ";
}

void showMenu() {
    cout << "\n========== Bank Account Manager ==========" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Check Customer Account" << endl;
    cout << "6. View All Accounts" << endl;
    cout << "7. Save and Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    BankManager bank;
    bank.loadFromFile();

    int choice;

    do {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            clearInput();
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        try {
            if (choice == 1) {
                string name;
                int accountChoice;
                double initialBalance;

                clearInput();

                cout << "Enter customer name: ";
                getline(cin, name);

                showAccountTypeMenu();
                cin >> accountChoice;

                cout << "Enter initial balance: ";
                cin >> initialBalance;

                bank.createAccount(name, accountChoice, initialBalance);
                bank.saveToFile();
            }
            else if (choice == 2) {
                int customerId;
                double amount;

                cout << "Enter customer ID: ";
                cin >> customerId;

                cout << "Enter deposit amount: ";
                cin >> amount;

                bank.depositMoney(customerId, amount);
                bank.saveToFile();
            }
            else if (choice == 3) {
                int customerId;
                double amount;

                cout << "Enter customer ID: ";
                cin >> customerId;

                cout << "Enter withdraw amount: ";
                cin >> amount;

                bank.withdrawMoney(customerId, amount);
                bank.saveToFile();
            }
            else if (choice == 4) {
                int customerId;

                cout << "Enter customer ID: ";
                cin >> customerId;

                bank.checkBalance(customerId);
            }
            else if (choice == 5) {
                int customerId;

                cout << "Enter customer ID: ";
                cin >> customerId;

                bank.checkCustomerAccount(customerId);
            }
            else if (choice == 6) {
                bank.viewAllAccounts();
            }
            else if (choice == 7) {
                bank.saveToFile();
                cout << "\nData saved successfully." << endl;
                cout << "Thank you for using Bank Account Manager." << endl;
            }
            else {
                cout << "Invalid choice. Please choose between 1 and 7." << endl;
            }
        }
        catch (BankException& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (exception& e) {
            cout << "Unexpected Error: " << e.what() << endl;
        }

    } while (choice != 7);

    return 0;
}