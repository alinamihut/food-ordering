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

void displayOrderData (char Username[], char types[][MAX_TYPE_OF_FOOD_NAME], double pricesOfFood,char drinks[][MAX_DRINK_NAME], double pricesOfDrinks, char  wantCutlery[][MAX_CUTLERY_ANSWER_NAME]){
    printf("This is your order:\n");
    printf("-------------\n");
    printf("Name: %s\n", Username);
    printf("Food Items:\n");
    printf("--- %s (%.2f)\n", types, pricesOfFood);
    printf("Drinks:\n");
    printf("--- %s (%.2f)\n", drinks, pricesOfDrinks);
    printf("Cutlery: %s \n", wantCutlery);
    printf("Payment amount: %.2f\n", pricesOfFood+ pricesOfDrinks );
}
//
