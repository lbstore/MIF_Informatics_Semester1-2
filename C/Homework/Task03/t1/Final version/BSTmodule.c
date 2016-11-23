#include <stdlib.h>
#include <stdio.h>
#include "BSTmodule.h" 


#if intTESTING

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

#endif

void initialize(bstNode** node, void* data){
	*node = newNode(data);
}

bstNode* newNode(void* data){
	bstNode* tmpNode = malloc(sizeof(bstNode));
	tmpNode->data=data;
	tmpNode->left = NULL;
	tmpNode->right = NULL;
	return tmpNode;
}


bstNode** search4Place(bstNode** root, int cmp(void* a, void* b), void* data){
	bstNode** node = root;
	while ((*node) != NULL) {
		int cmpResult = cmp(data, (*node)->data);
		if (cmpResult < 0)
			node = &(*node)->left;
		else if (cmpResult > 0)
			node = &(*node)->right;
		else
			break;
	}
	return node;
}

void search4Value(bstNode** destination, bstNode** root, int cmp(void* a, void* b), void* data){
	bstNode** node = root;
	if ((*node) != NULL) {
		int cmpResult = cmp(data, (*node)->data);
		if (cmpResult == 0){
			#if PRINTFs
				printf("node found %d \n",*(int*)(*node)->data);
			#endif
			(*destination)->data = (*node)->data;
		}
		else if (cmpResult < 0)
			search4Value(&(*destination), &(*node)->left,cmp,data);
			else if (cmpResult > 0)
				search4Value(&(*destination), &(*node)->right,cmp,data);	
			
	} else {
		#if PRINTFs
			printf("Node was not found\n");
		#endif
		*destination = newNode(data);
	}
}

void insert(bstNode** root, int cmp(void* a, void*b), void* data){
	bstNode** node = search4Place(root, cmp, data);
	#if PRINTFs
		#if intTESTING
			printf("inserted %d\n",*((int*)data));
		#endif
	#endif
	if (*node == NULL) {
		*node = newNode(data);
	}
}

void freeNode(bstNode* node){
	free(node);
}

void clearTree(bstNode** node){
	if ((*node) == NULL) return;
	
	clearTree(&(*node)->left);
	clearTree(&(*node)->right);
	freeNode(*node);
}
