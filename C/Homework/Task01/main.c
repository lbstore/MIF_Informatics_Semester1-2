//28. Įvedamas skaičių masyvas. Reikia nustatyti, kiek jame yra skaičių, vienodai skaitomų iš pradžios ir iš pabaigos, ir ekrane pateikti jų sąrašą.

#include <stdio.h>
#include <stdlib.h>


#define CAPACITY 500
#define MAXVALUE 32768
int reverseNumber( int number){

    int isNegative = 0;
    int times = 1;
    int a,newNumber;
    if (number/10 == 0){
        return number;
    }
    else{
        if (number < 0){
            isNegative = 1;
            number = number*(-1);
        }
        a = newNumber = 0;
        newNumber = number;
        while (newNumber > 0){
            a = a + 1;
            newNumber = newNumber/10;
        }


        newNumber = 1;
        for (; newNumber < a ; newNumber++){
            times = times*10;
        }


        newNumber = 0;
        while (abs(number > 0)){
            a=abs(number % 10);
            number=number/10;
            newNumber = newNumber + a*times;
            times = times/10;
        }
    }
    if (isNegative) return (newNumber*(-1));
    return newNumber;
}

int main ()
{
    printf("Welcome!\n");
    printf("Please enter an size of your array (max 500),\n");
    printf("which you will use for entering integers later on\n");
    printf("Array size:");
    long int userInput = 0;
    int sizeOfArray = 0;

    ///Validation
     int originalArray[CAPACITY]={0};
    // int sortableArray[CAPACITY]={0};

    do{

        if (!((scanf("%5ld",&userInput) == 1) && (getchar() == '\n'))){
            while (getchar() != '\n');
            printf("that was not a valid number\n");
            printf("Try again: ");
        }
        else if (! ((userInput <= CAPACITY) && (userInput > 0)) ){
                printf("Please enter a number in ranges [1;500]\n");
                printf("Try again: ");
        }
        else {
            sizeOfArray = userInput;
            break;
        }

    }while (1);
    printf("\n");
    userInput = 0;
    int i;
    ///Entering integers to the array
    for (i = 0 ; i < sizeOfArray ; i++){
        do{
            printf("Please enter an integer with index Nr. %d: ",i);
            if (!((scanf("%5ld",&userInput) == 1) && (getchar() == '\n'))){
                while (getchar()!='\n');
                printf("that was not a valid number\n");
                printf("Try again\n");

            }
            else if(! ((userInput <= (MAXVALUE-1)) && (userInput >= (MAXVALUE*(-1) ))) ){
                printf("Please enter a number in ranges of integer\n");
                printf("Try again: ");

            }
            else {
                originalArray[i] = userInput;
                ///printf("%d",userInput);
                break;
            }

        }while (1);

    }

    //int i2=0;///In case of sorting
    printf("\n\nNow, you will see all the numbers, \nthat are read the same from both sides:\n");
    ///Printing out Matching integers
    for(i = 0 ; i < sizeOfArray ; i++){
        if (reverseNumber(originalArray[i]) == originalArray[i]){
            printf("%d\n",originalArray[i]);
            //sortableArray[i2]=originalArray[i]; i2=i2+1;
        }
    }

    printf("\nTHE END\n");

    return 0;
}





