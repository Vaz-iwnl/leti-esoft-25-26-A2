#include "../../../headers/domain/model/VaccineType.h"
#include <stdexcept>

namespace domain::model {

    // Construtor
    VaccineType::VaccineType(const std::string& code,
                             const std::string& disease,
                             const std::string& description,
                             VaccineTechnology technology)
        : code_(code), disease_(disease), description_(description), technology_(technology)
    {
        // Aqui você pode adicionar lógica de validação básica, como verificar se as strings não estão vazias
        if (code_.empty() || disease_.empty() || description_.empty()) {
            throw std::invalid_argument("Code, Disease, and Description cannot be empty.");
        }
        // Nota: A validação do formato do código e a unicidade devem ser tratadas em um nível superior.
    }

    // Implementações dos Getters
    std::string VaccineType::getCode() const {
        return code_;
    }

    std::string VaccineType::getDisease() const {
        return disease_;
    }

    std::string VaccineType::getDescription() const {
        return description_;
    }

    VaccineTechnology VaccineType::getTechnology() const {
        return technology_;
    }

} // namespace domain::model