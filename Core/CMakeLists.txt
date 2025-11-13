project(Core)

# O tipo STATIC é importante para criar o ficheiro libCore.a
add_library(Core STATIC
        sources/domain/shared/Result.cpp
        sources/domain/shared/StringUtils.cpp
)

# Crucial para que ConsoleApp possa compilar os headers
target_include_directories(Core PUBLIC headers)