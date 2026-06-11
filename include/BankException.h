#ifndef BANK_EXCEPTION_H
#define BANK_EXCEPTION_H

#include <exception>
#include <string>
using namespace std;

class BankException : public exception {
private:
    string message;

public:
    BankException(string msg);

    const char* what() const noexcept override;
};

#endif