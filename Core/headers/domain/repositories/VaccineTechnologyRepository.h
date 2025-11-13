//create by João Vaz 1240908
#ifndef VACCINE_TECHNOLOGY_REPOSITORY_H
#define VACCINE_TECHNOLOGY_REPOSITORY_H

#include <vector>
#include <memory>
#include "../model/VaccineTechnology.h"

//Repositório com a lista predefinida da Pfizer.

class VaccineTechnologyRepository {
private:
    std::vector<std::shared_ptr<VaccineTechnology>> technologies;

public:
    VaccineTechnologyRepository() {
        // --- A LISTA DO AC11-1 (do site da Pfizer) ---
        technologies.push_back(std::make_shared<VaccineTechnology>(1, "Vacinas vivas atenuadas"));
        technologies.push_back(std::make_shared<VaccineTechnology>(2, "Vacinas inativadas"));
        technologies.push_back(std::make_shared<VaccineTechnology>(3, "Vacinas de mRNA (ARN mensageiro)"));
        technologies.push_back(std::make_shared<VaccineTechnology>(4, "Vacinas de subunidades, recombinantes..."));
        technologies.push_back(std::make_shared<VaccineTechnology>(5, "Vacinas de toxoide"));
        technologies.push_back(std::make_shared<VaccineTechnology>(6, "Vacinas de vetor viral"));
    }

    std::vector<std::shared_ptr<VaccineTechnology>> getAllTechnologies() const {
        return technologies;
    }
};

#endif // VACCINE_TECHNOLOGY_REPOSITORY_H