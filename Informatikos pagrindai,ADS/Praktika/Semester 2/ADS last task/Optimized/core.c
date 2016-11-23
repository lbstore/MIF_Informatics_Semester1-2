#include <stdio.h>
#include <stdlib.h>

#define DISPLAY_PROGRESS 0 // change to 0 if display only answer
#define arSize 10

typedef struct set{
	int *data;
	int size;
	int *iArray;
	int elemSum;
	int iter;
}set;

void printArray(int *arr, int arraySize){
	int i;
	for (i = 0; i<arraySize; i++){
		printf("%d ",arr[i]);
	}
}
void printATS(set set1, set set2){
	int i = 0;
	printf("\nATS:\n\t{");
	for(i = 0; i < set1.elemSum; i++){
		printf("%d",set1.data[set1.iArray[i]]);
		if ((i+1)<set1.elemSum)
			printf(", ");
	}
	printf(", ");
	for(i = 0; i < set2.elemSum; i++){
		printf("%d",set2.data[set2.iArray[i]]);
		if ((i+1)<set2.elemSum)
			printf(", ");
	}
	printf("}\n");
}
void switchArray(int *array1, int *array2){
	int tmp = 0;
	int i = 0;
	for (; i < arSize; i++){
		tmp = array1[i];
		array1[i] = array2[i];
		array2[i] = tmp; 
	}
}
void seperate(int* initialArr,int *arrN, int *arrP, int arrSize){
	int i=0;
	int index1=0;
	int index2=0;
	for (i=0;i<arrSize;i++){
		if (initialArr[i]<0){
			arrN[index1]=initialArr[i];
			index1++;
		} else {
			arrP[index2]=initialArr[i];
			index2++;
		}
	}
	if (index1 < index2){
		switchArray(arrN,arrP);
	}
}
void resetArray(set *theSet){
	int i=0;
	for (i=0;i<theSet->size;i++){
		theSet->iArray[i]=i;
	}
}
void copyArray(int *arrayDest, int *arraySource, int arraySize){
	int i=0;
	for(; i<arraySize; i++){
		arrayDest[i] = arraySource[i];
	}
}
void minimizeArray(int* array, int *arraySize){
	int i = *arraySize-1;
	int locSize = *arraySize;
	for(; i>=0; i--){
		if (array[i] == 0){
			locSize--;
		}
	}
	if (locSize != *arraySize){
		array = realloc(array,locSize*sizeof(int));
		*arraySize = locSize;
	}
	
}






