//
// Created by Alina Mihut on 12/20/19.
//
#include "specificfoods.h"

void displaySpecificFoodsOptions (specificFood *specificFoods, int noOfSpecificFoods, char *foodTypes){
    printf("Please choose the type of %s\n",foodTypes);
    for(int i=0;i<noOfSpecificFoods;i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", specificFoods[i].name, specificFoods[i].price);
    }
    printf("%c) Go back\n",'a'+noOfSpecificFoods);
}
void freeSpecificFood(specificFood *s) {
    free(s->name);
}