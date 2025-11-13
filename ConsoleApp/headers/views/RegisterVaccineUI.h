#ifndef REGISTER_VACCINE_UI_H
#define REGISTER_VACCINE_UI_H

// --- ADICIONE ESTE INCLUDE ---
#include "controllers/ui/RegisterVaccineController.h"

// Esta é a DECLARAÇÃO da classe.
class RegisterVaccineUI {
public:
    // --- CORREÇÃO: O construtor agora recebe o Controller ---
    explicit RegisterVaccineUI(const Core::Controller::RegisterVaccineController& controller);
    void run();

private:
    // --- ADICIONE ESTA LINHA ---
    const Core::Controller::RegisterVaccineController& controller_;
};

#endif // REGISTER_VACCINE_UI_H