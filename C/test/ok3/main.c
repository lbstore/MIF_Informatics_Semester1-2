

#include <stdlib.h>
#include <stdio.h>


int compare(void *a,void *b){

	int A = *((int*)a);
	int B = *((int*)b);
	printf("%d %d\n",A,B);
	int rez=A-B;
	return rez;
}

typedef struct node{
	void* i;
}node;
int main(int argc, char **argv)
{
	void* ptr1;
	void* ptr2;
	int n1=5;
	int n2=8;
	ptr1=&n1;
	ptr2=&n2;
	int res;
	res=compare(ptr1,ptr2);
	printf("%d\n\n",res);
	node* ok;
	ok->i=&n1;
	printf("%d",compare(ok->i,ptr2));
	return 0;
}

