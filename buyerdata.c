//
#include <stdio.h>
// Created by Alina Mihut on 11/6/19.
#define MAX_TYPE_OF_FOOD_NAME 30
#define MAX_DRINK_NAME 20
#define MAX_CUTLERY_ANSWER_NAME 12
#define MAX_ADDITIONAL_INFO 30
void inputPersonalData (char Username[], char Password[] ){
    printf("Please sign in to continue!\n");
    printf("---Username:\n");
    gets(Username);
    printf("---Password:\n");
    gets(Password);
}
void displayOrderData (char Username[], char types[][MAX_TYPE_OF_FOOD_NAME], double pricesOfFood,char drinks[][MAX_DRINK_NAME], double pricesOfDrinks, char  wantCutlery[][MAX_CUTLERY_ANSWER_NAME], char AdditionalInfo[ MAX_ADDITIONAL_INFO], int noAdditionalInfo){
    printf("This is your order:\n");
    printf("-------------\n");
    printf("Name: %s\n", Username);
    printf("Food Items:\n");
    printf("--- %s (%.2f)\n", types, pricesOfFood);
    printf("Drinks:\n");
    printf("--- %s (%.2f)\n", drinks, pricesOfDrinks);
    printf("Cutlery: %s \n", wantCutlery);
    if (noAdditionalInfo ==0) printf ("Additional info: %s\n", AdditionalInfo);

    printf("Payment amount: %.2f\n", pricesOfFood+ pricesOfDrinks );
    printf("-------------\n");


}
//
