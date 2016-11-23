#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CAPACITY 1000
int main()
{

    int size=0;
    printf("Enter the size of array: ");
    scanf("%3d",&size);
    int userInputIndex=0;
    int userInputValue=0;
    int x[CAPACITY] = {0};
    int i=0;
    int numberOfTries=0;
    srand(time(NULL));

    for (i=0;i<size;i++){
        x[i]=(rand()%100+1);
        printf("%d ",x[i]);
    }
///UPDATE
    printf("\nEnter an index, from 0 - %d, \nyou would like to change value of:",size-1);
    numberOfTries=0;
    do{
        if (numberOfTries>0){
            printf("Try again\n");
        }
        numberOfTries=numberOfTries+1;
        scanf("%d",&userInputIndex);
    }while ((userInputIndex>size-1)||(userInputIndex<0));

    printf("\nEnter an integer you would like to change Nr.%d, element value to:",userInputIndex);
    scanf("%d",&userInputValue);
    x[userInputIndex]=userInputValue;

    printf("Your new array\n");
    for (i=0;i<size;i++){
        printf("%d ",x[i]);
    }


///DELETE
    printf("\nEnter an element index, from 0 - %d, \nyou would like to delete:",size-1);
    numberOfTries=0;
    do{
        if (numberOfTries>0){
            printf("Try again\n");
        }
        numberOfTries=numberOfTries+1;
        scanf("%d",&userInputIndex);
    }while ((userInputIndex>size-1)||(userInputIndex<0));

    size=size-1;
    for (i=userInputIndex;i<size;i++){
        x[i]=x[i+1];
    }
    printf("Your new array\n");
    for (i=0;i<size;i++){
        printf("%d ",x[i]);
    }
///INSERT
    printf("Enter an element index, from 0 - %d, \nyou would like to insert:",size-1);
    numberOfTries=0;
    do{
        if (numberOfTries>0){
            printf("Try again\n");
        }
        numberOfTries=numberOfTries+1;
        scanf("%d",&userInputIndex);
    }while ((userInputIndex>size-1)||(userInputIndex<0));

    size=size+1;
    printf("Enter an integer you would like to change Nr.%d, element value to:",userInputIndex);
    scanf("%d",&userInputValue);
    for (i=size;i>userInputIndex;i--){
        x[i]=x[i-1];
    }

    x[userInputIndex]=userInputValue;
    printf("Your new array\n");
    for (i=0;i<size;i++){
        printf("%d ",x[i]);
    }
    printf("\n");
    printf("Great success\n");
    return 0;
}
