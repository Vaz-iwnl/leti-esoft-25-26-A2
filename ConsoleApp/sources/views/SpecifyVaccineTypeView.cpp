#include "headers/views/SpecifyVaccineTypeView.h"

#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>

namespace ui {

    void showSpecifyVaccineTypeView(const Core::Controller::SpecifyVaccineTypeController& controller) {

        std::cout << "\n=============================================" << std::endl;
        std::cout << "   Especificar Novo Tipo de Vacina" << std::endl;
        std::cout << "=============================================\n" << std::endl;

        std::string code, description, technology;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Insira o código do tipo de vacina: ";
        std::getline(std::cin, code);

        std::cout << "Insira a descrição: ";
        std::getline(std::cin, description);

        std::cout << "Insira a tecnologia (ex: mRNA, Inactivated): ";
        std::getline(std::cin, technology);

        try {
            //controller.vaccineTecnology(code, description, technology); # o pq do erro

            std::cout << "\n[SUCESSO] Tipo de vacina '" << description << "' registado com sucesso!" << std::endl;

        } catch (const std::exception& e) {
            std::cerr << "\n[ERRO] Nao foi possivel registar: " << e.what() << std::endl;
        }

        std::cout << "\n---------------------------------------------" << std::endl;
    }

    domain::model::VaccineTechnology selectTechnologyFromList() {

        std::cout << "\n--- Seleção de Tecnologia ---" << std::endl;
        std::cout << "1. mRNA" << std::endl;
        std::cout << "2. Inactivated Virus" << std::endl;
        std::cout << "3. Vector" << std::endl;

        int choice = 0;
        std::cout << "Escolha uma tecnologia (1-3): ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

       /* switch (choice) {
            case 1:
                return domain::model::VaccineTechnology(1, "mRNA");
            case 2:
                return domain::model::VaccineTechnology(2, "Inactivated Virus");
            case 3:
                return domain::model::VaccineTechnology (3, "Vector");
            default:
                std::cerr << "Escolha inválida, a usar 'Desconhecida' por defeito." << std::endl;
                return domain::model::VaccineTechnology (99, "Desconhecida");}*/

    }

} // fim do namespace ui