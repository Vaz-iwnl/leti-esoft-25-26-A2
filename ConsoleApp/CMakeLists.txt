

# MUDANÇA: Isto agora é uma BIBLIOTECA (STATIC) que contém a UI
add_library(ConsoleApp STATIC
        ConsoleApp.cpp
        sources/views/RegisterVaccineUI.cpp
        sources/views/SpecifyVaccineTypeView.cpp
)

# A biblioteca ConsoleApp (UI) precisa de aceder à biblioteca Core (Domínio)
target_link_libraries(ConsoleApp Core)

# Expõe os headers da UI (ex: SpecifyVaccineTypeView.h) para quem se ligar a esta biblioteca
target_include_directories(ConsoleApp PUBLIC headers)