int incIndexArray(int index, set *theSet){
	//index - paskutinio elemento vieta
	//indexAm - kiek elementu sumoje   
	//arraySize - kiek elementu masyve    
	//max = arraySize-indexAm + index;
	int result;
	int max = theSet->size - theSet->elemSum + index;
	if (theSet->iArray[index] == max){
		result = incIndexArray(index-1, theSet); 
	} else if (index >= 0) {
		theSet->iArray[index]++;
		int i = index;
		for (; i <= theSet->elemSum; i++){
			theSet->iArray[i+1]=theSet->iArray[i]+1;
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

int findSum(set *theSet){
	int sum = 0;
	int i = 0;
	for (; i<theSet->elemSum; i++){
		sum+=theSet->data[theSet->iArray[i]];
	}
	return sum;
}

int DoTheThing(set *theSet, int theSum){
		theSet->elemSum = 1;
		int startingIndex = theSet->elemSum - 1;
		int status = 1;
		int end = 0;
		int found = 1;
	
	while (end == 0){
			if (0 == theSum + findSum(theSet)){
				end = 1;
				#if DISPLAY_PROGRESS
					printf("local found\n");
				#endif
				break;
			} else{
				theSet->iter++;
				
				#if DISPLAY_PROGRESS	
					printArray(theSet->iArray,theSet->elemSum);
					printf(" s: %d %d ",findSum(theSet), theSum);
				#endif	
				status = incIndexArray(startingIndex,theSet);
				#if DISPLAY_PROGRESS
					printf("status:%d \n",status);		
				#endif	
				if (status == 0){
					theSet->elemSum++;
					startingIndex = theSet->elemSum - 1;
					#if DISPLAY_PROGRESS
						printf("%d out of %d\n",theSet->elemSum, theSet->size);
					#endif	
					if (theSet->elemSum > theSet->size){
					#if DISPLAY_PROGRESS	
						printf("\nLocal No combination was found \n");	
					#endif
						end = 1;
						found = 0;
					} else {
						resetArray(theSet);
						#if DISPLAY_PROGRESS
							getchar();
						#endif
					}
				}
			}
		}
	return found;
}
int main(int argc, char **argv){

	int initialArray[arSize] = {10,16,10,-11,-12,-13,99,99,99,99};
	//int initialArray[arSize] = {6,5,4,3,2,1,9,12,-21,-8};
	//int initialArray[arSize] = {1,2,3,4,5,6,7,8,9,10};
	//int initialArray[arSize] = {-40,1,9,8,2,4,6,7,3,-35};
	
	int *mainArray;
	mainArray = malloc(arSize*sizeof(int));
	copyArray(mainArray,initialArray,arSize);
	
	set Parray;
	Parray.data = malloc(arSize*sizeof(int));
	Parray.size = arSize;
	set Narray;
	Narray.data = malloc(arSize*sizeof(int));
	Narray.size = arSize;
	seperate(initialArray, Narray.data, Parray.data, arSize);
	
	#if DISPLAY_PROGRESS
	
	printArray(Narray.data, Narray.size);printf("\n");
	#endif
	minimizeArray(Narray.data, &Narray.size);
	#if DISPLAY_PROGRESS
	printArray(Narray.data, Narray.size);
	printf("\n\n");
	printArray(Parray.data, Parray.size);printf("\n");
	#endif
	minimizeArray(Parray.data, &Parray.size);
	#if DISPLAY_PROGRESS
	printArray(Parray.data, Parray.size);
	getchar();
	#endif
	
	if((Narray.size == arSize)||(Parray.size == arSize)){
		printf("\nNo data diversity\nImpossible to find\n");
	} else {
	
	

		int status = 1;
		int end = 0;
		int found = 0;
		int firstSum = 0;
		
		
		Parray.iter = 1;
		Parray.iArray = malloc(Parray.size*sizeof(int));
		
		
		Narray.elemSum = 1;
		Narray.iter = 1;
		Narray.iArray = malloc(Narray.size*sizeof(int));
		resetArray(&Narray);
		
		int startingIndex = 0;
		startingIndex = Narray.elemSum -1;
		while (end == 0){
			firstSum = findSum(&Narray);
			found = DoTheThing(&Parray, firstSum);
			if (found){
			#if DISPLAY_PROGRESS	
					printf("FOUND");
			#endif		
				end = 1;
				break;
			} else {
				Narray.iter++;
				#if DISPLAY_PROGRESS	
					printArray(Narray.iArray, Narray.elemSum);
				#endif	
				status = incIndexArray(startingIndex, &Narray);
				#if DISPLAY_PROGRESS
					printf(" status:%d \n",status);
				#endif	
				if (status == 0){
					Narray.elemSum++;
					startingIndex = Narray.elemSum - 1;
					#if DISPLAY_PROGRESS
						printf("\nFIRST CYCLE: %d out of %d\n", Narray.elemSum, Narray.size);
					#endif	
					if (Narray.elemSum > Narray.size){
						printf("\nNo combination was found \n");
						end = 1;
						found = 0;
					} else {
						#if DISPLAY_PROGRESS
							getchar();
						#endif	
						resetArray(&Narray);
					}
				}
			}
		}
		if (found){
			#if DISPLAY_PROGRESS
			printf("\n\n%d ",Narray.elemSum);
			printf("%d \n",Parray.elemSum);
			#endif
			printATS(Narray, Parray);
		}
	
		printf("\nIterations: %d",Parray.iter + Narray.iter);
	}
	printf("\n\nTHE END");
	getchar();
	return 0;
} 
