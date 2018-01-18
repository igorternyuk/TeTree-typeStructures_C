#ifndef TERNARY_TREE_H
#define TERNARY_TREE_H

#define NUM_TERNARY_TREE_CHILDREN 3

typedef struct TernaryTree TernaryTree;
typedef void(*VisitFunction)(const char *);
typedef enum
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
} Direction;

struct TernaryTree
{
    const char *data;
    TernaryTree* children[NUM_TERNARY_TREE_CHILDREN];
};

typedef struct
{
    int priority;
    TernaryTree* node;
} Frame;

TernaryTree *ternary_tree_add_node(TernaryTree *tree, char *data, Direction dir);
void ternary_tree_preorder(TernaryTree *root, VisitFunction wf);
void ternary_tree_inorder(TernaryTree *root, VisitFunction wf);
void ternary_tree_postorder(TernaryTree *root, VisitFunction wf);
void ternary_tree_iterative_preorder(TernaryTree *root, VisitFunction wf);
void ternary_tree_iterative_inorder(TernaryTree *root, VisitFunction wf);
void ternary_tree_iterative_postorder(TernaryTree *root, VisitFunction wf);
void ternary_tree_destroy(TernaryTree *root);

#endif // TERNARY_TREE_H
