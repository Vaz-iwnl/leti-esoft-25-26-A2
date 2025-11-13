add_library(ConsoleApp STATIC
        ConsoleApp.cpp

        # Ficheiros da US10 e US11
        sources/views/RegisterVaccineUI.cpp
        sources/views/SpecifyVaccineTypeView.cpp

        # --- NOVO FICHEIRO DA US14 ---
        sources/views/RegisterEmployeeUI.cpp
)

# A biblioteca ConsoleApp (UI) precisa de aceder à biblioteca Core (Domínio)
target_link_libraries(ConsoleApp Core)

# Expõe os headers da UI para quem se ligar a esta biblioteca
target_include_directories(ConsoleApp PUBLIC headers)