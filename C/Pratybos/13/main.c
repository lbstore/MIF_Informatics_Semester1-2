
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TEST 0

#if TEST
#define fileName "file2.bin"
#endif
int main(int argc, char **argv)
{
#if TEST == 0	
	char fileName[30];
#endif	
	char c = ' ';
	int uppercount = 0;
	int zerocount = 0;
	int fourDig = 0;
	int evencount = 0;
	int value = 0;
	FILE *doc;
	
#if TEST
	doc = fopen(fileName,"rb");
	
#else
	printf("Type your source name (with extension):");
	scanf("%30s",fileName);
	doc = fopen(fileName,"rb");			
#endif	
	if(doc == NULL){
		printf("Incorrect name\n");
	} else 
	{
	printf("File found\n");

	//UPPERCASE
		while (!(feof(doc))){
			fread(&c,sizeof(char),1,doc);
			if (isupper((int)c)){
				uppercount++;
			}
		}
		
	//ZEROES	
		rewind(doc);
		while (!(feof(doc))){
			fread(&value,sizeof(int),1,doc);
			if (!(value)){
				zerocount++;
			}
		}
		
	//4 DIGITS	
		rewind(doc);
		while (!(feof(doc))){
			short v;
			fread(&v,sizeof(short),1,doc);
			int check = v / 1000;	
			if (((check % 10) == check)&&(check !=0)){
				fourDig++;
			}
		}	
		
		
	// MIN MAX AVG	
		rewind(doc);
		float sum = 0;
		int ammount = 0;
		float min,max;
		float f = 0;
		while(f<1){
			fread(&f,sizeof(float),1,doc);
			min = f;
			max = f;
		}
		sum +=f;
		ammount++;
		while (!(feof(doc))){
			fread(&f,sizeof(float),1,doc);
			if (f > 1){
				if (f < min){
					min = f;
				}
				if (f > max){
					max = f;
				}
				sum += f;
				ammount++;
			}
			
		}

		
	//EVEN 
		rewind(doc);
		while (!(feof(doc))){
			int val=0;
			fread(&val,3,1,doc);
			
			if ((!(val % 2))&&(val !=0)){
				evencount++;
			}
		}	

	//LINE LENGHT
		rewind(doc);
		int maxLen = 0;
		int minLen = 0;
		int currentLen = 0;
		int change = 0;
		while (!(feof(doc))){
			
			fread(&c,sizeof(char),1,doc);
			change = 0;
			while (((c != 0))&&(!(feof(doc)))){
				
				currentLen++;
				change = 1;
				fread(&c,sizeof(char),1,doc);		
			}
			if (change){
				if (minLen == 0){
						minLen = currentLen;
					}
				if (currentLen > maxLen){
					maxLen = currentLen;	
				}
				if ((currentLen < minLen)&&(currentLen !=0)){
					minLen = currentLen;
				}
			}
			currentLen = 0;
		}	

			
		fclose(doc);
		printf("\nRESULTS\n");
		printf("1) UpperCase: %d\n",uppercount);
		printf("2) Zeroes: %d\n",zerocount);
		printf("3) 4 Digits: %d\n",fourDig);
		printf("4) Min:%.2f\tMax:%.2f\tAverage:%.2f\n",min, max, sum/ammount);
		printf("5) Even numbers: %d\n",evencount);
		printf("6) Min Lenght: %d\tMax Lenght: %d\n",minLen, maxLen);
		
	}
	printf("\nProgram EXIT");
	getchar();
	return 0;
}

