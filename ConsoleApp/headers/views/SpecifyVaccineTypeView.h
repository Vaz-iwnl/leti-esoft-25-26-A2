#ifndef SPECIFY_VACCINE_TYPE_VIEW_H
#define SPECIFY_VACCINE_TYPE_VIEW_H


#include "headers/controllers/ui/SpecifyVaccineTypeController.h"
#include "headers/domain/model/VaccineType.h"
#include "headers/domain/model/VaccineTechnology.h" # o pq deste erro tbm


namespace application {
    class VaccineTypeService;
}

namespace ui {

    void showSpecifyVaccineTypeView(const Core::Controller::SpecifyVaccineTypeController &controller);


    domain::model::VaccineTechnology selectTechnologyFromList();

}

#endif // SPECIFY_VACCINE_TYPE_VIEW_H