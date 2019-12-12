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
FILE *fptr;

int main() {
    fptr = fopen("/Users/alinamihut/Computer programming/food-ordering/data.txt","r");
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
    const char delimFood1[3]=": ", delimFood2[5]=":()-";
    const char delimDrinks[7]="()-,";
    int noOfFoodTypes;
    char **foodTypes;
    char *** specificFoods;
    int * noOfSpecificFoods;
    double **pricesOfFood;
    int isFoodType, isSpecificFood,j;
    int drinkOrPrice;
    int noOfDrinks;
    char ** drinks;
    double *pricesOfDrinks;

/*
    if(fptr) {
        //printf ("%s \n", LOAD_DATA);
        fscanf(fptr, "%d", &noOfFoodTypes);
        getchar();

    else {*/
        printf("%s \n", LOAD_DATA);
        scanf("%d", &noOfFoodTypes);
        getchar();
        foodTypes = (char **) malloc(noOfFoodTypes * sizeof(char *));
        specificFoods = (char ***) malloc(noOfFoodTypes * sizeof(char **));
        noOfSpecificFoods = (int *) malloc(noOfFoodTypes * sizeof(int));
        pricesOfFood = (double **) malloc(noOfFoodTypes * sizeof(double *));
        lineOfFood = (char **) malloc(noOfFoodTypes * sizeof(char *));
        lineCopy = (char **) malloc(noOfFoodTypes * sizeof(char *));
        for (int i = 0; i < noOfFoodTypes; i++) {
            /*lineOfFood[i] = (char *) malloc(LINE_lENGTH * sizeof(char));
            gets(lineOfFood[i]);
            isFoodType = 0;
            isSpecificFood = 0;
            foodTypes[i] = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
            token = strtok(lineOfFood[i], delimFood1);
            noOfSpecificFoods[i] = 0;
            j = 0;

            for (int j=0;j<strlen(foodTypes[i]);j++)
                for (int k=0;k<strlen (lineOfFood[i]); k++) {
                    lineOfFood[k] = lineOfFood[k + 1];
                }
            token=strtok(lineOfFood, delimFood);

            while (token != NULL) {

                if (isFoodType == 0) {
                    strcpy (foodTypes[i], token);
                    isFoodType = 1;
                    // printf ("%s \n", foodTypes[i]);
                } else {
                    if (noOfSpecificFoods[i] == 0) {
                        noOfSpecificFoods[i] = atof(token);
                        specificFoods[i] = (char **) malloc(noOfSpecificFoods[i] * sizeof(char *));
                    } else {
                        if (isSpecificFood == 0) {
                            //specificFoods[i][noOfSpecificFoods[i]] = (char *) malloc(MAX_TYPE_OF_FOOD_NAME * sizeof(char));
                            specificFoods[i][j] = (char *) malloc(MAX_TYPE_OF_FOOD_NAME * sizeof(char));
                            //strcpy(specificFoods[i][noOfSpecificFoods[i]],token); //doesn't work for foods with spaces
                            strcpy(specificFoods[i][j], token);
                            isSpecificFood = 1;
                            //printf("%s \n", specificFoods[i][noOfSpecificFoods[i]]);
                            // printf("%s \n", specificFoods[i][j]);
                        } else {
                            pricesOfFood[i] = (double *) malloc(noOfSpecificFoods[i] * sizeof(double));
                            //pricesOfFood[i][noOfSpecificFoods[i]] = atof(token);
                            pricesOfFood[i][j] = atof(token);
                            isSpecificFood = 0;
                            // printf("%.2lf \n", pricesOfFood[i][noOfSpecificFoods[i]]);
                            // printf("%.2lf \n", pricesOfFood[i][j]);
                            j++;

                        }
                    }
                }
                token = strtok(NULL, delimFood);
            }*/
            lineOfFood[i] = (char *) malloc(LINE_lENGTH * sizeof(char));
            lineCopy[i] = (char *) malloc(LINE_lENGTH * sizeof(char));
            gets(lineOfFood[i]);
            const char delim[2]=" ";
            token = strtok(lineOfFood[i],delim); //type of food
            foodTypes[i] = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
            strcpy (foodTypes[i], token);
            // no of specific foods
            const char delim2[2]=":";
            token = strtok(NULL,delim2);
            noOfSpecificFoods[i] = atoi(token);
            specificFoods[i] = (char **) malloc(noOfSpecificFoods[i] * sizeof(char *));
            pricesOfFood[i] = (double *) malloc(noOfSpecificFoods[i] * sizeof(double));
            strcpy(lineCopy[i],token+2);
            token = strtok(lineCopy[i], "(");
            j=0;
            for (int j=0;j<noOfSpecificFoods[i];j++)
                specificFoods[i][j] = (char *) malloc(MAX_TYPE_OF_FOOD_NAME * sizeof(char));
            while (token!=NULL){
                token=strtok(NULL,"-"); //specific foods;
                strcpy(specificFoods[i][j], token);
                token=strtok(NULL,")"); //price of food;
                sscanf(token, "%lf", &pricesOfFood[i][j]);
                j++;
                token = strtok(NULL, "(");
            }
        }
        for (int i=0;i<noOfFoodTypes;i++)
        {
            printf(" %d \n", noOfSpecificFoods[i]);
        }
        for(int i=0;i<noOfFoodTypes;i++)
            for (int j=0;j<noOfSpecificFoods[i];j++)
        {
            printf(" mancare %s \n", specificFoods[i][j]);
            printf ("pret %.2lf \n", pricesOfFood[i][j]);
        }

        scanf("%d", &noOfDrinks);
        getchar();
        lineOfDrinks = (char *) malloc(LINE_lENGTH * sizeof(char));
        gets(lineOfDrinks);
        drinks = (char **) malloc(noOfDrinks * sizeof(char *));
        pricesOfDrinks = (double *) malloc(noOfDrinks * sizeof(double));
            for(int i=0;i<noOfDrinks;i++)
                drinks[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
            appendCharAtBeginning(lineOfDrinks,' ');
            token = strtok(lineOfDrinks,"(" );
            int i=0;
            while (token != NULL) {
                token= strtok(NULL, "-");
                strcpy (drinks[i], token);
                token = strtok(NULL, ")");
                sscanf(token, "%lf", &pricesOfDrinks[i]);
                i++;
                token = strtok(NULL, "(");
            }

        for(int i=0;i<noOfDrinks;i++) {
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
                displayOrderData(Username, &specificFoods[foodChoice], pricesOfFood[foodChoice][typeChoice], drinks[drinkChoice], pricesOfDrinks[drinkChoice], &wantCutlery[cutleryChoice]);
                if (strlen(additionalInfo) != 0) printf("Additional info: %s \n", (additionalInfo));
                printf("-------------\n");
                getConfirmation(&state, &foodOrdered);
                if (foodOrdered == 1) printf("Order confirmed! Thank you for buying from us, %s \n", Username);
                getchar();
                break;
                }
            }
        }
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
/*token = strtok(lineOfDrinks, delimDrinks);
            drinkOrPrice = 1;
            while (token != NULL) {
                if (drinkOrPrice % 2 == 1) {
                    drinks[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
                    strcpy (drinks[i], token);
                    printf("%s \n", drinks[i]);
                } else {
                    //pricesOfDrinks[i] = (double *)malloc(noOfDrinks * sizeof(double));
                    pricesOfDrinks[i] = atof(token);
                    printf("%.2lf \n", pricesOfDrinks[i]);

                }
                drinkOrPrice++;
                token = strtok(NULL, delimDrinks);
            }
             */

/*if (drinkOrPrice % 2 == 1) {
                drinks[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
                //token[strlen(token)-1]='\0';
                strcpy (drinks[i], token);
            } else {
                strcpy(token,token+1);
               // token[strlen(token)-1]='\0';
                pricesOfDrinks[i] = atof(token);

            }
            drinkOrPrice++;*/