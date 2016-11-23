
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct record{
	int data;
	char str[10];
} record;

int main(int argc, char **argv){

	FILE *rez,*doc;
	record node;
	
	int c;
	scanf("%d",&c);
	if (c){
		rez = fopen("textFile.bin","wb");
		if(!rez){
			printf("No file found\n");
		}else {
			int i = 1;
			for (; i < 10; i++){
				node.data = i;
				strcpy(node.str,"kl");
				fwrite(&node, sizeof(record),1,rez);
			}
			
			fclose(rez);
		}
	} else {
		doc = fopen("textFile.bin","rb");
		if (!doc){
			printf("Error\n");
			
		} else {
			int i = 1;
			for (; i < 10; i++){
				fread(&node,sizeof(record),1,doc);
				printf("%d ",node.data);
				printf("%s\n",node.str);
			}
			
		}
		fclose(doc);
	}
	

	return 0;
} 
