#ifndef REGISTER_EMPLOYEE_CONTROLLER_H
#define REGISTER_EMPLOYEE_CONTROLLER_H

#include "domain/model/EmployeeService.h" // Inclui o Serviço
#include "domain/model/EmployeeRole.h"   // Inclui o Enum
#include <string>

// Usamos o namespace Core::Controller para os controladores de UI
namespace Core {
    namespace Controller {

        // Atalho para o namespace da aplicação
        using application::EmployeeService;

        class RegisterEmployeeController {
        public:
            // Injeção de Dependência do Serviço
            explicit RegisterEmployeeController(EmployeeService& service);

            // Metodo que a View irá chamar
            void registerEmployee(const std::string& employeeId,
                                  const std::string& name,
                                  domain::model::EmployeeRole role) const;

        private:
            // Referência para o serviço
            EmployeeService& service_;
        };

    } // namespace Controller
} // namespace Core

#endif //REGISTER_EMPLOYEE_CONTROLLER_H