//
// Created by Alina Mihut on 11/6/19.
//
#include "definitions.h"
#ifndef FOOD_ORDERING_DISPLAY_OPTIONS_H
#define FOOD_ORDERING_DISPLAY_OPTIONS_H

void displayMealOptions (int noOfFoodTypes, char **foodTypes);
void displayTypesOfMealsOptions (int noOfSpecificFoods, char **foodTypes, char ***specificFoods, double **pricesOfFood );
void displayTypesOfDrinks (char **foodTypes, int noOfDrinks, char **drinks, double *pricesOfDrinks);
#endif //FOOD_ORDERING_DISPLAY_OPTIONS_H
