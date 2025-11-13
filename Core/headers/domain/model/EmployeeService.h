#ifndef EMPLOYEE_SERVICE_H
#define EMPLOYEE_SERVICE_H

#include "Employee.h"
#include "EmployeeContainer.h"
#include "EmployeeRole.h"
#include <string>
#include <memory>

// O Serviço fica no namespace 'application' (lógica de aplicação)
namespace application {

    // Atalho para o namespace do modelo
    using namespace domain::model;

    class EmployeeService {
    public:
        // Injeção de Dependência do repositório (Container)
        explicit EmployeeService(std::unique_ptr<EmployeeContainer> container);

        // Metodo principal da US14
        void registerEmployee(const std::string& employeeId,
                              const std::string& name,
                              EmployeeRole role) const;

    private:
        std::unique_ptr<EmployeeContainer> container_;
    };

} // namespace application

#endif //EMPLOYEE_SERVICE_H