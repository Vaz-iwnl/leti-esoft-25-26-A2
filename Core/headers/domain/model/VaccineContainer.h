#ifndef VACCINE_CONTAINER_H
#define VACCINE_CONTAINER_H

#include "Vaccine.h" // Este header agora define domain::model::Vaccine
#include <string>
#include <memory>

namespace domain {
    namespace model {

        class VaccineContainer {
        public:
            virtual ~VaccineContainer() = default;

            // --- CORREÇÃO: Usar o nome completo do tipo ---
            virtual void save(std::unique_ptr<domain::model::Vaccine> vaccine) = 0;
        };

    } // namespace model
} // namespace domain

#endif //VACCINE_CONTAINER_H