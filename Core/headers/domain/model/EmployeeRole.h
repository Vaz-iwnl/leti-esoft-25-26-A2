#ifndef EMPLOYEEROLE_H
#define EMPLOYEEROLE_H

namespace domain {
    namespace model {

        // Define os papéis possíveis para um funcionário (US14)
        enum class EmployeeRole {
            RECEPTIONIST,
            NURSE,
            UNKNOWN
        };

    } // namespace model
} // namespace domain

#endif //EMPLOYEEROLE_H