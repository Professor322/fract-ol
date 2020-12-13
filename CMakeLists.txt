cmake_minimum_required(VERSION 3.17)
project(fract-ol C)

set(CMAKE_C_STANDARD 99)

include_directories(./includes)
include_directories(./libft/includes)
include_directories(./minilibx)

add_library(libft SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(libft PROPERTIES
        IMPORTED_LOCATION "/home/professor/SchoolProjects/fract-ol/libft/libft.a"
        INTERFACE_INCLUDE_DIRECTORIES "/home/professor/SchoolProjects/fract-ol/libft/includes"
        )

add_library(libmlx SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(libmlx PROPERTIES
        IMPORTED_LOCATION "/home/professor/SchoolProjects/fract-ol/minilibx/libmlx_Linux.a"
        INTERFACE_INCLUDE_DIRECTORIES "/home/professor/SchoolProjects/fract-ol/minilibx"
        )

add_library(libX11 SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(libX11 PROPERTIES
        IMPORTED_LOCATION "/usr/lib/x86_64-linux-gnu/libX11.so.6"
        )

add_library(libXext SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(libXext PROPERTIES
        IMPORTED_LOCATION "/usr/lib/x86_64-linux-gnu/libXext.so.6"
        )

add_library(libm SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(libm PROPERTIES
        IMPORTED_LOCATION "/usr/lib/x86_64-linux-gnu/libm.so"
        )
add_executable(fract-ol ./src/main.c)
target_link_libraries(fract-ol libmlx libX11 libXext libft libm)


