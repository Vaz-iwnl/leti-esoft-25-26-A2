#ifndef REGISTER_VACCINE_CONTROLLER_H
#define REGISTER_VACCINE_CONTROLLER_H

#include "domain/model/VaccineService.h"
#include "domain/model/VaccineTechnology.h"
#include <string>

namespace Core {
    namespace Controller {

        class RegisterVaccineController {
        public:
            // Injeção de Dependência do nosso novo serviço
            explicit RegisterVaccineController(application::VaccineService& service);

            // Delega a chamada para o serviço
            void registerVaccine(const std::string& name,
                                 const std::string& brand,
                                 domain::model::VaccineTechnology technology) const;

        private:
            application::VaccineService& service_;
        };

    } // namespace Controller
} // namespace Core

#endif //REGISTER_VACCINE_CONTROLLER_H