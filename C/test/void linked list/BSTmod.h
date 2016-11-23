
#ifndef _BST_H_
#define _BST_H_
 
/* Returns negative (left<right), zero (left==right), or positive (left>right). */
typedef int comparator(void* left, void* right);

struct bst_node {
    void* data;
    struct bst_node* left;
	struct bst_node* right;
	struct bst_node* parent;
};

struct bst_node* new_node(void* data);
void free_node(struct bst_node* node);
struct bst_node** search(struct bst_node** root, comparator compare, void* data);
void insert(struct bst_node** root, comparator compare, void* data);
void free_node(struct bst_node* node);
void delete(struct bst_node** node);
#endif
