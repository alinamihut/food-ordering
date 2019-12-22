//
// Created by Alina Mihut on 12/22/19.
//

#ifndef FOOD_ORDERING_OUTPUT_H
#define FOOD_ORDERING_OUTPUT_H
#include <stdio.h>
#include "definitions.h"
#include "buyer.h"
#include "specificfoods.h"
#include "drinks.h"
int getConfirmation (int *state,  int *foodOrdered);
void displayOrderData (buyer *b, specificFood *s,   drink *d, char  wantCutlery[][MAX_CUTLERY_ANSWER_NAME]);
#endif //FOOD_ORDERING_OUTPUT_H
