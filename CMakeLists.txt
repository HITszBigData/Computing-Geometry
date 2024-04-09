cmake_minimum_required(VERSION 3.27)
project(Comp_Geo)

set(CMAKE_CXX_STANDARD 17)

add_executable(Comp_Geo main.c
        bresenham_line.c
        bresenham_circle.c
)
