#include "../../../headers/domain/container/VaccineInMemoryContainer.h"

namespace domain {
    namespace container {

        // --- CORREÇÃO: Usar o nome completo do tipo ---
        void VaccineInMemoryContainer::save(std::unique_ptr<model::Vaccine> vaccine) {
            if (vaccine) {
                vaccines_.push_back(std::move(vaccine));
            }
        }

    } // namespace container
} // namespace domain