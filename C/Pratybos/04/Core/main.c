#include <stdio.h>
#include <stdlib.h>

int goodNumber(int number){
    int digit1,digit2,digit3;
    digit1=number/100;
    digit2=(number/10)%10;
    digit3=number %10;
    if ((digit1==digit2)||(digit1==digit3)||(digit2==digit3)){
        return 0;
    }
    else return 1;
}
int main()
{
    char choice;
    int userInput=0;
    validation:

        printf("\nPlease enter a single, positive, 3 digit number:\n");
        scanf("%3d",&userInput);
        if (!(getchar() == '\n')){///Not an end
         while (getchar()!='\n');
            printf("\nNot valid, try again");
            goto validation;
        }
        if ((userInput<0)||(userInput<100)){
            printf("\nNot valid, try again");
            goto validation;
        }
    if (goodNumber(userInput)){
        printf("Yes");
    }
    else {
        printf("No");
    }
    printf("\nQuit?(1=yes)");
    scanf("%c",&choice);
    if (!(choice=='1')){
        goto validation;
    }
    return 0;
}
