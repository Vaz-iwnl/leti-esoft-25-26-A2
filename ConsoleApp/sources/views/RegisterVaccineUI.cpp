#include "views/RegisterVaccineUI.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>
#include <stdexcept> // Para std::exception

// Includes para os modelos de domínio
#include "domain/model/Vaccine.h"
#include "domain/model/VaccineTechnology.h"

// Traz os tipos para o scope
using namespace domain::model;
using namespace Core::Controller;

// --- CORREÇÃO: Implementação do Construtor ---
RegisterVaccineUI::RegisterVaccineUI(const RegisterVaccineController& controller)
    : controller_(controller)
{
    // O controlador é guardado como membro
}

// Implementação do metodo run
void RegisterVaccineUI::run() {
    std::string name, brand;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "=======================================" << std::endl;
    std::cout << "      Registar Nova Vacina (US 11)     " << std::endl;
    std::cout << "=======================================" << std::endl;

    std::cout << "Nome Comercial: ";
    std::getline(std::cin, name);
    std::cout << "Marca (Fabricante): ";
    std::getline(std::cin, brand);

    std::cout << "\n--- Selecione a Tecnologia ---" << std::endl;
    std::cout << "1. mRNA" << std::endl;
    std::cout << "2. Inactivated" << std::endl;
    std::cout << "3. ViralVector" << std::endl;
    // ... (podes adicionar os outros)
    std::cout << "6. Toxoid" << std::endl;

    int selection = 0;
    VaccineTechnology chosenTechnology = VaccineTechnology::Unknown;

    std::cout << "\nInsira a sua opcao (1-6): ";
    std::cin >> selection;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch(selection) {
        case 1: chosenTechnology = VaccineTechnology::mRNA; break;
        case 2: chosenTechnology = VaccineTechnology::Inactivated; break;
        case 3: chosenTechnology = VaccineTechnology::ViralVector; break;
        case 4: chosenTechnology = VaccineTechnology::LiveAttenuated; break;
        case 5: chosenTechnology = VaccineTechnology::Subunit; break;
        case 6: chosenTechnology = VaccineTechnology::Toxoid; break;
        default: chosenTechnology = VaccineTechnology::Unknown; break;
    }

    try {
        // --- CORREÇÃO: Chamar o controlador! ---
        controller_.registerVaccine(name, brand, chosenTechnology);

        std::cout << "\n[SUCESSO] Vacina '" << name << "' registada com sucesso!" << std::endl;

    } catch (const std::exception& e) {
        // Apanha erros do Serviço (ex: nome vazio)
        std::cout << "\n[ERRO] Nao foi possivel registar: " << e.what() << std::endl;
    }

    std::cout << "\nPressione ENTER para continuar..." << std::endl;
    std::cin.get();
}