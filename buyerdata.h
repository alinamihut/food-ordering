//
// Created by Alina Mihut on 11/6/19.
//
#include "definitions.h"
#ifndef FOOD_ORDERING_BUYERDATA_H
#define FOOD_ORDERING_BUYERDATA_H

void inputPersonalData (char Username[], char Password[] );
void displayOrderData (char Username[], char types[][MAX_TYPE_OF_FOOD_NAME], double pricesOfFood,char drinks[][MAX_DRINK_NAME], double pricesOfDrinks, char  wantCutlery[][MAX_CUTLERY_ANSWER_NAME]);
#endif //FOOD_ORDERING_BUYERDATA_H
