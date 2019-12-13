#include <stdio.h>
#include "definitions.h"
//

int getChoiceIndex (int noOfChoices, int *state) {
    int choiceIndex;
    char choice = getchar();
    getchar();
    if(choice == 'a'+noOfChoices) {
        (*state)--;
    }else {
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}

void optionOfCutlery (char wantCutlery[][MAX_CUTLERY_ANSWER_NAME]){
    printf("Do you want cutlery? \n");
    for(int i=0;i<2;i++) {
        putchar('a'+i);
        printf(") %s\n",wantCutlery[i]);
    }
    printf("%c) Go back\n",'a'+2);

}
// Created by Alina Mihut on 11/6/19.
//

