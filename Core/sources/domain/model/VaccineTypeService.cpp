#include "../../../headers/domain/model/VaccineTypeService.h"
#include "../../../headers/domain/exceptions/DuplicateCodeException.h"
#include "../../../headers/domain/model/VaccineTypeContainer.h"

namespace application {

    using namespace domain::exceptions;
    using namespace domain::model;

    VaccineTypeService::VaccineTypeService(std::unique_ptr<domain::container::VaccineTypeContainer> container)
        : container_(std::move(container))
    {}

    // Implementação da Lógica de Negócio US10
    void VaccineTypeService::createVaccineType(std::string& code,
                                               std::string& disease,
                                               std::string& description,
                                               VaccineTechnology technology) const {

        // 1. REGRA DE NEGÓCIO AC10-1: Verificar a Unicidade do Código
        if (container_->existsByCode(code)) {
            // Lança a exceção específica
            throw DuplicateCodeException("Vaccine Type with code '" + code + "' already exists. Code must be unique.");
        }

        // 2. CRIAÇÃO DO MODELO E VALIDAÇÃO BÁSICA
        // O construtor do VaccineType irá lançar std::invalid_argument se os campos forem vazios.
        auto newVaccineType = std::make_unique<VaccineType>(code, disease, description, technology);

        // 3. PERSISTÊNCIA: Delega a responsabilidade de ARMAZENAR para o Container
        container_->save(std::move(newVaccineType));
    }

} // namespace application