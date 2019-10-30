#include <stdio.h>

int main() {
    printf("Welcome to food thingies!\n");


    int noOfMeals = 3,noOfDrinks = 5;
    char meals[][10] = {"Pizza","Pasta","Salad"};
    int noOfMealTypes[] = {3,3,4};
    char types[4][4][30] = {
            {"Pizza Carbonara", "Pizza Diavola", "Pizza Marguerita"},
            {"Chicken Alfredo", "Mac&cheese"},
            {"Tuna Salad", "Greek Salad", "Chicken Salad", "Cobb"}
    };

    int pricesOfFood[4][4] = {
            {21, 23, 19},
            {23, 21},
            {23, 22, 19, 21}};
    char drinks[][20] = {"Coca-Colla", "Fanta", "Lipton", "Water", "No, thanks"};
    int pricesOfDrinks[4][4] = {5,5,5,4};


    char wantCutlery[][30] = {"Yes","No, thanks!"};


    //user input
    char Username[20];
    char Password[20];
    int foodChoice, typeChoice, drinkChoice, choice, cutleryChoice;
    char AdditionalInfo[20];

    int state =0;
    int foodOrdered = 0;
    while(!foodOrdered){
        switch (state) {
            case 0: {

                printf("Please sign in to continue!\n");
                printf("---Username:\n");
                gets(Username);
                printf("---Password:\n");
                gets(Password);

                state++;
                break;
            }
            case 1: {
                printf("Please choose the food you feel like eating today\n");
                for(int i=0;i<noOfMeals;i++) {
                    putchar('a'+i);
                    printf(") %s\n",meals[i]);
                }
                printf("%c) Go back\n",'a'+noOfMeals);
                choice = getchar();
                getchar();
                if(choice == 'a'+noOfMeals) {
                    state--;
                    break;
                }
                foodChoice = choice- 'a';
                state++;
                break;
            }
            case 2: {

                printf("Please choose the type of %s\n",meals[foodChoice]);
                for(int i=0;i<noOfMealTypes[foodChoice];i++) {
                    putchar('a'+i);
                    printf(") %s (%.2f)\n",types[foodChoice][i], pricesOfFood[foodChoice][i]);
                }
                printf("%c) Go back\n",'a'+noOfMealTypes[foodChoice]);
                choice = getchar();
                getchar();
                if(choice == 'a'+noOfMealTypes[foodChoice]) {
                    state--;
                    break;
                }
                typeChoice = choice - 'a';
                state++;
                break;
            }
            case 3: {
                printf("Please choose a drink to go with your%s\n",meals[foodChoice]);
                for(int i=0;i<noOfDrinks;i++) {
                    putchar('a'+i);
                    printf(") %s\n",drinks[i]);
                }
                printf("%c) Go back\n",'a'+noOfDrinks);
                choice = getchar();
                getchar();
                if(choice == 'a'+noOfDrinks) {
                    state--;
                    break;
                }
                drinkChoice = choice- 'a';
                state++;
                break;
            }
            case 4: {
                printf("Do you want cutlery? \n");
                for(int i=0;i<2;i++) {
                    putchar('a'+i);
                    printf(") %s\n",wantCutlery[i]);
                }
                printf("%c) Go back\n",'a'+2);
                choice = getchar();
                getchar();
                if(choice == 'a'+2) {
                    state--;
                    break;
                }
                cutleryChoice = choice- 'a';
                state++;
                break;
            }
            case 5:{
                printf("Any additional info?\n");
                gets(AdditionalInfo);
                gets(AdditionalInfo);
            }
            case 6:{
                printf("This is your order:\n");
                printf("-------------\n");
                printf("Name: %s\n", Username);
                printf("Food Items:\n");
                printf("--- %s (%.2f)\n", types[foodChoice], pricesOfFood[foodChoice]);
                printf("Drinks:\n");
                printf("--- %s (%.2f)\n", drinks[drinkChoice], pricesOfDrinks[drinkChoice]);
                printf("Cutlery %s (%.2f)\n", wantCutlery[cutleryChoice]);
                printf ("Additional info: %s\n", AdditionalInfo);

                printf("Payment amount: %.2f\n", pricesOfFood[foodChoice][typeChoice] + pricesOfDrinks[drinkChoice] );
                printf("-------------\n");
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