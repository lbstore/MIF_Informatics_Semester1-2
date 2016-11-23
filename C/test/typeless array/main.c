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

void fillData(data* inf, int arg1, comparableType lastArg){
	inf->number=arg1;
	inf->comparableItem=lastArg;
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
	//data* pointer2data=&info;
	fillData(&info,10,20);
	insertValue(&Tree,info);
	printf("%d\n",Tree->info.number);getchar();
	printf("%d\n\n",Tree->info.comparableItem);
	
	fillData(&info,11,22);
	insertValue(&Tree,info);
	printf("%d\n",Tree->info.number);getchar();
	printf("%d",Tree->right->info.comparableItem);
	return 0;
}

