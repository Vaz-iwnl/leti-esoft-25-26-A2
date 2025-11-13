//
// Created by jvaz on 13/10/2023.
//

#ifndef VACCINE_TYPE_H
#define VACCINE_TYPE_H

#include <string> // <-- HEADER EM FALTA
#include "VaccineTechnology.h"

namespace domain {
    namespace model {

        class VaccineType {
        private:
            // --- CORREÇÃO: Adicionadas as variáveis de membro ---
            std::string code_;
            std::string description_;
            std::string disease_; // <-- Esta variável também estava em falta
            VaccineTechnology technology_;

        public:
            // --- CORREÇÃO: Assinatura correta (com std:: e 3 strings) ---
            VaccineType(const std::string& code, const std::string& disease, const std::string& description, VaccineTechnology technology);

            // --- CORREÇÃO: std::string ---
            std::string getCode() const;
            std::string getDescription() const;
            std::string getDisease() const; // <-- Este getter estava em falta
            VaccineTechnology getTechnology() const;
        };

    } // namespace model
} // namespace domain

#endif //VACCINE_TYPE_H