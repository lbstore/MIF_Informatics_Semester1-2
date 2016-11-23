#include <stdlib.h>
#include <stdio.h>

void r(int *b){ 
		do{
			scanf("%d",b);
			
			if ((getchar()!='\n')){
				while(getchar()!='\n');
				printf("Wrong input, enter a number between [1..14]\n");
			}else if ((*b<1)||(14<*b)){
				printf("Wrong input, enter a number between [1..14]\n");
				}
				else {
					break;	
				}
			}while (1);
		}
		
void f(int *a,int *b){
	int i;
		*(a)=1;
		for (i=1;i<*b;i++){
			a[i]=a[i-1]*i;
		}
	}

int main(){
	printf("Type a number, and you will see all factorials to your number (max 14)\n");
	int *b;
	r(b);
	int *a= malloc(*b*sizeof(int)); 	
	f(a,b);
	int i=0;
	for(i=0;i<*b;printf("%d -  %d\n",i-1,a[i++]));
	
	system("PAUSE");
	return 0;
	
	}
	


