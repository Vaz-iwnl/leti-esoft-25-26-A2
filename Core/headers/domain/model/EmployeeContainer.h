#ifndef EMPLOYEE_CONTAINER_H
#define EMPLOYEE_CONTAINER_H

#include "Employee.h" // Inclui o domain::model::Employee
#include <string>
#include <memory>

namespace domain {
    namespace model {

        // Interface (Contrato) para o repositório de Funcionários
        class EmployeeContainer {
        public:
            virtual ~EmployeeContainer() = default;

            // Verifica se um funcionário com este ID já existe (para validação)
            [[nodiscard]] virtual bool existsById(const std::string& employeeId) const = 0;

            // Guarda um novo funcionário
            virtual void save(std::unique_ptr<Employee> employee) = 0;
        };

    } // namespace model
} // namespace domain

#endif //EMPLOYEE_CONTAINER_H