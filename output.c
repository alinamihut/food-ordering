//
// Created by Alina Mihut on 12/22/19.
//
#include "output.h"
int getConfirmation (int *state, int *foodOrdered)
{
    printf("a) Confirm order\n");
    printf("b) Go back\n");
    *foodOrdered=0;
    char choice = getchar();
    if(choice=='b') (*state)--;
    else {(*foodOrdered )= 1;}
    return *foodOrdered;
}
void displayOrderData (buyer *b, specificFood *s,   drink *d, char  wantCutlery[][MAX_CUTLERY_ANSWER_NAME]){
    printf("This is your order:\n");
    printf("-------------\n");
    printf("Name: %s\n", b->Username);
    printf("Food Items:\n");
    printf("--- %s (%.2f)\n", s->name, s->price);
    printf("Drinks:\n");
    printf("--- %s (%.2f)\n", d->name, d->price);
    printf("Cutlery: %s \n", wantCutlery);
    printf("Payment amount: %.2f\n", s->price + d->price);
}