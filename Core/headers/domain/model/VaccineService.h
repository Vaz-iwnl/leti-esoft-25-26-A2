#ifndef VACCINE_SERVICE_H
#define VACCINE_SERVICE_H

#include "Vaccine.h"
#include "VaccineContainer.h"
#include "VaccineTechnology.h"
#include <string>
#include <memory>

namespace application {

    class VaccineService {
    public:
        // Injeção de Dependência do nosso novo container
        explicit VaccineService(std::unique_ptr<domain::model::VaccineContainer> container);

        // Metodo principal da US11
        void registerVaccine(const std::string& name,
                             const std::string& brand,
                             domain::model::VaccineTechnology technology) const;

    private:
        std::unique_ptr<domain::model::VaccineContainer> container_;
    };

} // namespace application

#endif //VACCINE_SERVICE_H