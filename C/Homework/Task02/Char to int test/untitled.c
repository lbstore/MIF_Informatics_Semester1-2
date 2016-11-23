
#include <stdio.h>
#include <stdlib.h>

void clearToEOL( void )
{
	char ch;
	ch=getchar();
	while(ch != '\n' )
		ch=getchar();
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

int main(int argc, char **argv)
{
	int number=0;
	char string[10]="12ok";
	number=stringToInt(string);
	printf("\n");
	printf("%d",number);
	return 0;
}

