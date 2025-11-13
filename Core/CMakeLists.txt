add_library(Core STATIC
        # Ficheiros antigos
        sources/domain/shared/Result.cpp
        sources/domain/shared/StringUtils.cpp

        # Ficheiros da US10
        sources/controllers/ui/SpecifyVaccineTypeController.cpp
        sources/domain/exceptions/DuplicateCodeException.cpp
        sources/domain/model/VaccineType.cpp
        sources/domain/model/VaccineTypeInMemoryContainer.cpp
        sources/domain/model/VaccineTypeService.cpp

        # Ficheiros da US11
        sources/domain/model/VaccineInMemoryContainer.cpp
        sources/domain/model/VaccineService.cpp
        sources/controllers/ui/RegisterVaccineController.cpp

        # --- NOVOS FICHEIROS DA US14 ---
        sources/domain/model/Employee.cpp
        sources/domain/model/EmployeeInMemoryContainer.cpp
        sources/domain/model/EmployeeService.cpp
        sources/controllers/ui/RegisterEmployeeController.cpp
)

target_include_directories(Core PUBLIC headers)