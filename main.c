#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buyer.h"
#include "input.h"
#include "specificfoods.h"
#include "foodTypes.h"
#include "drinks.h"
#include "output.h"
FILE *foodOrderingFile;

int main() {

    int noOfCutleryOptions = 2;
    char wantCutlery[][12] = {"Yes", "No, thanks!"};
    char additionalInfo[30];
    int foodChoice, typeChoice, drinkChoice, cutleryChoice;
    int foodOrdered = 0;
    int state = 0;
    char **lineOfFood, **lineCopy;
    char *lineOfDrinks;
    char *token;
    int noOfFoodTypes;
    int j;
    int noOfDrinks;
    buyer b = createBuyer();
    foodType *t;
    drink *d;
    enum State {
        PERSONAL_DATA, CHOOSE_FOODTYPE, CHOOSE_SPECIFiCFOOD, CHOOSE_DRINK, CUTLERY_OPTION, ADDITIONAL_INFO, CONFIRM_ORDER};
    foodOrderingFile = fopen("../data.txt", "r");
    if (foodOrderingFile == NULL) {
        printf("%s\n", LOAD_DATA);
        foodOrderingFile = stdin;
    }
    printf("%s \n", LOAD_DATA);
   fscanf(foodOrderingFile, "%d", &noOfFoodTypes);
    fgetc(foodOrderingFile);

    lineOfFood = (char **) malloc(noOfFoodTypes * sizeof(char *));
    lineCopy = (char **) malloc(noOfFoodTypes * sizeof(char *));
    t = (foodType*) malloc (noOfFoodTypes * sizeof(foodType));
    for (int i = 0; i < noOfFoodTypes; i++) {
        t[i]= createFoodType();
        lineOfFood[i] = (char *) malloc(LINE_lENGTH * sizeof(char));
        lineCopy[i] = (char *) malloc(LINE_lENGTH * sizeof(char));
        fgets(lineOfFood[i], LINE_lENGTH, foodOrderingFile);
        lineOfFood[i][strlen(lineOfFood[i])-1]='\0';
        const char delim[2] = " ";
        token = strtok(lineOfFood[i], delim); //type of food
        strcpy (t[i].name, token);// no of specific foods
        const char delim2[2] = ":";
        token = strtok(NULL, delim2);
        t[i].noOfSpecificFoods = atoi(token);
        strcpy(lineCopy[i], token + 2);
        token = strtok(lineCopy[i], "(");
        t[i].specificFoods=( specificFood *)malloc (t[i].noOfSpecificFoods *sizeof (specificFood));
        for (int j = 0; j < t[i].noOfSpecificFoods; j++)
            t[i].specificFoods[j].name = (char *) malloc(MAX_TYPE_OF_FOOD_NAME * sizeof(char));
        j = 0;
        while (token != NULL) {
            token = strtok(NULL, "-"); //specific foods;
            strcpy(t[i].specificFoods[j].name, token);
            token = strtok(NULL, ")"); //price of food;
            sscanf(token, "%lf", &t[i].specificFoods[j].price);
            j++;
            token = strtok(NULL, "(");
        }
    }

    fscanf(foodOrderingFile, "%d", &noOfDrinks);
    fgetc(foodOrderingFile);
    lineOfDrinks = (char *) malloc(LINE_lENGTH * sizeof(char));
    fgets(lineOfDrinks, LINE_lENGTH, foodOrderingFile);
    lineOfDrinks[strlen(lineOfDrinks)-1]='\0';
    d = (drink*) malloc (noOfDrinks* sizeof(drink));
    for (int i = 0; i < noOfDrinks; i++)
        //drinks[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
        d[i].name=(char*)malloc(MAX_DRINK_NAME*sizeof(char));
    appendCharAtBeginning(lineOfDrinks, ' ');
    token = strtok(lineOfDrinks, "(");
    int i = 0;
    while (token != NULL) {
        token = strtok(NULL, "-");
        strcpy (d[i].name, token);
        token = strtok(NULL, ")");
        sscanf(token, "%lf", &d[i].price);
        i++;
        token = strtok(NULL, "(");
        }

        while (!foodOrdered) {
            switch (state) {
                case PERSONAL_DATA: {
                    printf("Welcome to food thingies!\n");
                    inputPersonalData(&b);
                    state++;
                    break;

                }
                case CHOOSE_FOODTYPE: {
                    displayMealOptions(noOfFoodTypes, t);
                    foodChoice = getChoiceIndex(noOfFoodTypes, &state);
                    break;
                }
                case CHOOSE_SPECIFiCFOOD: {

                    displaySpecificFoodsOptions(t[foodChoice].specificFoods, t[foodChoice].noOfSpecificFoods,
                                                t[foodChoice].name);
                    typeChoice = getChoiceIndex(t[foodChoice].noOfSpecificFoods, &state);
                    break;
                }
                case CHOOSE_DRINK: {
                    displayTypesOfDrinks(t[foodChoice].name, noOfDrinks, d);
                    drinkChoice = getChoiceIndex(noOfDrinks, &state);
                    break;
                }
                case CUTLERY_OPTION: {
                    optionOfCutlery(wantCutlery);
                    cutleryChoice = getChoiceIndex(noOfCutleryOptions, &state);
                    break;
                }
                case ADDITIONAL_INFO: {
                    printf("Any additional info?\n");
                    gets(additionalInfo);
                    state++;
                }
                case CONFIRM_ORDER: {
                    displayOrderData(b.Username, &(t[foodChoice].specificFoods[typeChoice]),&(d[drinkChoice]), &wantCutlery[cutleryChoice]);
                    if (strlen(additionalInfo) != 0) printf("Additional info: %s \n", (additionalInfo));
                    printf("-------------\n");
                    getConfirmation(&state, &foodOrdered);
                    if (foodOrdered == 1) printf("Order confirmed! Thank you for buying from us, %s \n", b.Username);
                    getchar();
                    break;
                }
            }
        }
        for (int i = 0; i < noOfFoodTypes; i++)
        {
            free(lineOfFood[i]);
            free(lineCopy[i]);
        }
        free(lineOfFood);
        free(lineCopy);
        free(lineOfDrinks);
        freeFoodTypes(t, noOfFoodTypes);
        freeDrinks(d);

        fclose(foodOrderingFile);
        return 0;
    }
