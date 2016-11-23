

/*
susikurti masyva su tam tikru dydziu
susikurti dinamini masyva
random elementus susikuria
isspausdina viska
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void getSize(int* locSize){
    while (1) {
        if((scanf("%d",locSize))==1 || (getchar()=='\n')){
        break;}
        else printf("Try again");
    }
}

int generateRand(){
    int result=0;
    result=(rand()%100+1);
    return result;
}



void getMemory(int** array1,int arraySize){
    *array1= malloc(arraySize*sizeof(int));
};

void printArray(int* array1,int ammountOfElements){
    if(!(array1==NULL)){
        int j=0;
        for (j=0;j<ammountOfElements;j++){
            printf(" %d",array1[j]);
        }
    }
}

int main(int argc, char **argv)
{

    printf("Write the size of your array:");
    int sizeOfArray, userInput;
    getSize(&sizeOfArray);

    int*array ;
    getMemory(&array,sizeOfArray);

    srand(time(NULL));

    int i;
    for (i=0;i<sizeOfArray;i++){
        array[i]=generateRand();
    }

    printArray(array,sizeOfArray);
    free(array);
	return 0;
}

