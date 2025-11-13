#ifndef EMPLOYEE_IN_MEMORY_CONTAINER_H
#define EMPLOYEE_IN_MEMORY_CONTAINER_H

#include "../model/EmployeeContainer.h"
#include <vector>
#include <memory>

// Nota: O Employee.h já é incluído pelo EmployeeContainer.h

namespace domain {
    namespace container {

        // Implementação "em memória" da interface
        class EmployeeInMemoryContainer : public model::EmployeeContainer {
        public:
            EmployeeInMemoryContainer() = default;
            ~EmployeeInMemoryContainer() override = default;

            // Implementa os métodos da interface
            [[nodiscard]] bool existsById(const std::string& employeeId) const override;
            void save(std::unique_ptr<model::Employee> employee) override;

        private:
            // O nosso "armazenamento" em memória
            std::vector<std::unique_ptr<model::Employee>> employees_;
        };

    } // namespace container
} // namespace domain

#endif //EMPLOYEE_IN_MEMORY_CONTAINER_H