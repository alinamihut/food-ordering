#include <stdio.h>
#include "definitions.h"
//
void displayMealOptions (int noOfMeals, char meals[][MAX_MEAL_NAME]){
    printf("Please choose the food you feel like eating today\n");
    for(int i=0;i<noOfMeals;i++) {
        putchar('a'+i);
        printf(") %s\n",meals[i]);
    }
    printf("%c) Go back\n",'a'+noOfMeals);
}

void displayTypesOfMealsOptions (int noOfMealTypes, char meals[], char types[][MAX_TYPE_OF_FOOD_NAME], double pricesOfFood[] ){
    printf("Please choose the type of %s\n",meals);
    for(int i=0;i<noOfMealTypes;i++) {
        putchar('a'+i);
        printf(") %s (%.2f)\n",types[i], pricesOfFood[i]);
    }
    printf("%c) Go back\n",'a'+noOfMealTypes);
}

void displayTypesOfDrinks (char meals[], int noOfDrinks, char drinks[][MAX_DRINK_NAME], double pricesOfDrinks[]) {
    printf("Please choose a drink to go with your %s\n", meals);
    for (int i = 0; i < noOfDrinks; i++) {
        putchar('a' + i);
        printf(") %s (%.2f) \n", drinks[i], pricesOfDrinks[i]);
    }
    printf("%c) Go back\n", 'a' + noOfDrinks);
// Created by Alina Mihut on 11/6/19.
//
}
