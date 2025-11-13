#include "../../../headers/domain/model/VaccineService.h"
#include <stdexcept> // Para std::invalid_argument

namespace application {

    using namespace domain::model;

    VaccineService::VaccineService(std::unique_ptr<VaccineContainer> container)
        : container_(std::move(container))
    {}

    // Implementação da Lógica de Negócio US11
    void VaccineService::registerVaccine(const std::string& name,
                                         const std::string& brand,
                                         VaccineTechnology technology) const {
        
        // 1. VALIDAÇÃO (Regra de negócio simples: não pode ser vazio)
        if (name.empty() || brand.empty()) {
            throw std::invalid_argument("Vaccine Name and Brand cannot be empty.");
        }

        // 2. CRIAÇÃO DO MODELO
        auto newVaccine = std::make_unique<Vaccine>(name, brand, technology);

        // 3. PERSISTÊNCIA
        container_->save(std::move(newVaccine));
    }

} // namespace application