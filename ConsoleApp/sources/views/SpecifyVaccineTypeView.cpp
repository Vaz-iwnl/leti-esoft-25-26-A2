#include <iostream>
#include <memory>
#include "../../headers/views/SpecifyVaccineTypeView.h"
#include "../../../Core/headers/domain/model/VaccineTypeInMemoryContainer.h"
#include "../../../Core/headers/domain/model/VaccineTypeService.h"
#include "../../../Core/headers/controllers/ui/SpecifyVaccineTypeController.h"

int main() {
    std::cout << "==================================================" << std::endl;
    std::cout << "  Sistema de Gestão de Vacinação Pandémica (PVMS)" << std::endl;
    std::cout << "  DGS - Direção Geral de Saúde" << std::endl;
    std::cout << "==================================================" << std::endl;

    try {
        // 1. Instancia o Container (Repositório em Memória)
        auto container = std::make_unique<domain::container::VaccineTypeInMemoryContainer>();

        // 2. Instancia o Service, injetando o Container
        auto service = std::make_unique<application::VaccineTypeService>(std::move(container));

        // 3. Instancia o Controller, injetando o Service
        Core::Controller::SpecifyVaccineTypeController controller(*service);

        // 4. Inicia a View
        ui::showSpecifyVaccineTypeView(controller);

    } catch (const std::exception& e) {
        std::cerr << "\nERRO CRÍTICO no sistema: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\n\nPressione Enter para sair...";
    std::cin.get();

    return 0;
}