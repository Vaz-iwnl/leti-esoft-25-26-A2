#include "domain/model/Employee.h"
#include <stdexcept> // Para std::invalid_argument

namespace domain {
    namespace model {

        // Implementação do Construtor
        Employee::Employee(const std::string& employeeId, const std::string& name, EmployeeRole role)
            : employeeId(employeeId), name(name), role(role)
        {
            // Regra de Negócio: ID e Nome não podem ser vazios
            if (employeeId.empty() || name.empty()) {
                throw std::invalid_argument("Employee ID and Name cannot be empty.");
            }
        }

        // Implementação dos Getters
        std::string Employee::getEmployeeId() const {
            return employeeId;
        }

        std::string Employee::getName() const {
            return name;
        }

        EmployeeRole Employee::getRole() const {
            return role;
        }

    } // namespace model
} // namespace domain