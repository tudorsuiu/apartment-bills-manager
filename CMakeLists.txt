cmake_minimum_required(VERSION 3.21)
project(lab_78_tudorsuiu)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_78_tudorsuiu main.cpp Domain/Entity.cpp Domain/Entity.h Repository/Repository.cpp Repository/Repository.h Tests/Test.cpp Tests/Test.h UserInterface/Console.cpp UserInterface/Console.h Domain/Vector.cpp Domain/Vector.h)
