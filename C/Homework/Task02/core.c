//28. Įvedamas skaičių masyvas. Reikia nustatyti, kiek jame yra skaičių, vienodai skaitomų iš pradžios ir iš pabaigos, ir ekrane pateikti jų sąrašą.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXVALUE 32767
// All the text used in main
#define ArrPres 		"Array is not present or empty"
#define arrayGenerated 	"Array generated\n"
#define elementChanged 	"Element has been changed\n"
#define elementDeleted 	"Element has been deleted\n"
#define elementIndex 	"Element index? [0: %d]\n"
#define elementInserted "Element has been inserted\n"
#define elementValue 	"Set element value:"
#define inputFound		"Input found %s "
#define leaveReversable "New array contains only reversable elements \n"
#define numberWithIndex	"Number with index #%d:"
#define printArray 		"Displaying all elements\n"
#define printElement 	"Displaying picked element\n"
#define printReversable "Displaying only reversable elements\n"
#define sizeBefore		"Size before:%d\n"
#define sizeCurrent 	"\nCurrent size:%d\n"
#define sizePred 		"\nPredetermined size: %d\n"
#define sizeSet 		"Set size:"
#define comLnArg		"Use command line arguments?(1 to accept)\n"
#define comLnNoArg		"No arguments found\n"


void clearToEOL( void ) // Clear to end of line
{
	char ch;
	ch=getchar();
	while(ch != '\n' )
		ch=getchar();
}


