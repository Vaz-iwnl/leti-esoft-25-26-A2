#ifndef RESULT_H
#define RESULT_H

#include <string>
// using namespace std; REMOVIDO para evitar poluição do namespace global

class Result {
private:
    int result;
    std::wstring resultMsg; // std:: adicionado

    Result(const int result, const std::wstring &message);

public:
    int getResult() const; // Removido 'const' do tipo de retorno (redundante para tipos primitivos)
    const std::wstring& getMessage() const; // Retorno por referência constante para eficiência
    bool isOK() const;
    bool isNOK() const;
    bool operator == (const Result& other) const;

    // Removido 'const' do tipo de retorno para permitir otimizações de move/copy
    static Result OK();
    static Result OK(const std::wstring &message);
    static Result NOK(const std::wstring &message);
    static Result NOK(int number, const std::wstring &message);
};

#endif //RESULT_H