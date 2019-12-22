//
// Created by Alina Mihut on 12/22/19.
//
#include "drinks.h"


void displayTypesOfDrinks (foodType *foodTypes, int noOfDrinks, drink *drinks ){
    printf("Please choose a drink to go with your %s\n", foodTypes);
    for (int i = 0; i < noOfDrinks; i++) {
        putchar('a' + i);
        printf(") %s (%.2f) \n", drinks[i].name, drinks[i].price);
    }
   printf("%c) Go back\n", 'a' + noOfDrinks);
}
void freeDrinks(drink *d)
{
    free(d->name);
}
