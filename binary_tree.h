#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>

typedef struct BinaryTree BinaryTree;
typedef void(*WorkFucntion)(int);
typedef void(*WalkFunction)(BinaryTree*, int);

struct BinaryTree
{
    int data;
    BinaryTree *left;
    BinaryTree *right;
};

BinaryTree* binary_tree_add_node(BinaryTree *root, int data, bool insertAsLeftChild);
void binary_tree_preorder(BinaryTree *root, WorkFucntion work);
void binary_tree_inorder(BinaryTree *root, WorkFucntion work);
void binary_tree_postorder(BinaryTree *root, WorkFucntion work);
void binary_tree_print_data(BinaryTree *node, int level);
void binary_tree_walk(BinaryTree *root, WalkFunction wf, int level);
int binary_tree_height(BinaryTree *root);
int binary_tree_get_width(BinaryTree *root, int level);
int binary_tree_get_max_width(BinaryTree *root);
int binary_tree_get_number_of_nodes(BinaryTree* root);
void binary_tree_flip(BinaryTree *root);
bool binary_tree_find(BinaryTree *root, int key);
void binary_tree_destroy(BinaryTree *root);

#endif // BINARY_TREE_H
