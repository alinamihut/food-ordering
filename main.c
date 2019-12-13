#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buyerdata.h"
#include "display_options.h"
#include "customer_answers.h"
#define LOAD_DATA	"Please load the data"
#define LINE_lENGTH 500
int getConfirmation (int *state,  int *foodOrdered);
void appendCharAtBeginning(char * str, char c);
FILE *foodOrderingFile;

int main() {

/*
  int noOfFoodTypes=3,
   int noOfDrinks = 5;

   char foodTypes[][10] = {"Pizza", "Pasta", "Salad"};
    int noOfSpecificFoods[] = {3, 2, 4};

    char specificFoods[][4][30] = {{"Pizza Carbonara", "Pizza Diavola", "Pizza Marguerita"},
                                 {"Chicken Alfredo", "Mac&cheese"},
                                        {"Tuna Salad",   "Greek Salad",   "Chicken Salad", "Cobb"} };
    double pricesOfFood[3][4] = { {21, 23, 19},
                                {23, 21},
                               {23, 22, 19, 21}};double pricesOfDrinks[5] = {5,5,5,4};
   char drinks[][20] = {"Coca-Colla", "Fanta", "Lipton", "Water", "No, thanks"};
*/
    int noOfCutleryOptions=2;
    char wantCutlery[][12] = {"Yes","No, thanks!"};
    char Username[20], Password[20], additionalInfo[30];
    int foodChoice, typeChoice, drinkChoice, cutleryChoice;
    int foodOrdered = 0;
    int state =0;
    char **lineOfFood, **lineCopy;
    char *lineOfDrinks, *lineCopy2;
    char *token;
    int noOfFoodTypes;
    char **foodTypes;
    char *** specificFoods;
    int * noOfSpecificFoods;
    double **pricesOfFood;
    int j;
    int noOfDrinks;
    char ** drinks;
    double *pricesOfDrinks;
    foodOrderingFile = fopen("/Users/alinamihut/Computer programming/food-ordering/data.txt","r");

    if(foodOrderingFile==NULL) {
        printf("%s\n", LOAD_DATA);
        foodOrderingFile = stdin;
    }
        printf("%s \n", LOAD_DATA);
        fscanf(foodOrderingFile, "%d", &noOfFoodTypes);
        fgetc(foodOrderingFile);
        foodTypes = (char **) malloc(noOfFoodTypes * sizeof(char *));
        specificFoods = (char ***) malloc(noOfFoodTypes * sizeof(char **));
        noOfSpecificFoods = (int *) malloc(noOfFoodTypes * sizeof(int));
        pricesOfFood = (double **) malloc(noOfFoodTypes * sizeof(double *));
        lineOfFood = (char **) malloc(noOfFoodTypes * sizeof(char *));
        lineCopy = (char **) malloc(noOfFoodTypes * sizeof(char *));
        for (int i = 0; i < noOfFoodTypes; i++) {
            lineOfFood[i] = (char *) malloc(LINE_lENGTH * sizeof(char));
            lineCopy[i] = (char *) malloc(LINE_lENGTH * sizeof(char));
            fgets(lineOfFood[i], LINE_lENGTH, foodOrderingFile);
            lineOfFood[i][strlen(lineOfFood[i])-1]='\0';
            const char delim[2] = " ";
            token = strtok(lineOfFood[i], delim); //type of food
            foodTypes[i] = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
            strcpy (foodTypes[i], token);// no of specific foods
            const char delim2[2] = ":";
            token = strtok(NULL, delim2);
            noOfSpecificFoods[i] = atoi(token);
            specificFoods[i] = (char **) malloc(noOfSpecificFoods[i] * sizeof(char *));
            pricesOfFood[i] = (double *) malloc(noOfSpecificFoods[i] * sizeof(double));
            strcpy(lineCopy[i], token + 2);
            token = strtok(lineCopy[i], "(");
            j = 0;
            for (int j = 0; j < noOfSpecificFoods[i]; j++)
                specificFoods[i][j] = (char *) malloc(MAX_TYPE_OF_FOOD_NAME * sizeof(char));
            while (token != NULL) {
                token = strtok(NULL, "-"); //specific foods;
                strcpy(specificFoods[i][j], token);
                token = strtok(NULL, ")"); //price of food;
                sscanf(token, "%lf", &pricesOfFood[i][j]);
                j++;
                token = strtok(NULL, "(");
            }
        }
        for (int i = 0; i < noOfFoodTypes; i++) {
            printf(" %d \n", noOfSpecificFoods[i]);
        }
        for (int i = 0; i < noOfFoodTypes; i++)
            for (int j = 0; j < noOfSpecificFoods[i]; j++) {
                printf(" mancare %s \n", specificFoods[i][j]);
                printf("pret %.2lf \n", pricesOfFood[i][j]);
            }

        fscanf(foodOrderingFile, "%d", &noOfDrinks);
        fgetc(foodOrderingFile);
        lineOfDrinks = (char *) malloc(LINE_lENGTH * sizeof(char));
        fgets(lineOfDrinks, LINE_lENGTH, foodOrderingFile);
        lineOfDrinks[strlen(lineOfDrinks)-1]='\0';
        drinks = (char **) malloc(noOfDrinks * sizeof(char *));
        pricesOfDrinks = (double *) malloc(noOfDrinks * sizeof(double));
        for (int i = 0; i < noOfDrinks; i++)
            drinks[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
        appendCharAtBeginning(lineOfDrinks, ' ');
        token = strtok(lineOfDrinks, "(");
        int i = 0;
        while (token != NULL) {
            token = strtok(NULL, "-");
            strcpy (drinks[i], token);
            token = strtok(NULL, ")");
            sscanf(token, "%lf", &pricesOfDrinks[i]);
            i++;
            token = strtok(NULL, "(");
        }


        for(int i=0;i< noOfDrinks;i++) {
            printf("drink %s \n", drinks[i]);
            printf("price %.0lf \n", pricesOfDrinks[i]);
        }

    while(!foodOrdered){
        switch (state) {
            case 0: {
                printf("Welcome to food thingies!\n");
                inputPersonalData (Username ,Password);
                state++;
                break;

            }
            case 1: {

                displayMealOptions (noOfFoodTypes, foodTypes);
                foodChoice = getChoiceIndex (noOfFoodTypes, &state);
                break;
            }

            case 2: {

                displayTypesOfMealsOptions(noOfSpecificFoods[foodChoice], foodTypes[foodChoice], specificFoods[foodChoice], pricesOfFood[foodChoice]);
                typeChoice = getChoiceIndex(noOfSpecificFoods[foodChoice], &state);
                break;
            }
            case 3: {
                displayTypesOfDrinks (foodTypes[foodChoice], noOfDrinks, drinks, pricesOfDrinks);
                drinkChoice = getChoiceIndex (noOfDrinks, &state);
                break;
            }
            case 4: {
                optionOfCutlery( wantCutlery);
                cutleryChoice = getChoiceIndex( noOfCutleryOptions,&state);
                break;
            }
            case 5:{
                printf("Any additional info?\n");
                gets(additionalInfo);
                state++;
            }
            case 6: {
                displayOrderData(Username, specificFoods[foodChoice], pricesOfFood[foodChoice][typeChoice], drinks[drinkChoice], pricesOfDrinks[drinkChoice], &wantCutlery[cutleryChoice]);
                if (strlen(additionalInfo) != 0) printf("Additional info: %s \n", (additionalInfo));
                printf("-------------\n");
                getConfirmation(&state, &foodOrdered);
                if (foodOrdered == 1) printf("Order confirmed! Thank you for buying from us, %s \n", Username);
                getchar();
                break;
                }
            }
        }
    for( int i=0;i< noOfFoodTypes;i++) {
        for(int j=0;j<noOfSpecificFoods[i];j++) {
            free(specificFoods[i][j]);
        }
        free(specificFoods[i]);
        free(foodTypes[i]);
    }
    free(foodTypes);
    free (noOfSpecificFoods);
    free (specificFoods);
    free(pricesOfFood);
    for(int i =0;i<noOfDrinks;i++) {
        free(drinks[i]);

    }
    free (drinks);
    free (pricesOfDrinks);
    fclose(foodOrderingFile);
    return 0;
}

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

void appendCharAtBeginning(char * str, char c) {
    int len = strlen(str)+1;
    memmove(str+1,str,len);
    str[0] = c;
}
