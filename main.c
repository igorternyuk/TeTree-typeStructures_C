#include <stdio.h>
#include "ternary_tree.h"

void print_node(const char* data);

int main()
{
    Tree *root = NULL;
    root = tree_add_node(root, "root", LEFT);
    Tree *node_a = tree_add_node(root, "A", LEFT);
    Tree *node_b = tree_add_node(root, "B", MIDDLE);
    Tree *node_c = tree_add_node(root, "C", RIGHT);

    Tree *node_e = tree_add_node(node_a, "E", LEFT);
    Tree *node_f = tree_add_node(node_a, "F", MIDDLE);
    Tree *node_g = tree_add_node(node_a, "G", RIGHT);

    Tree *node_h = tree_add_node(node_b, "H", LEFT);
    Tree *node_i = tree_add_node(node_b, "I", MIDDLE);
    Tree *node_j = tree_add_node(node_b, "J", RIGHT);

    Tree *node_k = tree_add_node(node_c, "K", LEFT);
    Tree *node_l = tree_add_node(node_c, "L", MIDDLE);
    Tree *node_m = tree_add_node(node_c, "M", RIGHT);
    printf("\n*******preorder*******\n");
    tree_preorder(root, &print_node);
    printf("\n*******inorder*******\n");
    tree_inorder(root, &print_node);
    printf("\n*******postorder*******\n");
    tree_postorder(root, &print_node);
    printf("\n");
    printf("\n*******iterative_preorder*******\n");
    tree_iterative_preorder(root, &print_node);
    printf("\n");
    printf("\n*******iterative_inorder*******\n");
    tree_iterative_inorder(root, &print_node);
    printf("\n");
    printf("\n*******iterative_postorder*******\n");
    tree_iterative_postorder(root, &print_node);
    printf("\n");
    tree_destroy(root);
    return 0;
}

void print_node(const char* data)
{
    printf("%s-", data);
}

/*
                                     root

            A                         B                              C

    E       F       G        H        I         J          K          L         M
*/
