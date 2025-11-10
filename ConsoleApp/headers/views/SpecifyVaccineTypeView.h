#ifndef SPECIFY_VACCINE_TYPE_VIEW_H
#define SPECIFY_VACCINE_TYPE_VIEW_H


#include "../../../Core/headers/domain/model/VaccineType.h"
#include "../../../Core/headers/controllers/ui/SpecifyVaccineTypeController.h"

namespace application {
    class VaccineTypeService;
}

namespace ui {

    void showSpecifyVaccineTypeView(const Core::Controller::SpecifyVaccineTypeController &controller);


    domain::model::VaccineTechnology selectTechnologyFromList();

}

#endif // SPECIFY_VACCINE_TYPE_VIEW_H