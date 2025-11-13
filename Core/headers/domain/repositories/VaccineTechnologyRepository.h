//
// Created by jvaz on 15/10/2023.
//

#ifndef VACCINETECHNOLOGYREPOSITORY_H
#define VACCINETECHNOLOGYREPOSITORY_H

#include <vector>
#include <string>
#include "../model/VaccineTechnology.h" // <-- Este include já traz a definição correta

namespace domain {
    namespace repositories {

        class VaccineTechnologyRepository {
        public:
            virtual ~VaccineTechnologyRepository() = default;

            /* --- CORREÇÃO ---
             * A definição duplicada do 'enum class' foi removida daqui.
             * O include na linha 11 já define o 'enum' que precisamos.
             */

            // O metodo getAll() deve usar o tipo que foi importado
            virtual std::vector<model::VaccineTechnology> getAll() const = 0;
        };

    } // namespace repositories
} // namespace domain

#endif //VACCINETECHNOLOGYREPOSITORY_H