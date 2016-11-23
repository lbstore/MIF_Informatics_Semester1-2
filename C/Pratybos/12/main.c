#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define epsilon 0.0001

typedef struct doubleSpaceType{
	int realPart;
	int intPart;
}doubleSpaceType;

typedef struct Elem{
	char str[30];
	int i;
	double d;
	doubleSpaceType dF;
}Elem;


int findNameSpace(Elem arr[],int len){
	int j;
	int max=strlen(arr[0].str);
	for (j=1;j<len;j++){
		if (max<strlen(arr[j].str)){
			max=strlen(arr[j].str);
		}
	}
	return max;
}

int findIntSpace(Elem arr[], int len){
	int j;
	int max=0;
	int el;
	for (j=0;j<len;j++){
		el=arr[j].i;
		int locMax=0;
		if (el<0){
			locMax++;
			el=el*(-1);
		}
		while (el>0){
			locMax++;
			el=el/10;
		}
		if (locMax>max){
			max=locMax;
		}
	}
	return max;
}

int findRealSpace(Elem arr[], int len){
	int j;
	int max=0;
	double el;
	for (j=0;j<len;j++){
		el=arr[j].d;	
		int locMax=0;
		if (el<0){
			el=el*(-1);
			locMax++;
		}
		while (el>1){//reduce to real part
			el--;
		}
		while (el>epsilon){
			
			locMax++;
			el=el/10;
		}
		if (locMax>max){
			max=locMax;
		}
	}
	
	return max;
}

int removeZeroes(int e){
	while ((e % 10)==0){
		 e=e/10;
	 }
	return e; 
}



doubleSpaceType findDoubleSpace(Elem arr[], int len){
		int j;
		doubleSpaceType max;
		Elem INTarray[len];
		
		max.realPart=findRealSpace(arr,len);
		for (j=0;j<len;j++){
			INTarray[j].i=(int)arr[j].d;
			arr[j].dF.intPart=INTarray[j].i;
			int negative=0;
			if (arr[j].d<0){
				arr[j].d*=(-1);
				negative=1;
			}
			double el=arr[j].d;
			while (el>1){//reduce to real part
				el--;
			}
			int multipLoc=10;
			while (el>epsilon){
				
				el=el/10;
				multipLoc=multipLoc*10;
			}
			if (negative){
				arr[j].dF.intPart*=(-1);
				arr[j].dF.realPart*=(-1);
			}
			arr[j].dF.realPart=(arr[j].d*multipLoc) - (arr[j].dF.intPart*multipLoc);
			if (negative){
				arr[j].dF.intPart*=(-1);
			}
			arr[j].dF.realPart=removeZeroes(arr[j].dF.realPart);
		}
		max.intPart=findIntSpace(INTarray,len);
		
	return max;
}


int main(int argc, char **argv){
	int nameSpace,intSpace;
	doubleSpaceType doubleSpace;
	Elem arr[4];

	Elem e1={"OK",3,2.1002};
	arr[0]=e1;
	Elem e2={"Hi",2,-11100.922222};
	arr[1]=e2;
	Elem e3={"Whatever",-10000,112.12349};
	arr[2]=e3;
	Elem e4={"That's it!",9999,0.5};
	arr[3]=e4;
	int index;
	nameSpace=findNameSpace(arr,4);
	intSpace=findIntSpace(arr,4);
	doubleSpace=findDoubleSpace(arr,4);
	printf("String space %d\nint space %d\ndouble space int: %d real: %d\n\n",nameSpace,intSpace,doubleSpace.intPart,doubleSpace.realPart);
	for(index=0;index<4;index++){
		printf("%-*s ",nameSpace,arr[index].str);
		printf("%*d ",intSpace,arr[index].i);
		printf("%*d.",doubleSpace.intPart,arr[index].dF.intPart);
		printf("%-*d\n",doubleSpace.realPart,arr[index].dF.realPart);
	}
	
	
	
	return 0;
} 
