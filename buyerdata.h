//
// Created by Alina Mihut on 11/6/19.
//

#ifndef FOOD_ORDERING_BUYERDATA_H
#define FOOD_ORDERING_BUYERDATA_H

#define MAX_TYPE_OF_FOOD_NAME 30
#define MAX_DRINK_NAME 20
#define MAX_CUTLERY_ANSWER_NAME 12
#define MAX_ADDITIONAL_INFO 30
void inputPersonalData (char Username[], char Password[] );
void displayOrderData (char Username[], char types[][MAX_TYPE_OF_FOOD_NAME], double pricesOfFood,char drinks[][MAX_DRINK_NAME], double pricesOfDrinks, char  wantCutlery[][MAX_CUTLERY_ANSWER_NAME], char AdditionalInfo[ MAX_ADDITIONAL_INFO], int noAdditionalInfo );
#endif //FOOD_ORDERING_BUYERDATA_H
