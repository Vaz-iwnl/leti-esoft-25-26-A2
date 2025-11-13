add_subdirectory(lib)

add_executable(CoreTests domain/shared/StringUtilsTests.cpp)

target_link_libraries(CoreTests Core)
target_link_libraries(CoreTests gtest gtest_main)