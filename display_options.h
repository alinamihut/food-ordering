//
// Created by Alina Mihut on 11/6/19.
//
#ifndef FOOD_ORDERING_DISPLAY_OPTIONS_H
#define FOOD_ORDERING_DISPLAY_OPTIONS_H

#define MAX_MEAL_NAME 10
#define MAX_TYPE_OF_FOOD_NAME 30
#define MAX_DRINK_NAME 20
#define MAX_CUTLERY_ANSWER_NAME 12
#define MAX_ADDITIONAL_INFO 30
void displayMealOptions (int noOfMeals, char meals[][MAX_MEAL_NAME]);
void displayTypesOfMealsOptions (int noOfMealTypes, char meals[], char types[][MAX_TYPE_OF_FOOD_NAME], double pricesOfFood[] );
void displayTypesOfDrinks (char meals[], int noOfDrinks, char drinks[][MAX_DRINK_NAME], double pricesOfDrinks[]);
#endif //FOOD_ORDERING_DISPLAY_OPTIONS_H
