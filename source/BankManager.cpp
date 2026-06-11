#include "BankManager.h"

BankManager::BankManager() {
    nextCustomerId = 1;
}

void BankManager::loadFromFile() {
    ifstream file("data/accounts.txt");

    if (!file) {
        return;
    }

    accounts.clear();

    string line;

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);

        string type;
        string idText;
        string name;
        string balanceText;

        getline(ss, type, '|');
        getline(ss, idText, '|');
        getline(ss, name, '|');
        getline(ss, balanceText, '|');

        int customerId = stoi(idText);
        double balance = stod(balanceText);

        if (type == "Savings") {
            string rateText;
            string minBalanceText;

            getline(ss, rateText, '|');
            getline(ss, minBalanceText, '|');

            double interestRate = stod(rateText);
            double minimumBalance = stod(minBalanceText);

            accounts.push_back(make_unique<SavingsAccount>(
                customerId,
                name,
                balance,
                interestRate,
                minimumBalance
            ));
        }
        else if (type == "Current") {
            string overdraftText;

            getline(ss, overdraftText, '|');

            double overdraftLimit = stod(overdraftText);

            accounts.push_back(make_unique<CurrentAccount>(
                customerId,
                name,
                balance,
                overdraftLimit
            ));
        }

        if (customerId >= nextCustomerId) {
            nextCustomerId = customerId + 1;
        }
    }

    file.close();
}

void BankManager::saveToFile() const {
    ofstream file("data/accounts.txt");

    if (!file) {
        cout << "Error: Could not save data to file." << endl;
        return;
    }

    for (const auto& account : accounts) {
        file << account->toFileString() << endl;
    }

    file.close();
}

Account* BankManager::findCustomer(int customerId) {
    for (auto& account : accounts) {
        if (account->getCustomerId() == customerId) {
            return account.get();
        }
    }

    return nullptr;
}

void BankManager::createAccount(string name, int accountChoice, double initialBalance) {
    if (accountChoice == 1) {
        if (initialBalance < 500) {
            throw BankException("Savings account requires minimum initial balance of 500.");
        }

        accounts.push_back(make_unique<SavingsAccount>(
            nextCustomerId,
            name,
            initialBalance,
            3.5,
            500.0
        ));

        cout << "\nSavings account created successfully." << endl;
        cout << "Customer ID: " << nextCustomerId << endl;

        nextCustomerId++;
    }
    else if (accountChoice == 2) {
        if (initialBalance < 0) {
            throw BankException("Initial balance cannot be negative.");
        }

        accounts.push_back(make_unique<CurrentAccount>(
            nextCustomerId,
            name,
            initialBalance,
            1000.0
        ));

        cout << "\nCurrent account created successfully." << endl;
        cout << "Customer ID: " << nextCustomerId << endl;

        nextCustomerId++;
    }
    else {
        throw BankException("Invalid account type.");
    }
}

void BankManager::depositMoney(int customerId, double amount) {
    Account* account = findCustomer(customerId);

    if (account == nullptr) {
        throw BankException("Customer not found.");
    }

    account->deposit(amount);

    cout << "\nDeposit successful." << endl;
    cout << "New Balance: " << account->getBalance() << endl;
}

void BankManager::withdrawMoney(int customerId, double amount) {
    Account* account = findCustomer(customerId);

    if (account == nullptr) {
        throw BankException("Customer not found.");
    }

    account->withdraw(amount);

    cout << "\nWithdrawal successful." << endl;
    cout << "New Balance: " << account->getBalance() << endl;
}

void BankManager::checkBalance(int customerId) {
    Account* account = findCustomer(customerId);

    if (account == nullptr) {
        throw BankException("Customer not found.");
    }

    cout << "\n--- Balance Information ---" << endl;
    cout << "Customer ID   : " << account->getCustomerId() << endl;
    cout << "Customer Name : " << account->getCustomerName() << endl;
    cout << "Account Type  : " << account->getAccountType() << endl;
    cout << "Balance       : " << account->getBalance() << endl;
}

void BankManager::checkCustomerAccount(int customerId) {
    Account* account = findCustomer(customerId);

    if (account == nullptr) {
        throw BankException("Customer not found.");
    }

    account->displayAccount();
}

void BankManager::viewAllAccounts() {
    if (accounts.empty()) {
        cout << "No accounts available." << endl;
        return;
    }

    cout << "\n========== All Accounts ==========" << endl;

    for (const auto& account : accounts) {
        account->displayAccount();
    }
}