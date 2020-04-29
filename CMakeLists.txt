cmake_minimum_required(VERSION 3.15)
project(cpp101)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp101 main.cpp ObjectOriented/Complex.cpp ObjectOriented/Complex.h ObjectOriented/main.cpp ObjectOriented/main.h InputOutput/main.cpp InputOutput/main.h ObjectOriented/my_string.cpp ObjectOriented/my_string.h ObjectOriented/Vector.cpp ObjectOriented/Vector.h ObjectOriented/Shape.cpp ObjectOriented/Shape.h DesignPattern/Singleton.cpp DesignPattern/Singleton.h DesignPattern/main.cpp DesignPattern/main.h RAII/ShapeWrapper.cpp RAII/ShapeWrapper.h RAII/UniquePtr.cpp RAII/UniquePtr.h RAII/main.cpp RAII/main.h DesignPattern/Observer.h DesignPattern/Observerable.cpp DesignPattern/Observerable.h language/main.cpp language/main.h DesignPattern/Adapter.cpp DesignPattern/Adapter.h)