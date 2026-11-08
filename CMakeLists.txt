cmake_minimum_required(VERSION 4.3)
project(CS210_Assignments)

set(CMAKE_CXX_STANDARD 20)

include_directories("Assignment 3")

add_executable(Assignment_3
        "Assignment 3/main.cpp"
)

add_executable(PA1_Uno_Turn_Order
        "PA1 Uno Turn Order/main.cpp"
)

add_subdirectory("Text Based RPG")