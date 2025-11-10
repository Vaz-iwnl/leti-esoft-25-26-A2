#include "../../../headers/controllers/ui/SpecifyVaccineTypeController.h"
// Inclui o Service e Modelo, se necessário, mas o header já o faz.
#include "../../../headers/domain/model/VaccineTypeService.h"

namespace Core::Controller {

    // Construtor: Inicializa a referência ao serviço injetado
    SpecifyVaccineTypeController::SpecifyVaccineTypeController(application::VaccineTypeService &service)
        : service_(service)
    {
        // O Controller agora tem acesso ao método createVaccineType do Service.
    }

    // O método principal que o Controller expõe à View.
    void SpecifyVaccineTypeController::createVaccineType(std::string &code,
                                                         std::string &disease,
                                                         std::string &description,
                                                         domain::model::VaccineTechnology technology) const {

        // A responsabilidade do Controller é simplesmente DELEGAR a chamada.
        // Toda a lógica de negócio (AC10-1, validações) está no Service.

        // Chamada direta ao Service
        service_.createVaccineType(code, disease, description, technology);

        // Notas:
        // - Se o Service lançar uma exceção (e.g., DuplicateCodeException), o Controller
        //   não a trata, permitindo que a exceção seja propagada até à View para ser mostrada ao utilizador.
    }

} // namespace Core::Controller