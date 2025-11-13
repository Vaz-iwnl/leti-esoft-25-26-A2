#include <stdexcept>
#include "domain/shared/Result.h"

Result::Result(const int result, const std::wstring &message) {
    this->result = result;
    this->resultMsg = message;
}

int Result::getResult() const {
    return this->result;
}

const std::wstring& Result::getMessage() const { // Alterado para retornar por referência constante
    return this->resultMsg;
}

bool Result::operator==(const Result &other) const {
    if (&other == this) return true;
    return (this->result == other.result);
}

bool Result::isOK() const {
    return (this->result == 0);
}

bool Result::isNOK() const {
    return !this->isOK();
}

Result Result::OK() { // Removido 'const'
    return Result(0,L"");
}

Result Result::OK(const std::wstring &message) { // Removido 'const'
    return Result(0,message);
}

Result Result::NOK(const std::wstring &message) { // Removido 'const'
    return Result(-1,message);
}

Result Result::NOK(int number, const std::wstring &message) { // Removido 'const'
    if (number != 0)
        return Result(number, message);
    throw std::invalid_argument("A NOK result cannot have a 'zero' error number.");
}