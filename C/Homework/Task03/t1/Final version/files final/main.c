#include "BSTmodule.h"

#include <stdio.h>
#include <stdlib.h>
#include "BSTmodule.h"

int compare(void *a,void *b){

	int left = *((int*)a);
	int right = *((int*)b);
	return (left-right);
}

int main(int argc, char** argv){
	
	int number1=5;
	bstNode* Tree;
	initialize(&Tree,&number1);
	//insert(&Tree,compare,&number1);
	
	int number2=8;
	insert(&Tree,compare,&number2);
	int number3=9;
	insert(&Tree,compare,&number3);
	int number4=6;
	insert(&Tree,compare,&number4);
	int number5=2;
	insert(&Tree,compare,&number5);
	int number6=3;
	insert(&Tree,compare,&number6);
	int number7=1;
	insert(&Tree,compare,&number7);
	
	int number10=999;
	printf("test passed");
	getchar();
	
	/*printf("some values:\n");	
	printf("%d(r) ",*(int*)Tree->right->data);
	printf("%d(l) ",*(int*)Tree->left->data);
	printf("%d(ll) ",*(int*)Tree->left->left->data);
	printf("%d(lr) ",*(int*)Tree->left->right->data);*/
	
	
	bstNode* OtherT;
	initialize(&OtherT,&number10);
	search4Value(&OtherT,&Tree,compare,&number10);
	printf("%d\n\n",*(int*)(OtherT)->data);
	intTreeInOrderPrintf(&Tree);printf(" <-In order\n");
	intTreePreOrderPrintf(&Tree);printf(" <-Pre order\n");
	intTreePostOrderPrintf(&Tree);printf(" <-Post order\n");
	
	//destroy(&Tree);
	//delete(&Tree);
	getchar();
	clearTree(&Tree);
	printf("\nmem deleted");
	getchar();
	
	/*printf("%d(r) ",*(int*)Tree->right->data);
	printf("%d(l) ",*(int*)Tree->left->data);
	printf("%d(ll) ",*(int*)Tree->left->left->data);
	printf("%d(lr) ",*(int*)Tree->left->right->data);
	
	
	
	
	int number11=50;
	initialize(&Tree,&number11);
	int number21=80;
	insert(&Tree,compare,&number21);
	int number31=90;
	insert(&Tree,compare,&number31);
	int number41=60;
	insert(&Tree,compare,&number41);
	int number51=20;
	insert(&Tree,compare,&number51);
	int number61=30;
	insert(&Tree,compare,&number61);
	int number71=10;
	insert(&Tree,compare,&number71);
	
	printf("test passed");
	getchar();
	printf("Some other values:\n");	
	printf("%d(r) ",*(int*)Tree->right->data);
	printf("%d(l) ",*(int*)Tree->left->data);
	printf("%d(ll) ",*(int*)Tree->left->left->data);
	printf("%d(lr) ",*(int*)Tree->left->right->data);
	delete(&Tree);
	//printf("%d ",*(int*)Tree1->left->right->data);
	//destroy(&Tree1);
	obliterate(&Tree);
	printf("\nmem deleted");
	getchar();*/
	
	return 0;
}

 
