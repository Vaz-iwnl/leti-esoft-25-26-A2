//create by João Vaz 1240908
#ifndef VACCINE_H
#define VACCINE_H

#include <string>
#include <memory>
#include "VaccineTechnology.h" // Inclui o ficheiro do Passo 1

// Modelo de Domínio da Vacina

class Vaccine {
private:
    std::string commercialName;
    std::string brand;

    std::shared_ptr<VaccineTechnology> technology;

public:
    Vaccine(const std::string& name, const std::string& brand, std::shared_ptr<VaccineTechnology> tech)
        : commercialName(name), brand(brand), technology(tech) {}

    std::string getCommercialName() const { return commercialName; }
    std::shared_ptr<VaccineTechnology> getTechnology() const { return technology; }
};

#endif // VACCINE_H