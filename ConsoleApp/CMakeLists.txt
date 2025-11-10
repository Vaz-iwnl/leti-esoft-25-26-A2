project(ConsoleApp)

add_executable(ConsoleApp
        ConsoleApp.cpp
        headers/views/SpecifyVaccineTypeView.h
        sources/views/SpecifyVaccineTypeView.cpp
)

target_include_directories(ConsoleApp PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/views
        ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

# Link com a biblioteca Core
target_link_libraries(ConsoleApp PRIVATE Core)