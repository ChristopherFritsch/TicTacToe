cmake_minimum_required(VERSION 3.5)
project(TicTacToe CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(TicTacToe main.cpp 
gui.cpp gui.hpp 
playerwidget.cpp playerwidget.hpp 
messagebox.cpp messagebox.hpp
canvas.cpp canvas.hpp 
game.cpp game.hpp 
board.cpp board.hpp)

target_link_libraries(TicTacToe Qt5::Widgets)

set(CMAKE_CXX_FLAGS "-Wno-psabi")
add_executable(unittests unittests.cpp catch.hpp board.cpp board.hpp game.cpp game.hpp)
