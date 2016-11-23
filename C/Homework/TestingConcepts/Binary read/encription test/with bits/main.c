#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
int charToInt(char chr){
	int number = chr;
	number = number + 5;
	return number;
} 
char intToChar(int itn){
	itn = itn - 5;
	char chr = itn;
	return chr;
}

void parseFileToInt(FILE* data, FILE* dataOut){
	rewind(data);
	char c1;
	int i = 0;
	int count = 0;
	char cLine[1024]; memset(cLine,0,sizeof(cLine));
	char iLine[1024]; memset(iLine,0,sizeof(iLine));
	while(!(feof(data))){	
		c1 = fgetc(data);
		if (c1 == '\n'){
			i = 0;
			iLine[count] = 35;
			count++;
			for (; i<count; i++){
				fwrite(dataOut,"%d ",iLine[i]);
			}
			fprintf(dataOut,"\n");
			memset(cLine,0,sizeof(cLine));
			count = 0;
		} else if (!(feof(data))) {
			
			cLine[count] = c1;
			iLine[count] = charToInt(c1);
			count++;
			
		}
	}
}

void parseFileToChar(FILE *data, FILE *dataOut){
	rewind(data);
	char c1;
	int i2 = 0;
	char str1[10];
	int number1;
	char cLine[1024]; memset(cLine,0,sizeof(cLine));
	char iLine[1024]; memset(iLine,0,sizeof(iLine));	
	
	while(!(feof(data))){
		fread(&c1,1,1,data);
		
		if (c1 != ' '){
			str1[i2] = c1;
			i2++;
		} else if (35 != atoi(str1)){
			number1 = atoi(str1);
			fprintf(dataOut,"%c",intToChar(number1));
			memset(str1,0,sizeof(str1));
			i2 = 0;		
		} else {
			i2 = 0;
			memset(str1,0,sizeof(str1));
			fprintf(dataOut,"\n");
		}	
	}
}

 
int main(int argc, char** argv){
	FILE *doc,*rez,*rezB,*rezInt,*docInt;
	char line[1024];
	int lineInt[1024];
	int array[1024];
	char lineC[1024];
	memset(line,0,sizeof(line));
	memset(lineInt,0,sizeof(lineInt));
	memset(lineInt,0,sizeof(lineC));
	memset(array,0,sizeof(array));


	
	
	
	rezInt = fopen("textInt.txt","w");
	doc = fopen("textDoc.txt","r");
	parseFileToInt(doc,rezInt);
	fclose(rezInt);
	docInt = fopen("textInt.txt","r");
	rez = fopen("textRez.txt","w");
	parseFileToChar(docInt,rez);
	
	
	fclose(rez);
	//fclose(rezB);
	
	printf("EXIT\n");
	return 0;
}
