#include <stdlib.h>
#include <stdio.h>
#include "BTM.h"
#include <string.h>


//typedef int (*cmp)(void *a, void *b);

void createNode(TreeNode **node,void *info){
	*node = (TreeNode*)malloc(sizeof(TreeNode));
	(*node)->left=NULL;
	(*node)->right=NULL;
	(*node)->parent=NULL;
	(*node)->data=malloc(1*sizeof(info));
	memcpy((*node)->data,info,sizeof(customType));
	printf("%d ",*((int*)info));
}
/*
void createNode(TreeNode **node,void* info){
	TreeNode* tmp=NULL;
	tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->left=NULL;
	tmp->right=NULL;
	tmp->parent=NULL;
	tmp->data=malloc(1*sizeof(info));
	memcpy(tmp->data,info,sizeof(customType));
	printf("%d %d",(int)&tmp->data, (int)&info);
	memcpy(node,tmp,sizeof(TreeNode));
}
*/

void insertValue(TreeNode **node, void *info,int (*cmp)(const void *, const void *)){

	if (!(*node)){ //node is empty
		createNode(&(*node),&info);
	} else {
		if((cmp(&(*node)->data,&info)>0)){ //insert to left
			insertValue(&(*node)->left, &info,cmp);
			(*node)->left->parent=(*node);
		} else{
			insertValue(&(*node)->right, &info,cmp);//insert to right
			(*node)->right->parent=(*node);
		}
	}
}

void deleteTree(TreeNode **node){
	if ((*node)!=NULL){ //Tree is not empty
		if (&(*node)->left){
			deleteTree(&(*node)->left);
		}
		if (&(*node)->right){
			deleteTree(&(*node)->right);
		}
		free(*node);
	}
}

void printTree(TreeNode **node){
	if (&(*node)->data!=NULL){ //Tree is not empty
		if (&(*node)->left!=NULL){
			printf("left ");
			getchar();
			printTree(&(*node)->left);
			
			
		}
		if (&(*node)->right!=NULL){
			printTree(&(*node)->right);
		}
		printf("ok");
	}
}
