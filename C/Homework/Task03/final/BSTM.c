#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "BSTM.h"

//.h


typedef struct bstNode {
    void* data;
    struct bstNode* left;
	struct bstNode* right;
	struct bstNode* parent;
}bstNode;
//.h


bstNode* newNode(void* data){
	bstNode* tmpNode = malloc(sizeof(bstNode));
	tmpNode->data=data;
	tmpNode->left = NULL;
	tmpNode->right = NULL;
	tmpNode->parent = NULL;
	//printf("data %d %d\n",*(int*)data,*(int*)tmpNode->data); //DEBUG
	return tmpNode;
}

bstNode** search(bstNode** root, int cmp(void* a, void* b), void* data){
//	if (*root == NULL) return root;
	bstNode** node = root;
	while ((*node) != NULL) {
		//printf("node data %d\n",*((int*)(*node)->data)); //DEBUG
		int cmpResult = cmp(data, (*node)->data);
		//printf("cmp result %d\n",cmpResult); //DEBUG
		if (cmpResult < 0)
			node = &(*node)->left;
		else if (cmpResult > 0)
			node = &(*node)->right;
		else
			break;
	}
	return node;
}

void searchValue(bstNode** destination, bstNode** root, int cmp(void* a, void* b), void* data){
	bstNode** node = root;
	if ((*node) != NULL) {
		//printf("node data %d\n",*((int*)(*node)->data)); //DEBUG
		int cmpResult = cmp(data, (*node)->data);
		//printf("cmp result %d\n",cmpResult); //DEBUG
		if (cmpResult == 0){
			printf("node found %d \n",*(int*)(*node)->data);
			(*destination)->data = (*node)->data;
		}
		else if (cmpResult < 0)
			searchValue(&(*destination), &(*node)->left,cmp,data);
			else if (cmpResult > 0)
				searchValue(&(*destination), &(*node)->right,cmp,data);
		
			
	} else {
		printf("Node was not found\n");
		*destination = newNode(data);
	}
}

void setParent(bstNode** node){
	if (*node != NULL){
		if (&(*node)->left != NULL){
			bstNode** iterNode = node;
			iterNode = &(*iterNode)->left;
			(*node)->parent = *iterNode;
		}
		if (&(*node)->right != NULL){
			bstNode** iterNode = node;
			iterNode = &(*iterNode)->right;
			(*node)->parent = *iterNode;
		}
	}
}

void initialize(bstNode** node, void* data){
	*node = newNode(data);
	
}

void insert(bstNode** root, int cmp(void* a, void*b), void* data){
	printf("inserted %d\n",*((int*)data));		//DEBUG
	bstNode** node = search(root, cmp, data);
	if (*node == NULL) {
		*node = newNode(data);
		setParent(node);
	}
}

void freeNode(bstNode* node){
	free(node);
}

void delete(bstNode** node) {
    bstNode* oldNode = *node;
    if ((*node)->left == NULL) {
        *node = (*node)->right;
        freeNode(oldNode);
    } else if ((*node)->right == NULL) {
        *node = (*node)->left;
        freeNode(oldNode);
    }else {
		bstNode** pred = &(*node)->left;
        while ((*pred)->right != NULL) {
			pred = &(*pred)->right;
		}
	void* temp = (*pred)->data;
	(*pred)->data = (*node)->data;
	(*node)->data = temp;
	delete(pred);
    }
}

void destroy(bstNode** node){
	if((*node)!=NULL){
	if ((*node)->left != NULL){
		destroy(&(*node)->left);
	}
	if ((*node)->right != NULL){
		destroy(&(*node)->right);
	}
	(*node)->left=NULL;
	(*node)->right=NULL;
	(*node)->data=0;
	
	freeNode(*node);
	} else 
		freeNode(*node);
	
	
}

void obliterate(bstNode** node){
	if ((*node) == NULL) return;
	
	obliterate(&(*node)->left);
	obliterate(&(*node)->right);
	freeNode(*node);
}

void intTreeInOrderPrintf(bstNode** node){
	if((*node) == NULL) return;
	
	intTreeInOrderPrintf(&(*node)->left);
	printf("%d ",*(int*)(*node)->data);
	intTreeInOrderPrintf(&(*node)->right);
	
}

void intTreePreOrderPrintf(bstNode** node){
	if((*node) == NULL) return;
	printf("%d ",*(int*)(*node)->data);
	intTreeInOrderPrintf(&(*node)->left);
	intTreeInOrderPrintf(&(*node)->right);
	
}
void intTreePostOrderPrintf(bstNode** node){
	if((*node) == NULL) return;
	intTreeInOrderPrintf(&(*node)->left);
	intTreeInOrderPrintf(&(*node)->right);
	printf("%d ",*(int*)(*node)->data);
}

int compare(void *a,void *b){

	int left = *((int*)a);
	int right = *((int*)b);
	//printf("int %d %d\n",left,right);		//DEBUG	
	//printf("void %d %d",*((int*)a),*((int*)b));		//DEBUG
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
	searchValue(&OtherT,&Tree,compare,&number10);
	printf("%d\n\n",*(int*)(OtherT)->data);
	intTreeInOrderPrintf(&Tree);printf(" <-In order\n");
	intTreePreOrderPrintf(&Tree);printf(" <-Pre order\n");
	intTreePostOrderPrintf(&Tree);printf(" <-Post order\n");
	
	//destroy(&Tree);
	//delete(&Tree);
	getchar();
	obliterate(&Tree);
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
