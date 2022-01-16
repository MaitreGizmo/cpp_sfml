cmake_minimum_required(VERSION 3.20)
project(cpp_sfml)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(SFML_source_2_5_1)

set(SFML_DIR "cmake-build-debug/SFML_source_2_5_1")

find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)

add_executable(cpp_sfml main.cpp MainWindow.cpp MainWindow.h Settings.h WorldBloc.cpp WorldBloc.h Player.cpp Player.h)

target_link_libraries(cpp_sfml sfml-graphics sfml-window sfml-system)
