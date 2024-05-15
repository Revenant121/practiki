cmake_minimum_required(VERSION 3.28)
project(practica13 C)

set(CMAKE_C_STANDARD 11)

add_executable(practica13 main.c
        student.h
        student.c
        node.h
        node.c
)
