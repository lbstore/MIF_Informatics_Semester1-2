#include <stdio.h>

int isSeparator(char c1){
	int asc=c1;
	int result=1;
	if (((asc>='0')&&(asc<='9'))||((asc>='A')&&(asc<='Z'))||((asc>='a')&&(asc<='z'))){
		result=0;	
	}
	return result;
}

int main(int argc, char **argv)
{
	char c;
	char fileName[20];
	FILE *fptr;
	FILE *doc;
	FILE *rez;
	fptr = NULL;
	if (argc==1){
			printf("Type your file name (with extension(if there is one):");
			do {
				scanf("%20s",fileName);
				fptr = fopen(fileName,"r");	
				
			}while (fptr == NULL);
					
				doc=fopen(fileName,"r");
				rez=fopen("rezFile","w");
		} else if (argc==2){
				fptr = fopen(argv[1],"r");
			if (fptr != NULL){
				doc=fopen(argv[1],"r");
				rez=fopen("rezFile","w");
				printf("File found\n");
				}
		} else if (argc==3){
			fptr = fopen(argv[1],"r");
			if(fptr != NULL){
				doc=fopen(argv[1],"r");
				rez=fopen(argv[2],"w");
				printf("2 Files found\n");
			}
		} else {
			printf("Invalid command line arguments\n");
		}
	if (fptr != NULL){	
		c = fgetc(doc);
		while(!(feof(doc))){

			if (isSeparator(c)){
				fprintf(rez,"\n");		
			} else {			
				fprintf(rez,"%c",c);
			}
			c = fgetc(doc);
		}
	fclose(fptr);
	fclose(doc);
	fclose(rez);
	} else {
		printf("No files found\n");
	}

	printf("\nProgram Exit =  Success\n");
	return 0;
}

