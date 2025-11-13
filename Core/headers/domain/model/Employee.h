#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "EmployeeRole.h"

namespace domain {
    namespace model {

        class Employee {
        private:
            std::string employeeId;
            std::string name;
            EmployeeRole role;

        public:
            // Construtor para criar um novo funcionário
            Employee(const std::string& employeeId, const std::string& name, EmployeeRole role);

            // Getters
            std::string getEmployeeId() const;
            std::string getName() const;
            EmployeeRole getRole() const;
        };

    } // namespace model
} // namespace domain

#endif //EMPLOYEE_H