int reverseNumber( int number){//function from the previous task
	
    int times = 1;
    int a,newNumber;
    if (number/10 == 0){
        return number;
    }
    else{
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
    return newNumber;
}

int stringToInt(char str[]){
	int i=0;
	int integer=0;
	while(1){
		if (((str[i]-'0')>=0)&&((str[i]-'0')<=9)){
				integer=integer*10 + (str[i]-'0');	
				i++;
		}else {
			break;
		}	
	}
	return integer;
	clearToEOL();
}

int menuChoice(){
	int validInput=0;
	char userInput=' ';
	printf("\nMake a choice:\n");
	printf("1 - Type in new array\n");
	printf("2 - Generate a new array \n");
	printf("3 - Pick an element to change \n");
	printf("4 - Pick an element to delete \n");
	printf("5 - Insert new element \n");
	printf("6 - Pick an element to view \n");
	printf("7 - Display entire array\n");
	printf("8 - Display only reversable numbers\n");
	printf("9 - Leave only reversable numbers\n");
	printf("0 - exit\n");
	do { //in-build VALIDATION for a single char
		scanf("%c",&userInput);
		validInput=userInput-'0';
		clearToEOL();
		if (!((0 <= validInput)&&(validInput <= 9))){
			printf("\n Not a valid input\n");
		}
	}while(!((0 <= validInput)&&(validInput <= 9)));
return validInput;
}

void validation(long int *anyNumber){// Validation for an integer
	long int anyNumberCopy=1;
    do{

        if (!((scanf("%5ld",&anyNumberCopy) == 1) && (getchar() == '\n'))){
			clearToEOL();
            printf("that was not a valid number\n");
            printf("Try again: ");
        }
        else if (! ((anyNumberCopy <= MAXVALUE) && (anyNumberCopy >= 0)) ){
                printf("Please enter a number in ranges [0;32768]\n");
                printf("Try again: ");
        }
        else {
            *anyNumber=anyNumberCopy;
            break;
        }

    }while (1);
}

void getMemory(int** array1,int arraySize){
    *array1= malloc(arraySize*sizeof(int));
};

void relocateMemory(int** array1,int arraySize){
    *array1= realloc(*array1,arraySize);
};

int generateRand(){// Returns random positive integer
    int result=0;
    result=(rand()%MAXVALUE);//[0;32768]
    return result;
}


int main (int argc, char *argv[])
{	
	long int tempNumber=0;
	int size=0;
	int i=0;
	int j=0;
	int predSize=0;
	printf(comLnArg);//Command line argument handling
	validation(&tempNumber);
	if (tempNumber==1){
		if((argc!=1)){
			printf(inputFound,argv[1]);
			size=stringToInt(argv[1]);
			printf(sizeCurrent,size);
			predSize=1;
		}else printf(comLnNoArg);
	}
	
	int index=0;
	int choice=8;
	int* array;
	int* copyArray;
	int arrayIsPresent=0;
	
	//Menu initializing
	
	choice=menuChoice();
	
	while (!(choice==0)){//Check size was passed through command line arguments
		if((predSize)&&(size>0)){
			printf(sizePred,size);
		}else{
			printf(sizeCurrent,size);
		}	
		switch(choice)
		
		{
			
			case 1 : //Type new array
				if (arrayIsPresent){
					free(array);
				}
				if (size<1){
				predSize=0;
				}
				if (!predSize){		//Check if predetermined size is gone
					printf(sizeSet"\n");
					validation(&tempNumber);
					size=tempNumber;
				}
					getMemory(&array,size);
					for ( i=0;i<size;i++){
						printf(numberWithIndex,i);
						validation(&tempNumber);
						array[i]=tempNumber;
					} 
					if (size>0){
						arrayIsPresent=1;
						}		
				break;
				
			case 2 : //Generate new array
				if (arrayIsPresent){
					free(array);
				}
				if (size<1){
				predSize=0;
				}
				if (!predSize){		//Check if predetermined size is gone
					printf(sizeSet);
					validation(&tempNumber);
					size=tempNumber;
					}
				getMemory(&array,size);
				srand(time(NULL));
				for ( i=0;i<size;i++){
					array[i]=(generateRand()%MAXVALUE-1);
				} 
				if (size>0){
					arrayIsPresent=1;
					}
					printf(arrayGenerated);
				break;
				
			case 3 : //Change element
				
				if (!arrayIsPresent){
					printf("%s\n",ArrPres);
					break;
				}
				do {
					printf(elementIndex,size-1);
					validation(&tempNumber);
				}while (tempNumber>=size);
				index=tempNumber;
				printf(elementValue);
				validation(&tempNumber);
				array[index]=tempNumber;
				printf(elementChanged);
				break;
				
			case 4 : //Delete element
				if (!arrayIsPresent){
					printf("%s\n",ArrPres);
					break;
				}
				
				do {
					printf(elementIndex,size-1);
					validation(&tempNumber);
				}while (tempNumber>=size);
				index=tempNumber;
				for (i=index;i<size;i++){
					array[i]=array[i+1];
				}
				printf(elementDeleted);
				size--;
				relocateMemory(&array,size);
				if (size==0){
					arrayIsPresent=0;
				}
				break;
			
			case 5 : //Insert element
				if (!arrayIsPresent){
					printf("%s\n",ArrPres);
					break;
				}
				size++;
				relocateMemory(&array,size);
				printf("Type 1 if you want to insert it to the end, any other number otherwise\n");
				validation(&tempNumber);
				if (tempNumber ==1) {
					printf(elementValue);
					validation(&tempNumber);
					array[size-1]=tempNumber;
				}else
					{
						do {
							printf(elementIndex,size-2);
							validation(&tempNumber);
						}while (tempNumber>size-1);
						index=tempNumber;
						relocateMemory(&array,size);
						for(i=(size);i>index;i--){
							array[i]=array[i-1];
						}
						printf(elementValue);
						validation(&tempNumber);
						array[i]=tempNumber;
						printf(elementInserted);
					}
				break;
				
			case 6 : //Print element
				if (!arrayIsPresent){
					printf("%s\n",ArrPres);
					break;
				}
				do {
					printf(elementIndex,size-1);
					validation(&tempNumber);
				}while (tempNumber>size);
				printf(printElement);
				printf("%d\n",array[tempNumber]);
				
				break;
				
			case 7 : //Print Entire array
				printf(printArray);
				if (!arrayIsPresent){
						printf("%s\n",ArrPres);
						break;
				}
				for (i=0;i<(size)-1;i++){
					printf("%d ",array[i]);
					if (((i+1)%10)==0){
						printf("\n");
					}
				}
				printf("%d\n",array[i]);
				break;
				
			case 8 : //Print Reversable
				printf(printReversable);
				if (!arrayIsPresent){
						printf("%s\n",ArrPres);
						break;
				}
					for (i=0;i<(size);i++){
						if (reverseNumber(array[i])==array[i]){
							printf("%d\n",array[i]);
						}	
					}
				break;
			
			case 9 : //Leave only Reversable
				if (!arrayIsPresent){
					printf("%s\n",ArrPres);
					break;
				}
				//Kopijavimas, nes ties 6-8 elementu neaiskus overflow prasidedavo
				getMemory(&copyArray,size);
					for (j=0,i=0;i<(size);i++){
							if (reverseNumber(array[i])==array[i]){
								copyArray[j]=array[i];
								j++;
							}
						}
					free(array);					
					size=j;
					getMemory(&array,size);
					for (j=0,i=0;i<size;i++,j++){
							array[j]=copyArray[i];
					}
					printf(leaveReversable);
					printf(sizeCurrent,size);
				break;	
				
				default:{
					break;
				}
		}
		
		choice=menuChoice();
	
	}//end of menu loop
	printf("\nTHE END \n");
    return 0;

}





