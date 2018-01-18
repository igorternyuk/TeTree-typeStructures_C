#include "bst.h"
#include <string.h>

bst *bst_create()
{
    bst* tree = (bst*)malloc(sizeof(bst));
    if(!tree) return NULL;
    tree->root = NULL;
    tree->count = 0;
    return tree;
}

void bst_destroy(bst *tree)
{
    if(!tree) return;
    Node *root = tree->root;
    if(!root) node_detroy(root);
    free(tree);
}

int bst_insert_node(bst *tree, int key, const char *data)
{
    Node **new_node = &tree->root;
    Node *target = tree->root;

    for(;;)
    {
        if(!target)
        {
            target = *new_node = (Node*)malloc(sizeof(Node));
            if(!target) return 0;
            target->data = data;
            target->key = key;
            target->left = target->right = NULL;
            ++tree->count;
            return 1;
        }
        else if(key == target->key)
            return 2; // Ya lo tenemos
        else if(key < target->key)
        {
            new_node = &target->left;
            target = target->left;
        }
        else
        {
            new_node = &target->right;
            target = target->right;

        }
    }
}

int bst_search(bst *tree, int key, char **data)
{
    const Node* node_to_search = tree->root;
    for(;;)
    {
        if(!node_to_search) return 0;
        if(key == node_to_search->key)
        {
            *data = node_to_search->data;
            return 1;
        }
        else if(key < node_to_search->key)
            node_to_search = node_to_search->left;
        else
            node_to_search = node_to_search->right;
    }
}

void node_detroy(Node *node)
{
    if(!node) return;
    if(node->left) node_detroy(node->left);
    if(node->right) node_detroy(node->right);
    free(node);
}

void bst_print_node(Node *node, int level)
{
    if(!node) return;
    for(int l = 0; l < level; ++l)
        printf("      ");
    printf("{%d, %s}\n", node->key, node->data);
}

void bst_print_sub_tree(Node *root, WorkFunc wf, int level)
{
    if(!root) return;
    bst_print_sub_tree(root->right, wf, level + 1);
    wf(root, level);
    bst_print_sub_tree(root->left, wf, level + 1);
}

void bst_print_tree(bst *tree)
{
    if(!tree) return;
    bst_print_sub_tree(tree->root, &bst_print_node, 0);
}

Node *bst_get_maximum(bst *tree)
{
    if(!tree || !tree->root) return NULL;
    Node *node = tree->root;
    while(node->right)
        node = node->right;
    return node;
}

Node *bst_get_minimum(bst *tree)
{
    if(!tree || !tree->root) return NULL;
    Node *node = tree->root;
    while(node->left)
        node = node->left;
    return node;
}

int bst_remove_node(bst *tree, int key)
{
    Node **q = &tree->root;
    Node *z = tree->root; //Node to remove
}

/*
int delete(struct tree * search_tree, int ** item)
{
    struct node ** q,*z;

    q=&search_tree->root;
    z=search_tree->root;
    //поиск удаляемого элемента
    for(;;)
    {
        if(z == NULL) return 0;
        else if(item == (int **)z->data) break;
        else if(item > (int **)z->data)
        {
            q = &z->right;
            z = z->right;
        }
        else
        {
            q = &z->left;
            z = z->left;
        }
    }

    // непосредственное удаление элемента
    if(z->right == NULL) *q = z->left;
    else
    {
        struct node * y = z->right;
        if(y->left == NULL)
        {
            y->left = z->left;
            *q-y;
        }
        else
        {
            struct node * x=y->left;
            while(x->left != NULL)
            {
                y = x;
                x = y->left;
            }
            y->left = x->right;
            x->left = z->left;
            x->right = z->right;
            *q=x;
        }
    }

    search_tree->count --;
    free(z);
    return 1;
}
*/

/*
int isBST(struct node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}

int isBSTUtil(struct node* node, int min, int max)
{
    if (node==NULL) return(true);

    if (node->data<min || node->data>max) return(false);

return (
        isBSTUtil(node->left, min, node->data) &&
        isBSTUtil(node->right, node->data+1, max)
);
}
*/
