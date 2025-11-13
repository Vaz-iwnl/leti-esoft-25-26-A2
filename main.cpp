#include <iostream>
#include <string>
#include <limits>
#include <memory>    // Necessário para std::make_unique
#include <locale>    // Necessário para std::locale

// --- Includes para a US10 (Especificar Tipo de Vacina) ---
#include "domain/container/VaccineTypeInMemoryContainer.h"
#include "domain/model/VaccineTypeService.h"
#include "controllers/ui/SpecifyVaccineTypeController.h"
#include "views/SpecifyVaccineTypeView.h"

// --- Includes para a US11 (Registar Nova Vacina) ---
#include "domain/container/VaccineInMemoryContainer.h"
#include "domain/model/VaccineService.h"
#include "controllers/ui/RegisterVaccineController.h"
#include "views/RegisterVaccineUI.h"

// --- INCLUDES PARA A US14 (Registar Novo Funcionário) ---
#include "domain/container/EmployeeInMemoryContainer.h"
#include "domain/model/EmployeeService.h"
#include "controllers/ui/RegisterEmployeeController.h"
#include "views/RegisterEmployeeUI.h"


// Traz os namespaces para o scope
using namespace domain::container;
using namespace application;
using namespace Core::Controller;
using namespace ui; // Para a US10 (showSpecifyVaccineTypeView)


int main() {
    // Configura o output para suportar caracteres especiais (acentos)
    std::wcout.imbue(std::locale(""));
    std::cout.imbue(std::locale(""));

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
    RegisterVaccineUI registerVaccineView(regVaccineController);

    // 3. Dependências para US14
    auto employeeContainer = std::make_unique<EmployeeInMemoryContainer>();
    EmployeeService employeeService(std::move(employeeContainer));
    RegisterEmployeeController regEmployeeController(employeeService);
    RegisterEmployeeUI registerEmployeeView(regEmployeeController);


    // --- Menu Principal ---

    int choice = 0;
    do {
        std::cout << "\n--- MENU PRINCIPAL ---" << std::endl;
        std::cout << "1. Especificar Novo Tipo de Vacina (US10)" << std::endl;
        std::cout << "2. Registar Nova Vacina (US11)" << std::endl;
        std::cout << "3. Registar Novo Funcionario (US14)" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Escolha uma opcao: ";

        std::cin >> choice;

        // Limpa o buffer de input
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1; // Força opção inválida
        }

        switch(choice) {
            case 1:
                showSpecifyVaccineTypeView(specVaccineTypeController);
                break;
            case 2:
                registerVaccineView.run();
                break;
            case 3:
                registerEmployeeView.run();
                break;
            case 0:
                std::cout << "A sair do programa..." << std::endl;
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
                break;
        }

    } while (choice != 0);


    std::cout << "\nPressione Enter para sair..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}