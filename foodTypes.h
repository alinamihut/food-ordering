//
// Created by Alina Mihut on 12/22/19.
//

#ifndef FOOD_ORDERING_FOODTYPES_H
#define FOOD_ORDERING_FOODTYPES_H
#include "specificfoods.h"
#include "foodTypes.h"
typedef struct _foodType{
    char * name;
    int noOfSpecificFoods;
    specificFood *specificFoods;
} foodType;
void displayMealOptions (int noOfFoodTypes, foodType *foodTypes);
void freeFoodTypes(foodType* foodTypes, int noOfFoodTypes);
foodType createFoodType();
#endif //FOOD_ORDERING_FOODTYPES_H
