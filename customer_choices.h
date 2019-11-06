//
// Created by Alina Mihut on 11/6/19.
//

#ifndef FOOD_ORDERING_CUSTOMER_CHOICES_H
#define FOOD_ORDERING_CUSTOMER_CHOICES_H

#define MAX_MEAL_NAME 10
#define MAX_TYPE_OF_FOOD_NAME 30
#define MAX_DRINK_NAME 20
#define MAX_CUTLERY_ANSWER_NAME 12
#define MAX_ADDITIONAL_INFO 30



int getChoiceIndex (int noOfChoices, int *state);
void optionOfCutlery (char wantCutlery[][MAX_CUTLERY_ANSWER_NAME]);
#endif //FOOD_ORDERING_CUSTOMER_CHOICES_H
