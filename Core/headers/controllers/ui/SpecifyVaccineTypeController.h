#ifndef SPECIFY_VACCINE_TYPE_CONTROLLER_H
#define SPECIFY_VACCINE_TYPE_CONTROLLER_H

#include "../../../headers/domain/model/VaccineTypeService.h"
#include "../../../headers/domain/model/VaccineType.h"       // Inclui o Modelo
#include <string>

namespace Core::Controller {

    class SpecifyVaccineTypeController {
    public:
        explicit SpecifyVaccineTypeController(application::VaccineTypeService &service);

        void createVaccineType(std::string &code,
                               std::string &disease,
                               std::string &description,
                               domain::model::VaccineTechnology technology) const;

    private:
        application::VaccineTypeService& service_;
    };

}

#endif // SPECIFY_VACCINE_TYPE_CONTROLLER_H