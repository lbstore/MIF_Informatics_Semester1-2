#include <stdlib.h>
#include <stdio.h>
#include "BTM.h"
#include <string.h>


typedef int (*cmp)(void *a, void *b);



TreeNode createNode(void* info){
	TreeNode* tmp=NULL;
	tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->left=NULL;
	tmp->right=NULL;
	tmp->parent=NULL;
	tmp->data=malloc(1*sizeof(info));
	//tmp->data=info;
	memcpy(tmp->data,info,sizeof(int));
	return *tmp;	
}


void insertValue(TreeNode** node, void* info,int (*cmp)(const void *, const void *)){

	if (!(*node)){ //node is empty
		**node=createNode(&info);
	} else {
		if (1){
		//if((cmp((*node)->data,info)>0)){ //insert to left//TODO
			insertValue(&(*node)->left, &info,cmp);
			(*node)->left->parent=(*node);
		} else{
			insertValue(&(*node)->right, &info,cmp);//insert to right
			(*node)->right->parent=(*node);
		}
	}
}

void deleteTree(TreeNode** node){
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
