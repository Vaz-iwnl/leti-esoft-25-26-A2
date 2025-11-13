/* * FICHEIRO CORRIGIDO v3: ConsoleApp/sources/views/SpecifyVaccineTypeView.cpp
 */

#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>

// Includes para os headers
#include "views/SpecifyVaccineTypeView.h"
#include "domain/model/VaccineTechnology.h"

// Traz os namespaces para o scope
using namespace domain::model;
using namespace Core::Controller;

namespace ui {

    // Função auxiliar para selecionar a tecnologia
    VaccineTechnology selectTechnologyFromList() {
        std::cout << "\n--- Seleção de Tecnologia ---" << std::endl;
        std::cout << "1. mRNA" << std::endl;
        std::cout << "2. Inactivated" << std::endl;
        std::cout << "3. ViralVector" << std::endl;
        std::cout << "4. LiveAttenuated" << std::endl;
        std::cout << "5. Subunit" << std::endl;
        std::cout << "6. Toxoid" << std::endl;

        int choice = 0;
        std::cout << "Escolha uma tecnologia (1-6): ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: return VaccineTechnology::mRNA;
            case 2: return VaccineTechnology::Inactivated;
            case 3: return VaccineTechnology::ViralVector;
            case 4: return VaccineTechnology::LiveAttenuated;
            case 5: return VaccineTechnology::Subunit;
            case 6: return VaccineTechnology::Toxoid;
            default:
                std::cerr << "Escolha inválida, a usar 'Unknown' por defeito." << std::endl;
                return VaccineTechnology::Unknown;
        }
    }

    // Função principal da View
    void showSpecifyVaccineTypeView(const SpecifyVaccineTypeController& controller) {
        std::cout << "\n=============================================" << std::endl;
        std::cout << "   Especificar Novo Tipo de Vacina" << std::endl;
        std::cout << "=============================================\n" << std::endl;

        // --- CORREÇÃO: Adicionada a string 'disease' ---
        std::string code, disease, description;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Insira o código do tipo de vacina: ";
        std::getline(std::cin, code);

        // --- CORREÇÃO: Adicionada a pergunta para 'disease' ---
        std::cout << "Insira a doença (ex: COVID-19): ";
        std::getline(std::cin, disease);

        std::cout << "Insira a descrição: ";
        std::getline(std::cin, description);

        // Chama a função para obter o objeto de tecnologia
        VaccineTechnology techObject = selectTechnologyFromList();

        try {
            // --- CORREÇÃO: Chamada ao controlador com os 4 argumentos NA ORDEM CORRETA ---
            // (code, disease, description, techObject)
            controller.createVaccineType(code, disease, description, techObject);

            std::cout << "\n[SUCESSO] Tipo de vacina '" << description << "' registado com sucesso!" << std::endl;

        } catch (const std::exception& e) {
            std::cerr << "\n[ERRO] Nao foi possivel registar: " << e.what() << std::endl;
        }

        std::cout << "\n---------------------------------------------" << std::endl;
    }

} // fim do namespace ui