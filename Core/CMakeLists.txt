project(Core)

# Define a biblioteca Core com todos os ficheiros necessários
add_library(Core
        # Domain Model
        sources/domain/model/VaccineType.cpp
        headers/domain/model/VaccineType.h

        # Service
        sources/domain/model/VaccineTypeService.cpp
        headers/domain/model/VaccineTypeService.h

        # Container Interface
        headers/domain/model/VaccineTypeContainer.h

        # Container Implementation
        sources/domain/container/VaccineTypeInMemoryContainer.cpp
        headers/domain/container/VaccineTypeInMemoryContainer.h

        # Controller
        sources/controllers/ui/SpecifyVaccineTypeController.cpp
        headers/controllers/ui/SpecifyVaccineTypeController.h

        # Exceptions
        headers/domain/exceptions/DuplicateCodeException.h
        sources/domain/exceptions/DuplicateCodeException.cpp

        # Shared (se existirem)
        headers/domain/shared/Result.h
        headers/domain/shared/StringUtils.h
        sources/domain/shared/Result.cpp
        sources/domain/shared/StringUtils.cpp
)

# Torna os headers públicos
target_include_directories(Core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/headers
)