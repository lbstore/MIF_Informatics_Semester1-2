#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define Override 0 //change to not 0 to change passwords
FILE *doc;
FILE *lg; // log file
	

typedef struct content{
	char date[11];
	char time[6];
	char header[1024];
	char paragraph[1024];
	int pos;
}content;

typedef struct listType{
	content data;
	struct listType* next;
}listType;
	
typedef struct password{
	int array[20];
	int type;
	int length;
}password;	

password admin;
password basic;
password input;

void clearToEOL( void ) // Clear to end of line
{
	char ch;
	ch=getchar();
	while(ch != '\n' )
		ch=getchar();
}

listType* createNode(char Edate[], char Etime[], char Eheader[], char Eparagraph[], int Epos){
	listType *res = NULL;
	res = (listType*) malloc(sizeof(listType));
	strcpy(res->data.date, Edate);
	strcpy(res->data.time, Etime);
	strcpy(res->data.header, Eheader);
	strcpy(res->data.paragraph, Eparagraph);
	res->data.pos = Epos;
	return (res);
}

void copyContent(content *dest, content *source){
	if (dest == NULL){
		dest = (content*) malloc(sizeof(content));
	}
	strcpy(dest->date, source->date);
	strcpy(dest->time, source->time);
	strcpy(dest->header, source->header);
	strcpy(dest->paragraph, source->paragraph);
	dest->pos = source->pos;
}



void printNode(content *node){
	printf("Nr.%d   %s   %s\n",node->pos,node->date, node->time);
	printf("%s\n",node->header);
	printf("%s\n\n",node->paragraph);
	
}


void traverseList(listType *node){

	while(node){
		#if Output
			printNodeToFile(node);
		#else
			printNode(&(node)->data);
		#endif	
		node = node->next;
	}
}


listType *listCreate(listType *source){
	listType *newNode;
	if(!(newNode = malloc(sizeof(listType)))) return NULL;
	copyContent(&(newNode)->data,&(source)->data);
	newNode->next = NULL;
	return newNode;
}

listType *listInsertBeg(listType *theList, listType *source){
	listType * newNode;
	newNode = listCreate(source);
	newNode->next = theList;
	return newNode;
}


int isSeparator(char c){
	int asc=c;
	int result=1;
	if (((asc>='0')&&(asc<='9'))||((asc>='A')&&(asc<='Z'))||((asc>='a')&&(asc<='z'))){
		result=0;	
	}
	return result;
}

