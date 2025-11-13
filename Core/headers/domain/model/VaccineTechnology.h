//create by João Vaz 1240908
#ifndef VACCINE_TECHNOLOGY_H
#define VACCINE_TECHNOLOGY_H

// Definido dentro dos namespaces corretos
namespace domain {
    namespace model {

        // A sua lista correta de enum
        enum class VaccineTechnology {
            Inactivated,      // Inativada (ou Morta)
            LiveAttenuated,   // Atenuada Viva
            Subunit,          // Subunidade
            Toxoid,           // Toxoide
            ViralVector,      // Vetor Viral
            mRNA,             // mRNA
            Unknown           // Para casos default
        };

    } // namespace model
} // namespace domain

#endif // VACCINE_TECHNOLOGY_H