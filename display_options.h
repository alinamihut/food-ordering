//
// Created by Alina Mihut on 11/6/19.
//
#include "definitions.h"
#ifndef FOOD_ORDERING_DISPLAY_OPTIONS_H
#define FOOD_ORDERING_DISPLAY_OPTIONS_H

void displayMealOptions (int noOfMeals, char meals[][MAX_MEAL_NAME]);
void displayTypesOfMealsOptions (int noOfMealTypes, char meals[], char types[][MAX_TYPE_OF_FOOD_NAME], double pricesOfFood[] );
void displayTypesOfDrinks (char meals[], int noOfDrinks, char drinks[][MAX_DRINK_NAME], double pricesOfDrinks[]);
#endif //FOOD_ORDERING_DISPLAY_OPTIONS_H
