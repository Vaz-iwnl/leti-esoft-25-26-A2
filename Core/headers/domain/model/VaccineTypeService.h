#ifndef VACCINE_TYPE_SERVICE_H
#define VACCINE_TYPE_SERVICE_H

#include "VaccineType.h"
#include "VaccineTypeContainer.h"
#include <string>
#include <memory>


namespace application {

    class VaccineTypeService {
    public:
        // Injeção de Dependência
        explicit VaccineTypeService(std::unique_ptr<domain::container::VaccineTypeContainer> container);

        void createVaccineType(std::string& code,
                               std::string& disease,
                               std::string& description,
                               domain::model::VaccineTechnology technology) const;

    private:
        std::unique_ptr<domain::container::VaccineTypeContainer> container_;
    };

} // namespace application

#endif // VACCINE_TYPE_SERVICE_H