//create by João Vaz 1240908
#ifndef VACCINE_TECHNOLOGY_H
#define VACCINE_TECHNOLOGY_H

#include <string>

/**
 * PASSO 1: Modelo de Domínio para a Tecnologia
 */
class VaccineTechnology {
private:
    int id;
    std::string name;

public:
    VaccineTechnology(int id, const std::string& name)
        : id(id), name(name) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
};

#endif // VACCINE_TECHNOLOGY_H