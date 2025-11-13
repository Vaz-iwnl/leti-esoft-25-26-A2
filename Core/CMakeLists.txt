cmake_minimum_required(VERSION 3.28)
# CORREÇÃO 1: Nome do projeto corrigido
project(leti-esoft-25-26-A2)

# Define a biblioteca Core com todos os ficheiros necessários
add_library(Core
        # Domain Model
        sources/domain/model/VaccineType.cpp

        # Service
        sources/domain/model/VaccineTypeService.cpp

        # Container Interface

        # Container Implementation
        # CORREÇÃO 2: Adicionar o ficheiro .cpp que existe
        sources/domain/model/VaccineTypeInMemoryContainer.cpp

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

        # CORREÇÃO 3: Remover a referência ao ficheiro da ConsoleApp
        # ../ConsoleApp/sources/views/RegisterVaccineUI.cpp
)
# ...