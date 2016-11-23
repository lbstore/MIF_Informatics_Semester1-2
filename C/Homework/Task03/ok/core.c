
#include <stdlib.h>
#include <stdio.h>

typedef struct tree{
	struct tree* left;
	struct tree* right;
	struct tree* parent;
	int value;
}tree;

void createNode(tree** node,int val){
	tree* tmp=NULL;
	tmp = (tree*)malloc(sizeof(tree));
	tmp->left=NULL;
	tmp->right=NULL;
	tmp->parent=NULL;
	tmp->value=val;
	*node=tmp;	
}

void insertValue(tree** node, int val){

	if (!(*node)){ //node is empty
		createNode(&(*node),val);
	} else if(val<(*node)->value){ //insert to left
		insertValue(&(*node)->left, val);
		(*node)->left->parent=(*node);
		} else{
			insertValue(&(*node)->right,val);//insert to right
			(*node)->right->parent=(*node);
		}
}

void printTreeInOrder(tree* node){
	if(node->left) {
		printTreeInOrder(node->left);
	}
	printf("%d\n",node->value);
	if (node->right){
		printTreeInOrder(node->right);
	}
}

void printTreePostOrder(tree* node){
	if(node->left) {
		printTreePostOrder(node->left);
	}
	if (node->right){
		printTreePostOrder(node->right);
	}
	printf("%d\n",node->value);
}

void printTreePreOrder(tree* node){
	printf("%d\n",node->value);
	if(node->left) {
		printTreePreOrder(node->left);
	}
	if (node->right){
		printTreePreOrder(node->right);
	}
	
}

int main(int argc, char **argv)
{	tree* medis;
	//tree* root;
	medis = NULL;
	insertValue(&medis,6);
	insertValue(&medis,2);
	insertValue(&medis,4);
	insertValue(&medis,9);
	insertValue(&medis,7);
	insertValue(&medis,8);
	insertValue(&medis,3);
	//printf("check");
	
	//printf("%d\n",medis->left->right->left->parent->value);
	printf("Enter to continue");
	getchar();
	printf("\nInOrder\n");
	printTreeInOrder(medis);
	printf("\nPreOrder\n");
	printTreePreOrder(medis);
	printf("\nPostOrder\n");
	printTreePostOrder(medis);
	return 0;
}

