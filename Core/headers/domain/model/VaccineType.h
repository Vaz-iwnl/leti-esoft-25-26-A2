#ifndef VACCINE_TYPE_H
#define VACCINE_TYPE_H

#include <string>

namespace domain::model {

    // A lista predefinida de tecnologias de vacinas (AC11-1)
    enum class VaccineTechnology {
        Inactivated,      // Inativada (ou Morta)
        LiveAttenuated,   // Atenuada Viva
        Subunit,          // Subunidade
        Toxoid,           // Toxoide
        ViralVector,      // Vetor Viral
        mRNA,              // mRNA
        Unknown,
        // Use uma função auxiliar para converter a string de entrada para este enum
    };

    class VaccineType {
    public:
        // Construtor
        VaccineType(const std::string& code,
                    const std::string& disease,
                    const std::string& description,
                    VaccineTechnology technology);

        // Métodos Getters (Acessores)
        [[nodiscard]] std::string getCode() const;
        [[nodiscard]] std::string getDisease() const;
        [[nodiscard]] std::string getDescription() const;
        [[nodiscard]] VaccineTechnology getTechnology() const;


    private:
        std::string code_;
        std::string disease_;
        std::string description_;
        VaccineTechnology technology_;
    };
}

#endif // VACCINE_TYPE_H