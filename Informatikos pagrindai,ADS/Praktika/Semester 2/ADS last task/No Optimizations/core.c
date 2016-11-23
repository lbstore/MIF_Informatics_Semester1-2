#include <stdio.h>
#include <stdlib.h>

#define DISPLAY_PROGRESS 1 // change to 0 if display only answer
#define arSize 10

void printArray(int *arr, int arraySize){
	int i;
	for (i = 0; i<arraySize; i++){
		printf("%d ",arr[i]);
	}
}
void printATS(int *arr, int *indexArr, int indexAm){
	int i = 0;
	printf("ATS:\n\t{");
	for(; i < indexAm; i++){
		printf("%d",arr[indexArr[i]]);
		if ((i+1)<indexAm)
			printf(", ");
	}
	printf("}\n");
}
void seperate(int ar[],int ar1[], int ar2[], int len){
	int i=0;
	int index1=0;
	int index2=0;
	for (i=0;i<len;i++){
		if (ar[i]<0){
			ar1[index1]=ar[i];
			index1++;
		} else {
			ar2[index2]=ar[i];
			index2++;
		}
	}
}
void resetArray(int *arReset, int arraySize){
	int i=0;
	for (i=0;i<arraySize;i++){
		arReset[i]=i;
	}
}
void copyArray(int *arrayDest, int *arraySource, int arraySize){
	int i=0;
	for(; i<arraySize; i++){
		arrayDest[i] = arraySource[i];
	}
}
/*
void DoTheThing(int ar1[], int ar2[], int arr[]){
	int a=1;
	int b=1;
	int aM=4;
	int bM=6;
	int reza[10]={0};
	int rezb[10]={0};
	int i,j,k=0;
	for (i=0;i<aM;i++){
		for(j=0;j<bM;j++){
		}
	}
	
}
*/

int incIndexArray(int index, int indexAm, int arraySize, int *indexArray){
	//index - paskutinio elemento vieta
	//indexAm - kiek elementu sumoje   
	//arraySize - kiek elementu masyve    
	//max = arraySize-indexAm + index;
	int result;
	int max = arraySize - indexAm + index;
	if (indexArray[index] == max){
		result = incIndexArray(index-1, indexAm, arraySize, indexArray); 
	} else if (index >= 0) {
		indexArray[index]++;
		int i;
		for (i = index; i <= indexAm; i++){
			indexArray[i+1]=indexArray[i]+1;
		}
		result = 1;
	}	
		else 
			result = 0;
			
	return result;
}

int maxIndexArray(int indexAm, int arraySize){
	int i=0;
	int result = 0;
	int index = arraySize-1;
	for(i=0 ; i < indexAm;index--){
		i++;
		result += index;
	}
	return result;
}

int sumIndexArray(int indexAm, int *indexArray){
	int i = 0;
	int sum = 0;
	for(; i < indexAm ; i++){
			sum += indexArray[i];
	}
	return sum;
}

int findSum(int *resultArray, int *indexArray, int indexAm){
	int sum = 0;
	int i = 0;
	for (; i<indexAm; i++){
		sum+=resultArray[indexArray[i]];
	}
	return sum;
}
int main(int argc, char **argv)
{
	//int initialArray[arSize] = {10,16,10,-11,-12,-13,99,99,99,99};
	//int initialArray[arSize] = {6,5,4,3,2,1,9,12,-21,-8};
	int initialArray[arSize] = {1,2,3,4,5,6,7,8,9,10};
	//int initialArray[arSize] = {-40,1,9,8,2,4,6,7,3,-35};
	
	int *mainArray;
	mainArray = malloc(arSize*sizeof(int));
	copyArray(mainArray,initialArray,arSize);
	
		int *inAr;
		int lgh = 1;
		inAr = malloc(arSize*sizeof(int));
		resetArray(inAr,lgh);
		int startingIndex = lgh - 1;
		int ok = 1;
		int end = 0;
		int found = 1;
		int iterations = 1;
		while (end == 0){
			if (0 == findSum(mainArray, inAr, lgh)){
				end = 0;
				break;
			} else{
				iterations++;
				#if DISPLAY_PROGRESS	
					printArray(inAr,lgh);
					printf(" s=%d ",findSum(mainArray,inAr,lgh));
				#endif	
				ok = incIndexArray(startingIndex,lgh,arSize,*(&inAr));
				#if DISPLAY_PROGRESS
					printf("ok%d \n",ok);
				#endif	
				if (ok == 0){
					lgh++;
					startingIndex = lgh - 1;
					#if DISPLAY_PROGRESS
						printf("%d,%d\n",lgh,arSize);
					#endif	
					if (lgh >= arSize){
						printf("\nNo combination was found \n");
						end = 1;
						found = 0;
					} else {
						#if DISPLAY_PROGRESS
							getchar();
						#endif	
						resetArray(inAr, lgh);
					}
				}
			}
		}
	if (found){
		printATS(mainArray, inAr, lgh);
	}
	printf("\nIterations: %d",iterations);
	printf("\n\nTHE END");
	getchar();
	return 0;
} 
