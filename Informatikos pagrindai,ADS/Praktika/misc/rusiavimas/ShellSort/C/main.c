

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXVALUE 99999999
void shellsort (long masyvas[], int elem_sk)
{
  int i, j, k, zingsnis, elem;
  int zingsniai[] = {4356424, 1355339, 543749, 213331, 84801, 27901,
                     11969, 4711, 1968, 815, 277, 97, 31, 7, 3, 1};
   for (k=0; k<16; k++)
   {
     zingsnis = zingsniai[k];
     for (i=zingsnis; i<elem_sk; i++)
     {
       elem=masyvas[i];
       j=i;
       while ((j>=zingsnis) && (masyvas[j-zingsnis]>elem))
       {
         masyvas[j]=masyvas[j-zingsnis];
         j=j-zingsnis;
       }
       masyvas[j]=elem;
     }
   }
}


void printThis(long arr[], int size){
	int c = 0;
	for(; c<size; c++){
		printf("%li ",arr[c]);
		if ((c+1)%7 == 0) printf("\n");
	}
}
int main(int argc, char **argv)
{
	long *array;
	int i;
	int arraySize = 56;
	srand(time(NULL));
	array = malloc(arraySize*(sizeof(long)));
	for ( i=0;i<arraySize;i++){
		array[i]=(rand()%MAXVALUE-1);
		printf("%li ",array[i]);
		if ((i+1)%7 == 0) printf("\n");
	} 
	printf("\nSORTING\n\n");
	shellsort(array, arraySize);
	printThis(array, arraySize);
	return 0;
}

