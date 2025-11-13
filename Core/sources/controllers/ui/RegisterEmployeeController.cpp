#include "controllers/ui/RegisterEmployeeController.h"

namespace Core {
    namespace Controller {

        // Implementação do Construtor
        RegisterEmployeeController::RegisterEmployeeController(EmployeeService& service)
            : service_(service)
        {}

        // Implementação do metodo principal
        void RegisterEmployeeController::registerEmployee(const std::string& employeeId,
                                                      const std::string& name,
                                                      domain::model::EmployeeRole role) const {
            
            // O Controlador não tem lógica; apenas delega a chamada para o Serviço.
            // O Serviço tratará da validação e do armazenamento.
            service_.registerEmployee(employeeId, name, role);
        }

    } // namespace Controller
} // namespace Core