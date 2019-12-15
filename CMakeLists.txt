cmake_minimum_required(VERSION 3.15)
project(food_ordering C)

set(CMAKE_C_STANDARD 11)
include_directories(.)

add_executable(food_ordering
        buyerdata.c
        buyerdata.h
        customer_answers.c
        customer_answers.h
        definitions.h
        display_options.c
        display_options.h
        main.c)
