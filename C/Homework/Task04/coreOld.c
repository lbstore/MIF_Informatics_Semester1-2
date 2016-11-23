#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TESTING 1 //change to 0 to type files manually
#define Output 0 //change to 0 to view contents in console window
FILE *doc;
FILE *rez;

typedef struct listType{
	char date[11];
	char time[6];
	char header[1024];
	char paragraph[1024];
	int pos;
	struct listType* next;
}listType;

	


listType* createNode(char Edate[], char Etime[], char Eheader[], char Eparagraph[], int Epos){
	listType *res = NULL;
	res = (listType*) malloc(sizeof(listType));
	strcpy(res->date, Edate);
	strcpy(res->time, Etime);
	strcpy(res->header, Eheader);
	strcpy(res->paragraph, Eparagraph);
	res->pos = Epos;
	return (res);
}

void copyContent(listType *dest, listType *source){
	if (dest == NULL){
		dest = (listType*) malloc(sizeof(listType));
	}
	strcpy(dest->date, source->date);
	strcpy(dest->time, source->time);
	strcpy(dest->header, source->header);
	strcpy(dest->paragraph, source->paragraph);
	dest->pos = source->pos;
}



void printNode(listType *node){
	printf("Nr.%d Published: %s %s\n",node->pos,node->date, node->time);
	printf("%s\n",node->header);
	printf("%s\n\n",node->paragraph);
	
}

void printNodeToFile(listType *node){
	fprintf(rez,"Nr.%d Published: %s %s\n",node->pos,node->date, node->time);
	fprintf(rez,"%s\n",node->header);
	fprintf(rez,"%s\n\n",node->paragraph);
}

void traverseList(listType *node, char Etitle[]){
	#if Output
		fprintf(rez,"\nTitle:%s\n",Etitle);
	#else 
		printf("\nTitle:%s\n",Etitle);	
	#endif
	while(node){
		#if Output
			printNodeToFile(node);
		#else
			printNode(node);
		#endif	
		node = node->next;
	}
}


listType *listCreate(listType *source){
	listType *newNode;
	if(!(newNode = malloc(sizeof(listType)))) return NULL;
	copyContent(newNode,source);
	newNode->next = NULL;
	return newNode;
}

listType *listInsertBeg(listType *theList, listType *source){
	listType * newNode;
	newNode = listCreate(source);
	newNode->next = theList;
	return newNode;
}

/*
void initializeNode(listType* theList){
	memset(theList->date, 0, sizeof(11));
	memset(theList->time, 0, sizeof(6));
	memset(theList->header, 0, sizeof(1024));
	memset(theList->paragraph, 0, sizeof(1024));
	theList->next = NULL;
}
*/

int isSeparator(char c1){
	int asc=c1;
	int result=1;
	if (((asc>='0')&&(asc<='9'))||((asc>='A')&&(asc<='Z'))||((asc>='a')&&(asc<='z'))){
		result=0;	
	}
	return result;
}

int isTitle(char* result){
	char *tit = ("<title");
	if(strcmp(result,tit)){
		printf("%6s",result);
	}
	return (strcmp(result,tit));
}

void readTag(char result[]){
	int i=0;
	char c;
	for(i=0;i<10;i++){
		result[i] = 0;
	}
	result[0] ='<';
	c = fgetc(doc);
	i=1;
	while(!(isSeparator(c))){
		result[i] = c;
		c = fgetc(doc);
		i++;
	}
}



int main(int argc, char **argv)
{
	int i; char c;
	char title[100];
	listType *list;
	listType *tmp;
	
	
	
	char tag[10];
	char anyHeader[1024];
	char anyDate[11];
	char anyTime[6];
	char anyParagraph[1024];
	
	
#if TESTING == 0
	
	int tries = 0;
	char fileName[30];
	FILE *fptr;
	fptr = NULL;
	printf("Type your source name (with extension):");
	do {
		if(tries){
			printf("Try again:");
		}
		scanf("%30s",fileName);
		fptr = fopen(fileName,"r");	
		tries++;
		
	}while (fptr == NULL);		
	doc=fopen(fileName,"r");
	
	fclose(fptr);
	#if Output
	printf("Type your result name :");
	scanf("%30s",fileName);
	rez=fopen(fileName,"w");
	#endif
#else
		
	doc=fopen("VUnaujienos1.html","r");	
	rez=fopen("rezFile","w");
	printf("Testing\n");
#endif
int listAmm = 1;	
	while(!(feof(doc))){
		c = fgetc(doc);
		if (c == '<'){// found tag
			memset(tag, 0, sizeof(tag));
			readTag((tag));
			if (!(strcmp(tag,"<title"))){// set title
				i = 0;
				c = fgetc(doc);
				while (c!='<'){
					title[i] = c;
					i++;
					c = fgetc(doc);
				}
				title[i] = '\0';
			}
			//HEADER
			//NODE STARTS
			if (!(strcmp(tag,"<h2"))){
				
				c = fgetc(doc);
				while (c!='<'){
					c = fgetc(doc);
				}
				while (c!='"'){
					c = fgetc(doc);
				}
				c = fgetc(doc);
				i = 0;
				memset(anyHeader, 0, sizeof(anyHeader));
				do {
					anyHeader[i] = c;
					i++;				
					c = fgetc(doc);		
				} while (c!='"');
				anyHeader[i] = '\0';

				int foundDate = 0;
				
					while(!(foundDate)){
						c = fgetc(doc);
						if ((c == '<')){
						
							memset(tag, 0, sizeof(tag));
							readTag((tag));
							if(!(strcmp(tag,"<span"))){
								while(!(c =='>')){
									c = fgetc(doc);
								}
								//DATE
								memset(anyDate, 0, sizeof(anyDate));
								for(i = 0; i<10; i++){
									c = fgetc(doc);
									anyDate[i] = c;
								}
								anyDate[10] = '\0';
								c = fgetc(doc);
								//TIME
								memset(anyTime, 0, sizeof(anyTime));
								for(i = 0; i<5; i++){
									c = fgetc(doc);
									anyTime[i] = c;
								}
								anyTime[5] = '\0';
								foundDate = 1;
							}
						}
					}
					
					int foundP = 0;
					while(!(foundP)){
					c = fgetc(doc);
					if ((c == '<')){
						memset(tag, 0, sizeof(tag));
						readTag(tag);
					}
					//PARAGRAPH
					if(!(strcmp(tag,"<p"))){
						c = fgetc(doc);
						i = 0;
						memset(anyParagraph,0,sizeof(anyParagraph));
						while(c !='<'){
							anyParagraph[i] = c;
							i++;
							c = fgetc(doc);
						}
						anyParagraph[i] = '\0';
						foundP = 1;
					}
				}
				//created Node
				tmp = createNode(anyDate, anyTime, anyHeader, anyParagraph, listAmm);
				//printNode(tmp);
				if (listAmm>1){
					list = listInsertBeg(list,tmp);
				} else {
					list = listCreate(tmp);
				}
				listAmm++;
				//printf("%d",listAmm);
			}
			
		}
	}
	
	fclose(doc);
	traverseList(list,title);
	fclose(rez);
	free(list);
	printf("\nProgram Exit =  Success\n");
	getchar();
	return 0;
}

 
