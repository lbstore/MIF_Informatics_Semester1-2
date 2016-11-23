#include <stdlib.h>
#include <stdio.h>


typedef int comparableType;

typedef struct data{
	int number;
	comparableType comparableItem;
}data; 



typedef struct binaryTree{
	struct binaryTree* left;
	struct binaryTree* right;
	struct binaryTree* parent;
	data info;
	
}binaryTree;


void createNode(binaryTree** node, data info){
	binaryTree* tmp=NULL;
	tmp = (binaryTree*)malloc(sizeof(binaryTree));
	tmp->left=NULL;
	tmp->right=NULL;
	tmp->parent=NULL;
	tmp->info=info;
	*node=tmp;	
}


void insertValue(binaryTree** node, data info){

	if (!(*node)){ //node is empty
		createNode(&(*node),info);
	} else if(info.comparableItem<(*node)->info.comparableItem){ //insert to left
		insertValue(&(*node)->left, info);
		(*node)->left->parent=(*node);
		} else{
			insertValue(&(*node)->right, info);//insert to right
			(*node)->right->parent=(*node);
		}
}
