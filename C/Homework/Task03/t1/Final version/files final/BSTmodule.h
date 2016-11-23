#ifndef BSTmoduleGUARD
#define BSTmoduleGUARD

#define intTESTING 1 //change to 0 if integer testing functions are not desired
#define PRINTFs 1 //change to 0 if you do not want to see any printf outputs

/* * * * * * * * * * * * * * * * * * * * * * * * * *\
 * 					           *
 * Binary Search Tree Module			   *
 * Author: Laimonas Beniušis VU MIF INFORMATIKA 1  *
 * contact em@il: aciukadsiunciate@gmail.com       *
 * 						   *
\* * * * * * * * * * * * * * * * * * * * * * * * * */
 
typedef struct bstNode { //Structure of a node
    void* data;
    struct bstNode* left;
	struct bstNode* right;
}bstNode; 

#if intTESTING //int printing functions
void intTreeInOrderPrintf(bstNode** node);
void intTreePreOrderPrintf(bstNode** node);
void intTreePostOrderPrintf(bstNode** node);
#endif

//FREE TO USE
void initialize(bstNode** node, void* data); //use this to initialize tree by passing first value
void clearTree(bstNode** node); //use this to clean tree memory
void insert(bstNode** root, int cmp(void* a, void*b), void* data); // use this to insert new values into initialized tree
void search4Value(bstNode** destination, bstNode** root, int cmp(void* a, void* b), void* data); // use this to search for value, if not found, inserts requested value to the destination

//NOT FOR USE
bstNode* newNode(void* data);
bstNode** search4Place(bstNode** root, int cmp(void* a, void* b), void* data);
void freeNode(bstNode* node);

#endif
