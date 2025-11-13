#include "../../../headers/domain/container/EmployeeInMemoryContainer.h"
#include <algorithm> // Para std::any_of

namespace domain {
    namespace container {

        // Atalho para o nome da classe
        using model::Employee;

        // Implementação do metodo existsById
        bool EmployeeInMemoryContainer::existsById(const std::string& employeeId) const {
            // Procura no vetor se algum funcionário tem o ID correspondente
            return std::any_of(employees_.begin(), employees_.end(),
                [&employeeId](const std::unique_ptr<Employee>& emp) {
                    return emp->getEmployeeId() == employeeId;
                });
        }

        // Implementação do metodo save
        void EmployeeInMemoryContainer::save(std::unique_ptr<Employee> employee) {
            if (employee) {
                employees_.push_back(std::move(employee));
            }
        }

    } // namespace container
} // namespace domain