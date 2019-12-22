#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _specificFood{
    char * name;
    double price;
}specificFood;
void displaySpecificFoodsOptions (specificFood *specificFoods, int noOfSpecificFoods, char *foodTypes);
void freeSpecificFood(specificFood * s);
