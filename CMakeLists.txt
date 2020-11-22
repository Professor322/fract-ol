cmake_minimum_required(VERSION 3.17)
project(fract-ol C)

set(CMAKE_C_STANDARD 99)


add_executable(fract-ol src/main.c src/main.c)

target_include_directories(fract-ol PUBLIC ./libft/includes)
target_include_directories(fract-ol PUBLIC ./include)

target_link_libraries(fract-ol /home/professor/SchoolProjects/fract-ol/libft/libft.a)
