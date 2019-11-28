//
#include <stdio.h>
#include "definitions.h"
// Created by Alina Mihut on 11/6/19.

void inputPersonalData (char Username[], char Password[] ){
    printf("Please sign in to continue!\n");
    printf("---Username:\n");
    gets(Username);
    printf("---Password:\n");
    gets(Password);
}

void displayOrderData (char Username[], char ***specificFoods, double *pricesOfFood,char **drinks, double *pricesOfDrinks, char  wantCutlery[][MAX_CUTLERY_ANSWER_NAME]){
    printf("This is your order:\n");
    printf("-------------\n");
    printf("Name: %s\n", Username);
    printf("Food Items:\n");
    printf("--- %s (%.2f)\n", specificFoods, pricesOfFood);
    printf("Drinks:\n");
    printf("--- %s (%.2f)\n", drinks, pricesOfDrinks);
    printf("Cutlery: %s \n", wantCutlery);
    printf("Payment amount: %.2f\n", pricesOfFood + pricesOfDrinks);
}
//
