add_library(Core STATIC
        sources/domain/shared/Result.cpp
        sources/domain/shared/StringUtils.cpp

        sources/controllers/ui/SpecifyVaccineTypeController.cpp
        sources/domain/exceptions/DuplicateCodeException.cpp
        sources/domain/model/VaccineType.cpp
        sources/domain/model/VaccineTypeInMemoryContainer.cpp
        sources/domain/model/VaccineTypeService.cpp

        sources/domain/model/VaccineInMemoryContainer.cpp
        sources/domain/model/VaccineService.cpp
        sources/controllers/ui/RegisterVaccineController.cpp
)

target_include_directories(Core PUBLIC headers)