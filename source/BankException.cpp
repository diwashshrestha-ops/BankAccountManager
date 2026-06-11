#include "BankException.h"

BankException::BankException(string msg) {
    message = msg;
}

const char* BankException::what() const noexcept {
    return message.c_str();
}