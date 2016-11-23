#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
int charToInt(char chr){
	int number = chr;
	return number;
} 
char intToChar(int itn){
	char chr = itn;
	return chr;
}

int main(int argc, char **argv)
{
	
	int number = 10;
	char c = 'K';
	number = charToInt(c);
//	printf("%c\n",intToChar(number));
	printf("%d\n",number);
	c = intToChar(number);
	printf("%c",c);
	return 0;
}

