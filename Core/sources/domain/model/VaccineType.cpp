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

        if (code_.empty() || disease_.empty() || description_.empty()) {
            throw std::invalid_argument("Code, Disease, and Description cannot be empty.");
        }
    }

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