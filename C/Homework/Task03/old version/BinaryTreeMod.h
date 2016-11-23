#ifndef BinaryTreeIcluded
#define BinaryTreeIcluded

typedef int comparableType;//Type can be chaged

typedef struct data{//Contents can be changed
	int number;
	comparableType comparableItem;
}data;

typedef struct binaryTree{
	struct binaryTree* left;
	struct binaryTree* right;
	struct binaryTree* parent;
	data info;
	
}binaryTree;

void createNode(binaryTree** node, data info);

void insertValue(binaryTree** node, data info);

#endif // BinaryTreeIcluded
