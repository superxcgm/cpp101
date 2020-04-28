cmake_minimum_required(VERSION 3.15)
project(cpp101)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp101 main.cpp ObjectOriented/Complex.cpp ObjectOriented/Complex.h ObjectOriented/main.cpp ObjectOriented/main.h InputOutput/main.cpp InputOutput/main.h ObjectOriented/my_string.cpp ObjectOriented/my_string.h ObjectOriented/Vector.cpp ObjectOriented/Vector.h ObjectOriented/Shape.cpp ObjectOriented/Shape.h)