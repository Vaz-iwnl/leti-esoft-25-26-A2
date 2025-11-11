cmake_minimum_required(VERSION 3.28)
project(leti-esoft-25-25-A2)

# Define a biblioteca Core com todos os ficheiros necessários
add_library(Core
        # Domain Model
        sources/domain/model/VaccineType.cpp


        # Service
        sources/domain/model/VaccineTypeService.cpp

        # Container Interface


        # Container Implementation
        #sources/domain/container/VaccineTypeInMemoryContainer.cpp //isto não está a dar nem existe

        # Controller
        sources/controllers/ui/SpecifyVaccineTypeController.cpp


        # Exceptions
        sources/domain/exceptions/DuplicateCodeException.cpp

        # Shared (se existirem)
        sources/domain/shared/Result.cpp
        sources/domain/shared/StringUtils.cpp
        headers/domain/model/VaccineTechnology.h
        headers/domain/model/Vaccine.h
        headers/domain/repositories/VaccineTechnologyRepository.h
        ../ConsoleApp/sources/views/RegisterVaccineUI.cpp
)

# Torna os headers públicos
target_include_directories(Core PUBLIC headers)