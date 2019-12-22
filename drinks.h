//
// Created by Alina Mihut on 12/22/19.
//

#ifndef FOOD_ORDERING_DRINKS_H
#define FOOD_ORDERING_DRINKS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foodTypes.h"

typedef struct _drink{
    char * name;
    double price;
} drink;

void displayTypesOfDrinks (foodType *foodTypes,  int noOfDrinks, drink *drinks );
void freeDrinks(drink *d);
#endif //FOOD_ORDERING_DRINKS_H
