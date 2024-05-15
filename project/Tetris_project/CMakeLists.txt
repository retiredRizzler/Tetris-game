cmake_minimum_required(VERSION 3.5)

project(Tetris_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")
set(CMAKE_PREFIX_PATH "C:/Qt/6.6.2/mingw_64/lib/cmake")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()


add_subdirectory(src)
add_subdirectory(tests)


