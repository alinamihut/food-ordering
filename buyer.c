//
// Created by Alina Mihut on 12/20/19.
#include "definitions.h"
#include "buyer.h"
buyer createBuyer(){
    buyer b;
    b.Username = (char*)malloc(MAX_USERNAME* sizeof(char));
    b.Password = (char*)malloc(MAX_PASSWORD* sizeof(char));
    return b;
}
void inputPersonalData (buyer *b){
    printf("Please sign in to continue!\n");
    printf("---Username:\n");
    gets(b->Username);
    printf("---Password:\n");
    gets(b->Password);
}

//

