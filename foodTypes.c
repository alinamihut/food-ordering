//
// Created by Alina Mihut on 12/22/19.
//
#include "foodTypes.h"
#include "definitions.h"
foodType createFoodType() {
    foodType t;
    t.name = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
    t.specificFoods = NULL;
    return t;
}

void displayMealOptions (int noOfFoodTypes, foodType *foodTypes) {
    printf("Please choose the food you feel like eating today\n");
    for(int i=0;i< noOfFoodTypes;i++) {
        putchar('a'+i);
        printf(") %s \n",foodTypes[i].name);
    }
    printf("%c) Go back\n",'a'+ noOfFoodTypes);
}
void freeFoodTypes(foodType* foodTypes, int noOfFoodTypes) {
    for (int i = 0; i < noOfFoodTypes; i++) {
        for (int j = 0; j < foodTypes[i].noOfSpecificFoods; j++) {
            freeSpecificFood(&(foodTypes[i].specificFoods[j]));
        }
        free(foodTypes[i].specificFoods);
        free(foodTypes[i].name);
    }
    free(foodTypes);
}
