project(ConsoleApp)

add_executable(ConsoleApp ConsoleApp.cpp)

# CRÍTICO: Informar o linker explicitamente sobre o caminho da biblioteca estática.
# ${CMAKE_BINARY_DIR} aponta para a pasta de build da raiz, e '/lib' é onde a Core está.
target_link_directories(ConsoleApp PRIVATE "${CMAKE_BINARY_DIR}/lib")

target_link_libraries(ConsoleApp Core)