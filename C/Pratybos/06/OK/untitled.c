#include <stdlib.h>
#include <stdio.h>

void r(int *b){ 

		scanf("%d",b);
		}
		
void f(int *a,int *b){
	int i;
		*(a)=1;
		for (i=1;i<*b;i++){
			a[i]=a[i-1]*i;
		}
	}

int main(){
	
	int *b;
	r(b);
	int *a= malloc(*b*sizeof(int)); 	
	f(a,b);
	int i=0;
	for(i=0;i<*b;printf("%d - %d \n",i-1,a[i++]));
	
	system("PAUSE");
	return 0;
	
	}
	


