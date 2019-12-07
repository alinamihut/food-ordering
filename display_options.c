#include <stdio.h>
#include "definitions.h"
/
void displayMealOptions (int noOfFoodTypes, char **foodTypes){
    printf("Please choose the food you feel like eating today\n");
    for(int i=0;i< noOfFoodTypes;i++) {
        putchar('a'+i);
        printf(") %s\n",foodTypes[i]);
    }
    printf("%c) Go back\n",'a'+ noOfFoodTypes);
}

void displayTypesOfMealsOptions (int noOfSpecificFoods, char *foodTypes, char **specificFoods, double *pricesOfFood ){
    printf("Please choose the type of %s\n",foodTypes);
    for(int i=0;i<noOfSpecificFoods;i++) {
        putchar('a'+i);
        printf(") %s (%.2f)\n", specificFoods[i], pricesOfFood[i]);
    }
    printf("%c) Go back\n",'a'+noOfSpecificFoods);
}

void displayTypesOfDrinks (char *foodTypes, int noOfDrinks, char **drinks, double *pricesOfDrinks){
    printf("Please choose a drink to go with your %s\n", foodTypes);
    for (int i = 0; i < noOfDrinks; i++) {
        putchar('a' + i);
        printf(") %s (%.2f) \n", drinks[i], pricesOfDrinks[i]);
    }
    printf("%c) Go back\n", 'a' + noOfDrinks);
// Created by Alina Mihut on 11/6/19.
//
}
