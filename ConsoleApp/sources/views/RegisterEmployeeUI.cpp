#include "views/RegisterEmployeeUI.h"
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept> // Para std::exception

// Inclui os modelos de domínio necessários
#include "domain/model/EmployeeRole.h"

// Traz os namespaces para o scope para facilitar
using namespace domain::model;
using namespace Core::Controller;

// Implementação do Construtor
RegisterEmployeeUI::RegisterEmployeeUI(const RegisterEmployeeController& controller)
    : controller_(controller)
{
    // O controlador é guardado como membro
}

// Implementação do metodo principal 'run'
void RegisterEmployeeUI::run() {
    std::string employeeId, name;

    // Limpa o buffer de input (importante se vier de outro menu)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\n=============================================" << std::endl;
    std::cout << "     Registar Novo Funcionario (US 14)" << std::endl;
    std::cout << "=============================================\n" << std::endl;

    std::cout << "Insira o ID do funcionario (ex: 123456): ";
    std::getline(std::cin, employeeId);

    std::cout << "Insira o Nome do funcionario: ";
    std::getline(std::cin, name);

    // Chama a função auxiliar para mostrar o menu de seleção de Papel
    EmployeeRole chosenRole = selectRoleFromList();

    if (chosenRole == EmployeeRole::UNKNOWN) {
        std::cerr << "\n[ERRO] Selecao de papel invalida. A operacao foi cancelada." << std::endl;
        std::cout << "\n---------------------------------------------" << std::endl;
        return; // Termina a função mais cedo
    }
   
    try {
        // Tenta registar o funcionário chamando o controlador
        controller_.registerEmployee(employeeId, name, chosenRole);

        std::cout << "\n[SUCESSO] Funcionario '" << name << "' registado com sucesso!" << std::endl;

    } catch (const std::exception& e) {
        // Apanha erros do Serviço (ex: ID duplicado ou campos vazios)
        std::cerr << "\n[ERRO] Nao foi possivel registar: " << e.what() << std::endl;
    }

    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "\nPressione ENTER para continuar..." << std::endl;
    std::cin.get(); 
}


// Implementação da função auxiliar privada
EmployeeRole RegisterEmployeeUI::selectRoleFromList() {
    std::cout << "\n--- Selecione o Papel (Role) ---" << std::endl;
    std::cout << "1. Receptionist (Rececionista)" << std::endl;
    std::cout << "2. Nurse (Enfermeiro/a)" << std::endl;

    int choice = 0;
    std::cout << "Escolha um papel (1-2): ";
    std::cin >> choice;

    // Limpa o buffer de input
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    switch (choice) {
        case 1:
            return EmployeeRole::RECEPTIONIST;
        case 2:
            return EmployeeRole::NURSE;
        default:
            return EmployeeRole::UNKNOWN;
    }
}