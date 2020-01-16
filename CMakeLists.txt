cmake_minimum_required(VERSION 3.15)
project(food_ordering C)

set(CMAKE_C_STANDARD 11)
include_directories(.)

add_executable(food_ordering
        input.c
        input.h
        definitions.h
        main.c buyer.c buyer.h input.c input.h specificfoods.c foodTypes.c foodTypes.h drinks.c drinks.h output.c output.h)
