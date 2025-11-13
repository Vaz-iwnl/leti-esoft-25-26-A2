#ifndef REGISTER_EMPLOYEE_UI_H
#define REGISTER_EMPLOYEE_UI_H

// Inclui o Controlador que esta View irá utilizar
#include "controllers/ui/RegisterEmployeeController.h"

// Esta é a DECLARAÇÃO da classe.
class RegisterEmployeeUI {
public:
    // Construtor que recebe o controlador por Injeção de Dependência
    explicit RegisterEmployeeUI(const Core::Controller::RegisterEmployeeController& controller);

    // O metodo principal que executa a UI
    void run();

private:
    // Referência para o controlador
    const Core::Controller::RegisterEmployeeController& controller_;

    // Função auxiliar privada para mostrar o menu de seleção de Papel (Role)
    domain::model::EmployeeRole selectRoleFromList();
};

#endif // REGISTER_EMPLOYEE_UI_H