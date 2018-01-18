#include "ternary_tree.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_STACK_SIZE 1024

TernaryTree* ternary_tree_add_node(TernaryTree *tree, char *data, Direction dir)
{
    TernaryTree *tmp = (TernaryTree*)malloc(sizeof(TernaryTree));
    tmp->data = data;
    for(int i = 0; i < NUM_TERNARY_TREE_CHILDREN; ++i)
        tmp->children[i] = NULL;
    if(tree)
    {
        switch(dir)
        {
        case LEFT:
            tree->children[LEFT] = tmp;
            break;
        case MIDDLE:
            tree->children[MIDDLE] = tmp;
            break;
        default:
            tree->children[RIGHT] = tmp;
            break;
        }
    }
    return tmp;
}

void ternary_tree_preorder(TernaryTree *root, VisitFunction wf)
{
    if(root)
    {
        wf(root->data);
        for(int i = 0; i < NUM_TERNARY_TREE_CHILDREN;++i)
            ternary_tree_preorder(root->children[i], wf);
    }
}

void ternary_tree_inorder(TernaryTree *root, VisitFunction wf)
{
    if(root)
    {
        ternary_tree_inorder(root->children[LEFT], wf);
        wf(root->data);
        ternary_tree_inorder(root->children[MIDDLE], wf);
        ternary_tree_inorder(root->children[RIGHT], wf);
    }
}

void ternary_tree_postorder(TernaryTree *root, VisitFunction wf)
{
    if(root)
    {
        for(int i = 0; i < NUM_TERNARY_TREE_CHILDREN;++i)
            ternary_tree_postorder(root->children[i], wf);
        wf(root->data);
    }
}


void ternary_tree_iterative_preorder(TernaryTree *root, VisitFunction wf)
{
    Frame stack[MAX_STACK_SIZE];
    int pos = 0;
    Frame first = {0, root};
    stack[++pos] = first;
    Frame *curr_frame = NULL;
    Frame tmp;
    while(pos > 0)
    {
        curr_frame = &stack[pos];
        int *p = &curr_frame->priority;
        TernaryTree *curr_node = curr_frame->node;
        switch(*p)
        {
            case 0:
                *p = 1;
                if(!curr_node)
                    --pos;
                break;
            case 1:
                *p = 2;
                wf(curr_node->data);
                break;
            case 2:
                *p = 3;
                tmp.priority = 0;
                tmp.node = curr_node->children[LEFT];
                stack[++pos] = tmp;
                break;
            case 3:
                *p = 4;
                tmp.priority = 0;
                tmp.node = curr_node->children[MIDDLE];
                stack[++pos] = tmp;
                break;
            case 4:
                *p = 5;
                tmp.priority = 0;
                tmp.node = curr_node->children[RIGHT];
                stack[++pos] = tmp;
                break;
            case 5:
                --pos;
                break;
        }
    }
}


void ternary_tree_iterative_inorder(TernaryTree *root, VisitFunction wf)
{
    Frame stack[MAX_STACK_SIZE];
    int pos = 0;
    Frame first = {0, root};
    stack[++pos] = first;
    Frame *curr_frame = NULL;
    Frame tmp;
    while(pos > 0)
    {
        curr_frame = &stack[pos];
        int *p = &curr_frame->priority;
        TernaryTree *curr_node = curr_frame->node;
        switch(*p)
        {
            case 0:
                *p = 1;
                if(!curr_node)
                    --pos;
                break;
            case 1:
                *p = 2;
                tmp.priority = 0;
                tmp.node = curr_node->children[LEFT];
                stack[++pos] = tmp;
                break;
            case 2:
                *p = 3;
                wf(curr_node->data);
                break;
            case 3:
                *p = 4;
                tmp.priority = 0;
                tmp.node = curr_node->children[MIDDLE];
                stack[++pos] = tmp;
                break;
            case 4:
                *p = 5;
                tmp.priority = 0;
                tmp.node = curr_node->children[RIGHT];
                stack[++pos] = tmp;
                break;
            case 5:
                --pos;
                break;
        }
    }
}

void ternary_tree_iterative_postorder(TernaryTree *root, VisitFunction wf)
{
    Frame stack[MAX_STACK_SIZE];
    int pos = 0;
    Frame first = {0, root};
    stack[++pos] = first;
    Frame *curr_frame = NULL;
    Frame tmp;
    while(pos > 0)
    {
        curr_frame = &stack[pos];
        int *p = &curr_frame->priority;
        TernaryTree *curr_node = curr_frame->node;
        switch(*p)
        {
            case 0:
                *p = 1;
                if(!curr_node)
                    --pos;
                break;
            case 1:
                *p = 2;
                tmp.priority = 0;
                tmp.node = curr_node->children[LEFT];
                stack[++pos] = tmp;
                break;
            case 2:
                *p = 3;
                tmp.priority = 0;
                tmp.node = curr_node->children[MIDDLE];
                stack[++pos] = tmp;
                break;
            case 3:
                *p = 4;
                tmp.priority = 0;
                tmp.node = curr_node->children[RIGHT];
                stack[++pos] = tmp;
                break;
            case 4:
                *p = 5;
                wf(curr_node->data);
                break;
            case 5:
                --pos;
                break;
        }
    }
}

/*void tree_iterative_postorder(Tree *root, void(*func)(const char *))
{
    Tree* stack1[MAX_STACK_SIZE];
    Tree* stack2[MAX_STACK_SIZE];
    int pos1 = 0, pos2 = 0;
    Tree *curr = root;
    Tree *tmp = NULL;
    stack1[++pos1] = curr;
    while(pos1 > 0)
    {
        tmp = stack1[pos1--];
        stack2[++pos2] = tmp;
        for(int i = 0; i < NUM_TERNARY_TREE_CHILDREN; ++i)
            if(tmp->children[i])
                stack1[++pos1] = tmp->children[i];
    }

    while(pos2 > 0)
    {
        tmp = stack2[pos2--];
        func(tmp->data);
    }
}*/

void ternary_tree_destroy(TernaryTree *root)
{
    for(int i = 0; i < NUM_TERNARY_TREE_CHILDREN; ++i)
    {
        if(root->children[i])
            ternary_tree_destroy(root->children[i]);
    }
    printf("Destroying %s\n", root->data);
    free(root);
}
