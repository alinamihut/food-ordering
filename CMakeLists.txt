cmake_minimum_required(VERSION 3.15)
project(food_ordering C)

set(CMAKE_C_STANDARD 99)

add_executable(food_ordering main.c buyerdata.h buyerdata.c display_options.h display_options.c buyerdata.c customer_answers.h customer_answers.c definitions.h)