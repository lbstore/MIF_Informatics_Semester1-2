#include <stdlib.h>
#include <stdio.h>
#include "BinaryTreeMod.h"

typedef int comparableType;

void fillData(data* inf, int arg1, comparableType lastArg){
	inf->number=arg1;
	inf->comparableItem=lastArg;
}



/*
void printTreeInOrder(binaryTree* node){
	if(node->left) {
		printTreeInOrder(node->left);
	}
	printf("%d\n",node->data);
	if (node->right){
		printTreeInOrder(node->right);
	}
}

void printTreePostOrder(binaryTree* node){
	if(node->left) {
		printTreePostOrder(node->left);
	}
	if (node->right){
		printTreePostOrder(node->right);
	}
	printf("%d\n",node->data);
}

void printTreePreOrder(binaryTree* node){
	printf("%d\n",node->data);
	if(node->left) {
		printTreePreOrder(node->left);
	}
	if (node->right){
		printTreePreOrder(node->right);
	}
	
}

*/


int main(int argc, char **argv)
{
	
	binaryTree* Tree;
	data info;
	
	fillData(&info,10,20);
	insertValue(&Tree,info);
	printf("%d\n",Tree->info->number);getchar();
	printf("%d\n\n",Tree->info->comparableItem);
	
	fillData(&info,11,22);
	insertValue(&Tree,info);
	printf("%d\n",info.number);
	printf("%d",Tree->right->info->comparableItem);
	return 0;
}

