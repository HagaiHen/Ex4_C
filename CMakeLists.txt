cmake_minimum_required(VERSION 3.21)
project(Ex4_C_ C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Ex4_C_
        Algo.c
        Edge.c
        graph.h
        main.c
        Node.c
        Queue.c)
