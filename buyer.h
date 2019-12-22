//
// Created by Alina Mihut on 12/20/19.
//

#ifndef FOOD_ORDERING_BUYER_H
#define FOOD_ORDERING_BUYER_H
#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

// Created by Alina Mihut on 11/6/19.

typedef struct _buyer {
    char * Username;
    char * Password;
} buyer;

buyer createBuyer();
void inputPersonalData (buyer *b);

#endif //FOOD_ORDERING_BUYER_H
