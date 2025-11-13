cmake_minimum_required(VERSION 3.20)
project(project-template)
set(CMAKE_CXX_STANDARD 17)

# Mantém as tuas configurações de output
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Adiciona o executável principal (main.cpp)
add_executable(project-template main.cpp)

# Adiciona os subdiretórios (Core e ConsoleApp são agora bibliotecas)
add_subdirectory(Core)
add_subdirectory(CoreTests)
add_subdirectory(ConsoleApp)

# MUDANÇA CRÍTICA: Liga o teu executável principal a AMBAS as bibliotecas
target_link_libraries(project-template Core ConsoleApp)