project(ConsoleApp)

add_executable(ConsoleApp
        ../main.cpp
        headers/views/SpecifyVaccineTypeView.h
        sources/views/SpecifyVaccineTypeView.cpp
        sources/views/RegisterVaccineUI.cpp
)

target_include_directories(ConsoleApp PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/headers/views
        ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

target_link_libraries(ConsoleApp PRIVATE Core)