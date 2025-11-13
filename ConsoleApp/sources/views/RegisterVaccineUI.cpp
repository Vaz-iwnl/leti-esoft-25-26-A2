#ifndef REGISTER_VACCINE_UI_H
#define REGISTER_VACCINE_UI_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>

// Incluir os ficheiros headers
#include "../../../Core/headers/domain/model/Vaccine.h"
#include "../../../Core/headers/domain/model/VaccineTechnology.h"
#include "../../../Core/headers/domain/repositories/VaccineTechnologyRepository.h"

// O ecrã da consola (UI) para o Administrador.

class RegisterVaccineUI {
private:
    VaccineTechnologyRepository techRepo;

public:
    void run() {
        std::string name, brand;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "=======================================" << std::endl;
        std::cout << "      Registar Nova Vacina (US 11)     " << std::endl;
        std::cout << "=======================================" << std::endl;

        std::cout << "Nome Comercial: ";
        std::getline(std::cin, name);
        std::cout << "Marca (Fabricante): ";
        std::getline(std::cin, brand);

        std::cout << "\n--- Selecione a Tecnologia (AC11-1) ---" << std::endl;

        auto availableTechnologies = techRepo.getAllTechnologies();

        for (size_t i = 0; i < availableTechnologies.size(); ++i) {
            std::cout << (i + 1) << ". " << availableTechnologies[i]->getName() << std::endl;
        }

        int selection = 0;
        std::shared_ptr<VaccineTechnology> chosenTechnology = nullptr;

        while (chosenTechnology == nullptr) {
            std::cout << "\nInsira a sua opcao (1-" << availableTechnologies.size() << "): ";

            if (!(std::cin >> selection) || selection < 1 || selection > availableTechnologies.size()) {
                std::cout << "Erro: Opcao invalida. Tente novamente." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                chosenTechnology = availableTechnologies[selection - 1];
            }
        }
        try {
            Vaccine newVaccine(name, brand, chosenTechnology);


            std::cout << "\n--- SUCESSO! ---" << std::endl;
            std::cout << "Vacina '" << newVaccine.getCommercialName() << "' registada." << std::endl;
            std::cout << "Tecnologia: " << newVaccine.getTechnology()->getName() << std::endl;

        } catch (const std::exception& e) {
            std::cout << "\nErro ao registar a vacina: " << e.what() << std::endl;
        }

        std::cout << "\nPressione ENTER para continuar..." << std::endl;
        std::cin.get();
    }
};

#endif // REGISTER_VACCINE_UI_H