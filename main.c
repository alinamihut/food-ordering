#include <stdio.h>
#include "buyerdata.h"
#include "display_options.h"
#include "customer_choices.h"
#define MAX_MEAL_NAME 10
#define MAX_TYPE_OF_FOOD_NAME 30
#define MAX_DRINK_NAME 20
#define MAX_CUTLERY_ANSWER_NAME 12
#define MAX_ADDITIONAL_INFO 30


int noOfMeals = 3,noOfDrinks = 5,noOfCutleryOptions=2;;
char meals[][10] = {"Pizza","Pasta","Salad"};
int noOfMealTypes[] = {3,2,4};
char types[][3][30] = {
        {"Pizza Carbonara", "Pizza Diavola", "Pizza Marguerita"}, {"Chicken Alfredo", "Mac&cheese"}, {"Tuna Salad", "Greek Salad", "Chicken Salad", "Cobb"} };
double pricesOfFood[3][4] = { {21, 23, 19}, {23, 21}, {23, 22, 19, 21}};
char drinks[][20] = {"Coca-Colla", "Fanta", "Lipton", "Water", "No, thanks"};
double pricesOfDrinks[5] = {5,5,5,4};
char wantCutlery[][12] = {"Yes","No, thanks!"};
char Username[20];
char Password[20];
int foodChoice, typeChoice, drinkChoice, choice, cutleryChoice;
char AdditionalInfo[30];
int noAdditionalInfo =1;
int state =0;
int foodOrdered = 0;
int main() {
    printf("Welcome to food thingies!\n");
    while(!foodOrdered){
        switch (state) {
            case 0: {
                inputPersonalData (Username ,Password);
                state++;
                break;
            }
            case 1: {
                displayMealOptions (noOfMeals, meals);
                foodChoice= getChoiceIndex (noOfMeals, &state);
                break;
            }
            case 2: {
                displayTypesOfMealsOptions(noOfMealTypes[foodChoice], meals[foodChoice], types[foodChoice],  pricesOfFood[foodChoice]);
                typeChoice = getChoiceIndex(noOfMealTypes[foodChoice], &state);
                break;
            }
            case 3: {
                displayTypesOfDrinks (meals[foodChoice], noOfDrinks, drinks, pricesOfDrinks);
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
                gets(AdditionalInfo);
                if (AdditionalInfo != '\n') noAdditionalInfo=0;
            }
            case 6:{
                displayOrderData (Username,  types[foodChoice],  pricesOfFood[foodChoice][typeChoice], drinks[drinkChoice], pricesOfDrinks[drinkChoice], wantCutlery[cutleryChoice], AdditionalInfo, noAdditionalInfo);
                printf("a) Confirm order\n");
                printf("b) Go back\n");
                choice = getchar();
                if(choice=='a') {
                    {
                        foodOrdered = 1;
                        printf ("Order confirmed! Thank you for buying from us, %s \n", Username);
                    }
                } else {
                    state--;
                }
                getchar();
                break;
            }
        }
    }
    return 0;
}
