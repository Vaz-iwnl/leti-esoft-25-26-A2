#ifndef SPECIFY_VACCINE_TYPE_VIEW_H
#define SPECIFY_VACCINE_TYPE_VIEW_H


#include "controllers/ui/SpecifyVaccineTypeController.h"
#include "domain/model/VaccineType.h"
#include "domain/model/VaccineTechnology.h"


namespace application {
    class VaccineTypeService;
}

namespace ui {

    void showSpecifyVaccineTypeView(const Core::Controller::SpecifyVaccineTypeController &controller);


    domain::model::VaccineTechnology selectTechnologyFromList();

}

#endif // SPECIFY_VACCINE_TYPE_VIEW_H