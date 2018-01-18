#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Node Node;
typedef void(*WorkFunc)(Node*,int);

struct Node
{
    int key;
    const char* data;
    Node* left;
    Node* right;
};

typedef struct
{
   Node *root;
   int count;
} bst;

bst* bst_create();
void bst_destroy(bst *tree);
void node_detroy(Node *node);
int bst_insert_node(bst *tree, int key, const char* data);
int bst_remove_node(bst *tree, int key);
int bst_search(bst *tree, int key, char **data);
void bst_print_node(Node *node, int level);
void bst_print_sub_tree(Node *root, WorkFunc wf, int level);
void bst_print_tree(bst *tree);
Node* bst_get_maximum(bst *tree);
Node* bst_get_minimum(bst *tree);


#endif // BST_H
