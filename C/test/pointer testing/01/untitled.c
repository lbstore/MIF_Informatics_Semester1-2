
#include <stdio.h>

int main(int argc, char **argv)
{
	int a=5;
	int *b;
	int c=9;
	printf("%d %d\n",a,c);
	b=&a;
	c=*b;
	printf("%d %d",a,c);
	
	
	return 0;
}

