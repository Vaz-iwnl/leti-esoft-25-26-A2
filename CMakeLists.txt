# CMakeLists.txt (Raiz)
cmake_minimum_required(VERSION 3.20)
project(project-template)
set(CMAKE_CXX_STANDARD 17)

# MANTENHA estas linhas:
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_executable(project-template main.cpp)

add_subdirectory(Core)
add_subdirectory(CoreTests)
add_subdirectory(ConsoleApp)

target_link_libraries(project-template Core)
# REMOVA AQUI A LINHA target_link_directories(ConsoleApp PRIVATE "${CMAKE_BINARY_DIR}/lib")
target_link_libraries(ConsoleApp Core)