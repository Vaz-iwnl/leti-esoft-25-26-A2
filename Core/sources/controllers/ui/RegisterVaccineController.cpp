#include "../../../headers/controllers/ui/RegisterVaccineController.h"

namespace Core {
    namespace Controller {

        RegisterVaccineController::RegisterVaccineController(application::VaccineService& service)
            : service_(service)
        {}

        void RegisterVaccineController::registerVaccine(const std::string& name,
                                                      const std::string& brand,
                                                      domain::model::VaccineTechnology technology) const {
            
            // O Controlador apenas delega a chamada para o Serviço
            service_.registerVaccine(name, brand, technology);
        }

    } // namespace Controller
} // namespace Core