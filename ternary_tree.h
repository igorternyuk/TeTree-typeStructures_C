#ifndef TERNARY_TREE_H
#define TERNARY_TREE_H

#include <stdlib.h>
#include <stdio.h>

#define NUM_TERNARY_TREE_CHILDREN 3

typedef struct Tree Tree;
typedef enum
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
} Direction;

struct Tree
{
    const char *data;
    Tree* children[NUM_TERNARY_TREE_CHILDREN];
};

typedef struct
{
    int priority;
    Tree* node;
} Frame;

Tree *tree_add_node(Tree *tree, char *data, Direction dir);
void tree_preorder(Tree *root, void(*func)(const char *));
void tree_inorder(Tree *root, void(*func)(const char *));
void tree_postorder(Tree *root, void(*func)(const char *));
void tree_iterative_preorder(Tree *root, void(*func)(const char *));
void tree_iterative_inorder(Tree *root, void(*func)(const char *));
void tree_iterative_postorder(Tree *root, void(*func)(const char *));
void tree_destroy(Tree *root);

#endif // TERNARY_TREE_H
