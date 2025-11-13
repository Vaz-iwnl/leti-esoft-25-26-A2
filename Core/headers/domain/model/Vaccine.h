#ifndef VACCINE_H
#define VACCINE_H

#include <string>
#include <memory>
#include "VaccineTechnology.h" // Este já está correto

// --- CORREÇÃO: Colocar a classe DENTRO do namespace ---
namespace domain {
    namespace model {

        class Vaccine {
        private:
            std::string name;
            std::string brand;
            VaccineTechnology technology; // O enum já está no mesmo namespace

        public:
            Vaccine(const std::string& name, const std::string& brand, VaccineTechnology tech)
                : name(name), brand(brand), technology(tech) {}

            std::string getName() const { return name; }
            std::string getBrand() const { return brand; }
            VaccineTechnology getTechnology() const { return technology; }
        };

    } // namespace model
} // namespace domain

#endif //VACCINE_H