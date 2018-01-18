#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX(a,b) (a > b) ? a : b
#define MIN(a,b) (a < b) ? a : b

BinaryTree* binary_tree_add_node(BinaryTree *root, int data, bool insertAsLeftChild)
{
    BinaryTree *new_node = (BinaryTree*)malloc(sizeof(BinaryTree));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    if(!root)
        root = new_node;
    else
    {
        if(insertAsLeftChild)
            root->left = new_node;
        else
            root->right = new_node;
    }
    return new_node;
}

void binary_tree_preorder(BinaryTree *root, WorkFucntion work)
{
    if(!root) return;
    work(root->data);
    binary_tree_preorder(root->left, work);
    binary_tree_preorder(root->right, work);
}

void binary_tree_inorder(BinaryTree *root, WorkFucntion work)
{
    if(!root) return;
    binary_tree_inorder(root->left, work);
    work(root->data);
    binary_tree_inorder(root->right, work);
}

void binary_tree_postorder(BinaryTree *root, WorkFucntion work)
{
    if(!root) return;
    binary_tree_postorder(root->left, work);
    binary_tree_postorder(root->right, work);
    work(root->data);
}

void binary_tree_destroy(BinaryTree *root)
{
    if(!root) return;
    if(root->left) binary_tree_destroy(root->left);
    if(root->right) binary_tree_destroy(root->right);
    //printf("\nDestroying node %d\n", root->data);
    free(root);
    root = NULL;
}

void binary_tree_print_data(BinaryTree *node, int level)
{
    if(!node) return;
    for(int i = 0; i < level; ++i)
        printf("   ");
    printf("%d\n", node->data);
}

void binary_tree_walk(BinaryTree *root, WalkFunction wf, int level)
{
    if(!root) return;
    if(root->right) binary_tree_walk(root->right, wf, level + 1);
    wf(root, level);
    if(root->left) binary_tree_walk(root->left, wf, level + 1);
}

int binary_tree_height(BinaryTree *root)
{
    if(!root) return 0;
    int left_subtree_height = 0;
    int right_subtree_height = 0;
    if(root->left) left_subtree_height = binary_tree_height(root->left);
    if(root->right) right_subtree_height = binary_tree_height(root->right);
    return MAX(left_subtree_height, right_subtree_height) + 1;
}

int binary_tree_get_max_width(BinaryTree *root)
{
    if(!root) return 0;
    int height = binary_tree_height(root);
    int max_width = 0;
    for(int lvl = 0; lvl <= height; ++lvl)
    {
        int curr_width = binary_tree_get_width(root,lvl);
        if(curr_width > max_width)
            max_width = curr_width;
    }
    return max_width;
}

int binary_tree_get_width(BinaryTree *root, int level)
{
    if(!root) return 0;
    if(level == 1)
        return 1;
    else if(level > 1)
        return binary_tree_get_width(root->left, level - 1) +
               binary_tree_get_width(root->right, level - 1);
    else
        return 0;
}

int binary_tree_get_number_of_nodes(BinaryTree *root)
{
    if(!root) return 0;
    return binary_tree_get_number_of_nodes(root->left) +
           binary_tree_get_number_of_nodes(root->right) + 1;
}

void binary_tree_flip(BinaryTree *root)
{
    if(!root) return;
    BinaryTree *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    binary_tree_flip(root->left);
    binary_tree_flip(root->right);
}

bool binary_tree_find(BinaryTree *root, int key)
{
    if(!root)
        return false;
    else
    {
        if(root->data == key)
            return true;
        else if(key < root->data)
            return binary_tree_find(root->left, key);
        else
            return binary_tree_find(root->right, key);
    }

}

/*
int lookup(struct node* node, int target)
{
    if (node == NULL)
{
    return(0);
}
else
{
        if (target == node->data) return(1);
        else
        {
            if (target < node->data) return(lookup(node->left, target));
            else return(lookup(node->right, target));
        }
    }
}
*/

/*
int sameTree(struct node* a, struct node* b)
{
    if (a==NULL && b==NULL) return(true);
    else if (a!=NULL && b!=NULL)
    {
        return(
            a->data == b->data &&
            sameTree(a->left, b->left) &&
            sameTree(a->right, b->right)
            );
    }
    else return(false);
}
*/
