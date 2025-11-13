#ifndef VACCINE_IN_MEMORY_CONTAINER_H
#define VACCINE_IN_MEMORY_CONTAINER_H

#include "../model/VaccineContainer.h"
#include <vector>
#include <memory>

// --- CORREÇÃO: A classe Vaccine já não é necessária aqui ---
// #include "../model/Vaccine.h" // O VaccineContainer.h já inclui isto

namespace domain {
    namespace container {

        class VaccineInMemoryContainer : public model::VaccineContainer {
        public:
            VaccineInMemoryContainer() = default;
            ~VaccineInMemoryContainer() override = default;

            // --- CORREÇÃO: Usar o nome completo do tipo (para bater com a interface) ---
            void save(std::unique_ptr<model::Vaccine> vaccine) override;

        private:
            // --- CORREÇÃO: Usar o nome completo do tipo ---
            std::vector<std::unique_ptr<model::Vaccine>> vaccines_;
        };

    } // namespace container
} // namespace domain

#endif //VACCINE_IN_MEMORY_CONTAINER_H