int isTitle(char* result){
	char *str = ("<title");
	if(strcmp(result,str)){
		printf("%6s",result);
	}
	return (strcmp(result,str));
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


int parseHtml(FILE *doc, listType **list, char Etitle[]){
	rewind(doc);
	listType *tmp;
	int listAmm = 1;
	int i;
	char c;
	char tag[10];
	char anyHeader[1024];
	char anyDate[11];
	char anyTime[6];
	char anyParagraph[1024];
	
		
	while(!(feof(doc))){
		c = fgetc(doc);
		if (c == '<'){// found tag
			memset(tag, 0, sizeof(tag));
			readTag((tag));
			if (!(strcmp(tag,"<title"))){// set title
				i = 0;
				c = fgetc(doc);
				while (c!='<'){
					Etitle[i] = c;
					i++;
					c = fgetc(doc);
				}
				Etitle[i] = '\0';
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
				tmp = createNode(anyDate, anyTime, anyHeader, anyParagraph, listAmm);
				if (listAmm>1){
					*list = listInsertBeg(*list,tmp);
				} else {
					*list = listCreate(tmp);
				}
				listAmm++;
			}
			
		}
		
	}
fprintf(lg,"Html parsed\n");
return listAmm-1;
}

void copyList2Array(listType *list, content *arr, int amm){
	int i = amm-1;
	memset(arr,0,sizeof(amm));
	for (; i >= 0; i--){
		copyContent(&(arr[i]),&(list)->data);
		list = list->next;
	}
}



int login(){
	int pick;
	printf("Pick level of privilegies:\nadmin, basic, guest\n");
	char nick[5];
	memset(nick,0,sizeof(nick));
	int t = 1;
	while(t){
		scanf("%5s",nick);
		clearToEOL();
		if (!(strcmp("admin",nick))){
			printf("\nadmin selected, type password:");
			t = 0;
			pick = 1;
		}else if (!(strcmp("basic",nick))){
			printf("\nbasic selected, type password:");
			t = 0;
			pick = 2;
		}else if (!(strcmp("guest",nick))){
			printf("\nguest mode\n");
			t = 0;
			pick = 0;
		} else {
			printf("\nWrong selection, try again\n");
		}
	}
	return pick;
}

int charToInt(char chr, int salt){
	int number = chr;
	int temp = number;
	number = (temp * (salt+2));
	return number;
}


int str2Numbers(char str[], int numbers[]){
	int i = 0;
	
	while (str[i] != '\0'){
		numbers[i] = charToInt(str[i],i);
		i++;
	}
	return i+1;
}

void storePsw(FILE* psw, password *admin, password *basic){
	rewind(psw);
	char str[20];
	int i;
	int count = 0;
	int numb[20];
	memset(numb,0,sizeof(numb));
	memset(str,0,sizeof(str));
	printf("Password for admin:");
	scanf("%s",str);
	count = str2Numbers(str, numb);
	
	i = 0;
	for (; i<count-1; i++){
		fprintf(psw,"%d ", numb[i]);
		admin->array[i] = numb[i];
	}
	fprintf(psw,". ");
	admin->length = i;
	memset(str,0,sizeof(str));
	memset(numb,0,sizeof(numb));
	printf("Password for basic user:");
	scanf("%s",str);
	count = str2Numbers(str, numb);
	i = 0;
	for (; i<count-1; i++){
		fprintf(psw,"%d ", numb[i]);
		basic->array[i] = numb[i];
	}
	fprintf(psw,". ");
	basic->length = i;
	fclose(psw);
	fprintf(lg,"Password change\n");
}

void readPswFile(FILE* psw, password *admin, password *basic){
	char c1 ='#';
	int i2 = 0;
	int i = 0;
	char str1[20];
	memset(str1,0,sizeof(str1));
	do{
		fread(&c1,1,1,psw);	
			if (c1 != ' '){
				str1[i2] = c1;
				i2++;
			} else {
				admin->array[i] = atoi(str1);
				i++;
				i2 = 0;
			}
			
	}while(c1 != '.');
		admin->length = i;
		//printf("admin %d",admin->length);
	i = 0;
	i2 = 0;
	memset(str1,0,sizeof(str1));
	fread(&c1,1,1,psw);	
	do{
		fread(&c1,1,1,psw);	
		if (c1 != ' '){
			str1[i2] = c1;
			i2++;
		} else {
			basic->array[i] = atoi(str1);
			i++;
			i2 = 0;
		}
	}while(c1 != '.');
	basic->length = i;
	fclose(psw);		
}

void inputPsw(char str[],password *userInput){
	int i = 0;
	do{
		userInput->array[i] = charToInt(str[i],i);
		i++;
	}while((str[i] != '\n')&&(str[i] != '\0'));
	userInput->length = i;	
}
	
int checkPsw(password psw, password input){
	int t = 0;
	//printf("%d %d \n\n\n",psw.length,input.length);
	if (psw.length == input.length){
		t = 1;
		int i = 0;
		for (; i<(psw.length); i++){
			//printf("%d %d ",psw.array[i],input.array[i]);
			if ((psw.array[i])!=(input.array[i])){
				t = 0;
			}
		}
	}
	return t;
}

void resetContent(content *node){
	memset(node->header,0,sizeof(node->header));
	memset(node->paragraph,0,sizeof(node->paragraph));
	memset(node->date,0,sizeof(node->date));
	memset(node->time,0,sizeof(node->time));
	node->pos = 0;
}

void writeBin(FILE* rezB, content *arr, int amm, char title[]){
	int i = 0;
	if (!rezB){
		printf("error\n");
	}
	FILE *extra;
	extra = fopen("titleAmm","w");
	fwrite(title,100,1,extra);
	fprintf(extra,"%d",amm);
	fclose(extra);
	for(; i < amm; i++){
		fwrite(&(arr[i]), sizeof(content),1,rezB);
	}
	fclose(rezB);
	
}

content* readBin(FILE* docB, int *ammE, char title[]){
	FILE *extra;
	int amm = 0;
	extra = fopen("titleAmm","r");
	if (extra == NULL){
		printf("titleAmm file is missing\n");
		fprintf(lg,"titleAmm file is missing\n");
	} else {
		fread(title,100,1,extra);
		fscanf(extra,"%d",&amm);
		fclose(extra);
	}
	if (!docB){
		return 0;
		printf("Binary file missing'\n");
		fprintf(lg,"Binary file missing\n");
	} else {
		content record;
		content *arrayL;
		arrayL = (content*)malloc(amm*sizeof(content));
		//printf("Title: %s\n",title);
		//printf("Ammount of elements stored %d\n",amm);
		getchar();
		int i = 0;
		for(; i<amm; i++){
			resetContent(&record);
			fread(&(record),sizeof(content),1,docB);
			copyContent(&(arrayL[i]),&record);
		}
		*ammE = amm;
		return (arrayL);
	}
	
}


content* editList(content *arrayE, int *ammE){
	char str[5];
	char anyHeader[1024];
	char anyDate[11];
	char anyTime[6];
	char anyParagraph[1024];
	int numb = 0;
	int i = 0;
	int amm = *ammE;
	printf("What element you want to change?\n");
	printf("Type %d to insert new one:",amm+1);
	do{
		scanf("%s",str);
		numb = atoi(str);
		
	}while((numb<1)||(numb>amm+1));
	numb--;
	
	
	content* arrayL;
	if (numb == amm){
		arrayL = (content*)malloc((1+amm)*sizeof(content));
	} else{
		arrayL = (content*)malloc((amm)*sizeof(content));	
		} 
		
		for(i = 0; i<amm; i++){
			copyContent(&(arrayL[i]),&(arrayE[i]));
		}
		if (numb == amm)
		amm++;
		
		
		printf("Creating or changing element\n");
		printf("Type date:");
		clearToEOL();
		scanf("%10s",anyDate);	
		strcpy(arrayL[numb].date,anyDate);
		clearToEOL();	
		printf("Type time:");
		scanf("%5s",anyTime);
		strcpy(arrayL[numb].time,anyTime);
		clearToEOL();	
		printf("Type header:");
		fgets(anyHeader,sizeof(anyHeader),stdin);
		strcpy(arrayL[numb].header,anyHeader);
		if (anyHeader[1023] == '\n')
			clearToEOL();
			
		printf("Type paragraph:");
		fgets(anyParagraph,sizeof(anyParagraph),stdin);
		strcpy(arrayL[numb].paragraph,anyParagraph);
		/*if (anyParagraph[1023] == '\0')
			clearToEOL();*/
			
		arrayL[i].pos = i+1;	
	
	
	
		
	*ammE = amm;
	
	return arrayL;
}

int greeting(){
	int pick;
	int correct = 0;
	printf("Welcome to the application, \n");
	pick = login();
	char pas[20];
	memset(pas,0,sizeof(pas));
	if (pick){
		do {
			scanf("%20s",pas);
			if (pick == 1){
				inputPsw(pas,&input);
				correct = checkPsw(admin,input);
				fprintf(lg,"Try to log in as admin\n");
			} else if(pick == 2){
				inputPsw(pas,&input);
				correct = checkPsw(basic,input);
				fprintf(lg,"Try to log in as user\n");
			}
		}while (correct == 0);
	fprintf(lg,"Log in = success\n");	
	} else{
		fprintf(lg,"Guest mode\n");
	}
	
	return pick;
}

int menu(){
	FILE* docB;
	FILE* rezB;
	char str[10];
	char fileName[30]; 
	char title[100]; memset(title,0,sizeof(title));
	listType *list = NULL;
	int ammount;
	content *array;
	
	printf("Options:");
	
	int t = 1;
	while(t){
		printf("\nimportHtml, clean, edit, print, resume, export, exit\n:");
		memset(str,0,sizeof(str));
		scanf("%s",str);
		if (!(strcmp(str,"importHtml"))){
			do{
				
			printf("\nHtml file name:");
			memset(fileName,0,sizeof(fileName));
			scanf("%s",fileName);	
			fprintf(lg,"Try to open html for parsing\n");
			}while(!(doc=fopen(fileName,"r")));
			ammount = parseHtml(doc,&list,title);
			array = (content*)malloc(ammount*sizeof(content));
			copyList2Array(list,array,ammount);
			printf("Success\n");
		} 
		else if (!(strcmp(str,"edit"))){
			array = editList(array,&ammount);
			fprintf(lg,"Manual list change\n");	
		}
		else if(!(strcmp(str,"clean"))){
			free(array);
			memset(title,0,sizeof(title));
			ammount = 0;
			fprintf(lg,"Clean\n");
		}
		else if (!(strcmp(str,"print"))){
			int i = 0;
			if (ammount){
				fprintf(lg,"Printing\n");
				printf("%s\n",title);
				for (; i < ammount; i++){
					printNode(&array[i]);
				}
			} else {
				printf("Nothing to print\n");
				fprintf(lg,"Printing fail\n");
			}
		}
		else if (!(strcmp(str,"export"))){
			if(ammount>0){
				rezB = fopen("BinFile.bin","wb");
				writeBin(rezB,array,ammount,title);
				printf("Success\n");
				fprintf(lg,"Exported bin file\n");
			} else {
				printf("Nothing to export\n");
			}
		}	
		else if (!(strcmp(str,"resume"))){
			docB = fopen("BinFile.bin","rb");
			*(&array) = readBin(docB, &ammount, title);
			fprintf(lg,"Resuming from binary file\n");
			printf("Success\n\n");
		} 
		else if (!(strcmp(str,"exit"))){
			t = 0;
		}						
	}
	
	return 1;
}

int main(int argc, char **argv)
{
	
	lg = fopen("logfile.txt","a");
	fprintf(lg,"Application Start\n");
	
	FILE* p;
#if Override
	fprintf(lg,"Override\n");
	p = fopen("psw.txt","w");
	storePsw(p, &admin, &basic);
#else
	int exit;
	int mode;	
	FILE* f;
	f = fopen("psw.txt","r");
	if (f == NULL){
		printf("Missing password file");
		fprintf(lg,"Missing password file\n");
	} else {
		fclose(f);
		p = fopen("psw.txt","r");
		readPswFile(p, &admin, &basic);
	
		mode = greeting();
		
		if (mode == 1){
			p = fopen("psw.txt","w");
			storePsw(p, &admin, &basic);
		} else if(mode == 0){
				char fileName[30]; 
				char title[100]; memset(title,0,sizeof(title));
				listType *list = NULL;
				int ammount;
				content *array;	
				do{	
					printf("\nHtml file name:");
					memset(fileName,0,sizeof(fileName));
					scanf("%s",fileName);		
				}while(!(doc=fopen(fileName,"r")));
				ammount = parseHtml(doc,&list,title);
				array = (content*)malloc(ammount*sizeof(content));
				copyList2Array(list,array,ammount);
				printf("Success\n\n");
				int i = 0;
				printf("%s\n",title);
				for (; i < ammount; i++){
					printNode(&array[i]);
				}
				fprintf(lg,"Printing\n"); 
			} else{
				do{
				exit = menu();
			}while (exit == 0);
		}
	}

	
#endif 
	printf("\nProgram Exit = Success\n");
	fprintf(lg,"Application exit\n");
	fclose(lg);
	getchar();
	return 0;
}

 
