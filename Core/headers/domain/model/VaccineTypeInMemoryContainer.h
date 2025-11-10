#ifndef VACCINE_TYPE_IN_MEMORY_CONTAINER_H
#define VACCINE_TYPE_IN_MEMORY_CONTAINER_H

#include "../../domain/model/VaccineTypeContainer.h"
#include <vector>
#include <memory>


namespace domain::container {

    /**
     * @brief Implementação em memória do Container de VaccineType
     * @details Armazena os tipos de vacina em um vector para persistência temporária
     */
    class VaccineTypeInMemoryContainer : public VaccineTypeContainer {
    public:
        VaccineTypeInMemoryContainer() = default;
        ~VaccineTypeInMemoryContainer() override = default;

        [[nodiscard]] bool existsByCode(const std::string& code) const override;
        void save(std::unique_ptr<model::VaccineType> vaccineType) override;

        // Método auxiliar para listar todos (útil para testes/debug)
        [[nodiscard]] const std::vector<std::unique_ptr<model::VaccineType>>& getAll() const;

    private:
        std::vector<std::unique_ptr<model::VaccineType>> vaccineTypes_;
    };

} // namespace domain::container

#endif // VACCINE_TYPE_IN_MEMORY_CONTAINER_H