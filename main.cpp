#include <iostream>
#include <string>
#include <limits>
#include <memory> // Necessário para std::make_unique

// --- Includes para a US10 (Especificar Tipo de Vacina) ---
#include "domain/container/VaccineTypeInMemoryContainer.h"
#include "domain/model/VaccineTypeService.h"
#include "controllers/ui/SpecifyVaccineTypeController.h"
#include "views/SpecifyVaccineTypeView.h"

// --- Includes para a US11 (Registar Nova Vacina) ---
#include "domain/container/VaccineInMemoryContainer.h"
#include "domain/model/VaccineService.h"
#include "controllers/ui/RegisterVaccineController.h"
#include "views/RegisterVaccineUI.h" // O .h que criámos no último passo

// Traz os namespaces para o scope
using namespace domain::container;
using namespace application;
using namespace Core::Controller;
using namespace ui; // Para a US10
// Nota: RegisterVaccineUI é uma classe, por isso não está no namespace ui

int main() {
    std::wcout.imbue(std::locale("")); // Suporte para caracteres especiais
    std::cout.imbue(std::locale("")); // Suporte para caracteres especiais

    std::cout << "==================================================" << std::endl;
    std::cout << "  Sistema de Gestao de Vacinacao Pandemica (PVMS)" << std::endl;
    std::cout << "  DGS - Direcao Geral de Saude" << std::endl;
    std::cout << "==================================================" << std::endl;


    // --- Bloco de Injeção de Dependência (DI) ---
    // Onde "ligamos" todas as peças

    // 1. Dependências para US10
    auto vaccineTypeContainer = std::make_unique<VaccineTypeInMemoryContainer>();
    VaccineTypeService vaccineTypeService(std::move(vaccineTypeContainer));
    SpecifyVaccineTypeController specVaccineTypeController(vaccineTypeService);

    // 2. Dependências para US11
    auto vaccineContainer = std::make_unique<VaccineInMemoryContainer>();
    VaccineService vaccineService(std::move(vaccineContainer));
    RegisterVaccineController regVaccineController(vaccineService);
    RegisterVaccineUI registerVaccineView(regVaccineController); // A View recebe o Controller


    // --- Menu Principal Simples ---
    // (Podes melhorar isto depois)

    std::cout << "\n--- MENU ---" << std::endl;
    std::cout << "1. Especificar Novo Tipo de Vacina (US10)" << std::endl;
    std::cout << "2. Registar Nova Vacina (US11)" << std::endl;
    std::cout << "Escolha uma opcao: ";

    int choice = 0;
    std::cin >> choice;

    if (choice == 1) {
        // Chama a US10
        showSpecifyVaccineTypeView(specVaccineTypeController);
    } else if (choice == 2) {
        // Chama a US11
        registerVaccineView.run();
    } else {
        std::cout << "Opcao invalida." << std::endl;
    }

    std::cout << "\nPressione Enter para sair..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}