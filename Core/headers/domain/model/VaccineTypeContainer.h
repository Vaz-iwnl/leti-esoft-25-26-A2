#ifndef VACCINE_TYPE_CONTAINER_H
#define VACCINE_TYPE_CONTAINER_H

#include "VaccineType.h"
#include <string>
#include <memory>

namespace domain::container {

    /**
     * @brief Interface (Contrato) para a Camada de Persistência (Repository) de VaccineType.
     * @details O seu colega de grupo implementará esta interface.
     */
    class VaccineTypeContainer {
    public:
        virtual ~VaccineTypeContainer() = default;
        [[nodiscard]] virtual bool existsByCode(const std::string& code) const = 0; // Para AC10-1
        virtual void save(std::unique_ptr<model::VaccineType> vaccineType) = 0;
    };

} // namespace domain::container

#endif // VACCINE_TYPE_CONTAINER_H