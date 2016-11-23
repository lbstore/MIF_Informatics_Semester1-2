#ifndef GUARDMOD
#define GUARDMOD
//typedef int (*compare)(void *a, void *b);


typedef struct TreeNode{
	struct TreeNode *left;
	struct TreeNode *right;
	struct TreeNode *parent;
	void *data;
}TreeNode;

TreeNode createNode(void* info);
void insertValue(TreeNode** node, void* info,int (*cmp)(const void *, const void *));
void deleteTree(TreeNode** node);

#endif
