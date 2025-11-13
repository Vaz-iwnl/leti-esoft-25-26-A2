#ifndef DUPLICATE_CODE_EXCEPTION_H
#define DUPLICATE_CODE_EXCEPTION_H

#include <stdexcept>
#include <string>

namespace domain::exceptions {

    /**
     * @brief Exceção lançada quando a regra de unicidade do código (AC10-1) é violada.
     * * Herda de std::runtime_error, apropriado para erros de lógica de negócio em tempo de execução.
     */
    class DuplicateCodeException : public std::runtime_error {
    public:
        // Construtor que recebe a mensagem de erro (e.g., "Code XXX já existe.")
        // e passa-a para o construtor da classe base (std::runtime_error).
        DuplicateCodeException(const std::string& msg)
            : std::runtime_error(msg) {}
    };

} // namespace domain::exceptions

#endif // DUPLICATE_CODE_EXCEPTION_H