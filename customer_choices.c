#include <stdio.h>
//
#define MAX_MEAL_NAME 10
#define MAX_TYPE_OF_FOOD_NAME 30
#define MAX_DRINK_NAME 20
#define MAX_CUTLERY_ANSWER_NAME 12
#define MAX_ADDITIONAL_INFO 30
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

