cmake_minimum_required(VERSION 4.3)
project(CS210_Assignments)

set(CMAKE_CXX_STANDARD 14)

include_directories("Assignment 3")

add_executable(Assignment_3
        "Assignment 3/ArrayList.h"
        "Assignment 3/Data.h"
        "Assignment 3/LinkedList.h"
        "Assignment 3/main.cpp"
        "Assignment 3/Node.h"
        "Assignment 3/List.h"
)

add_executable(PA1_Uno_Turn_Order
        "PA1 Uno Turn Order/main.cpp"
        "PA1 Uno Turn Order/Player.h"
        "PA1 Uno Turn Order/Stack.h"
        "PA1 Uno Turn Order/ArrayList.h"
        "PA1 Uno Turn Order/LinkedList.h"
        "PA1 Uno Turn Order/Data.h"
        "PA1 Uno Turn Order/Node.h"
        "PA1 Uno Turn Order/List.h"
)
