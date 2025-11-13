cmake_minimum_required(VERSION 3.20)
project(leti-esoft-25-26-A2)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Inclui diretórios do Core globalmente
include_directories(Core)
include_directories(ConsoleApp)
# Adiciona os subdiretórios
add_subdirectory(Core)
add_subdirectory(ConsoleApp)

# Se existir CoreTests, adiciona table
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/CoreTests/CMakeLists.txt")
    add_subdirectory(CoreTests)
endif()

# Define ConsoleApp como projeto de inicialização
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ConsoleApp)