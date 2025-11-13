#include "domain/model/EmployeeService.h"
#include "domain/exceptions/DuplicateCodeException.h" // Vamos reutilizar esta exceção
#include <stdexcept> // Para std::invalid_argument

namespace application {

    // Atalhos para os namespaces
    using namespace domain::model;
    using namespace domain::exceptions;

    // Implementação do Construtor (guarda o container)
    EmployeeService::EmployeeService(std::unique_ptr<EmployeeContainer> container)
        : container_(std::move(container))
    {}

    // Implementação da Lógica de Negócio US14
    void EmployeeService::registerEmployee(const std::string& employeeId,
                                         const std::string& name,
                                         EmployeeRole role) const {

        // 1. REGRA DE NEGÓCIO: Verificar a Unicidade do ID
        if (container_->existsById(employeeId)) {
            // Reutilizamos a DuplicateCodeException
            throw DuplicateCodeException("Employee with ID '" + employeeId + "' already exists.");
        }

        // 2. CRIAÇÃO DO MODELO
        // O construtor do Employee já valida se os campos estão vazios
        auto newEmployee = std::make_unique<Employee>(employeeId, name, role);

        // 3. PERSISTÊNCIA
        // Delega a responsabilidade de ARMAZENAR para o Container
        container_->save(std::move(newEmployee));
    }

} // namespace application