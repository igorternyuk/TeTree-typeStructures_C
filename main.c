#include <stdio.h>
#include "ternary_tree.h"
#include "binary_tree.h"
#include "bst.h"

void print_node(const char* data);
void print_node2(int data);

int main()
{
    printf("\n*******Ternary tree*******\n");
    TernaryTree *root = NULL;
    root = ternary_tree_add_node(root, "root", LEFT);
    TernaryTree *node_a = ternary_tree_add_node(root, "A", LEFT);
    TernaryTree *node_b = ternary_tree_add_node(root, "B", MIDDLE);
    TernaryTree *node_c = ternary_tree_add_node(root, "C", RIGHT);

    ternary_tree_add_node(node_a, "E", LEFT);
    ternary_tree_add_node(node_a, "F", MIDDLE);
    ternary_tree_add_node(node_a, "G", RIGHT);

    ternary_tree_add_node(node_b, "H", LEFT);
    ternary_tree_add_node(node_b, "I", MIDDLE);
     ternary_tree_add_node(node_b, "J", RIGHT);

    ternary_tree_add_node(node_c, "K", LEFT);
    ternary_tree_add_node(node_c, "L", MIDDLE);
    ternary_tree_add_node(node_c, "M", RIGHT);
    printf("\n*******preorder*******\n");
    ternary_tree_preorder(root, &print_node);
    printf("\n*******inorder*******\n");
    ternary_tree_inorder(root, &print_node);
    printf("\n*******postorder*******\n");
    ternary_tree_postorder(root, &print_node);
    printf("\n");
    printf("\n*******iterative_preorder*******\n");
    ternary_tree_iterative_preorder(root, &print_node);
    printf("\n");
    printf("\n*******iterative_inorder*******\n");
    ternary_tree_iterative_inorder(root, &print_node);
    printf("\n");
    printf("\n*******iterative_postorder*******\n");
    ternary_tree_iterative_postorder(root, &print_node);
    printf("\n");
    ternary_tree_destroy(root);

    printf("\n*******Binary tree*******\n");
    BinaryTree *bt_root = NULL;
    bt_root = binary_tree_add_node(bt_root, 8, false);
    BinaryTree *node_4 = binary_tree_add_node(bt_root, 4, true);
    BinaryTree *node_12 = binary_tree_add_node(bt_root, 12, false);

    BinaryTree *node_2 = binary_tree_add_node(node_4, 2, true);
    BinaryTree *node_6 = binary_tree_add_node(node_4, 6, false);

    BinaryTree *node_10 = binary_tree_add_node(node_12, 10, true);
    BinaryTree *node_14 = binary_tree_add_node(node_12, 14, false);

    binary_tree_add_node(node_2, 1, true);
    binary_tree_add_node(node_2, 3, false);

    binary_tree_add_node(node_6, 5, true);
    binary_tree_add_node(node_6, 7, false);

    binary_tree_add_node(node_10, 9, true);
    binary_tree_add_node(node_10, 11, false);

    binary_tree_add_node(node_14, 13, true);
    binary_tree_add_node(node_14, 15, false);

    binary_tree_walk(bt_root, &binary_tree_print_data, 0);

    printf("\nHeight = %d\n", binary_tree_height(bt_root));
    printf("\nMaxWidth = %d\n", binary_tree_get_max_width(bt_root));
    printf("\nNumber of nodes = %d\n", binary_tree_get_number_of_nodes(bt_root));
    printf("\nHas 3? = %d\n", binary_tree_find(bt_root, 3));
    printf("\nHas 8? = %d\n", binary_tree_find(bt_root, 8));
    printf("\nHas 12? = %d\n", binary_tree_find(bt_root, 12));
    printf("\nHas -99? = %d\n", binary_tree_find(bt_root, -99));
    printf("\nHas 100? = %d\n", binary_tree_find(bt_root, 100));
    printf("\nHas 500? = %d\n", binary_tree_find(bt_root, 500));

    printf("\n************Flip*********\n");
    binary_tree_flip(bt_root);
    binary_tree_walk(bt_root, &binary_tree_print_data, 0);
    printf("\n************Preorder*********\n");
    binary_tree_preorder(bt_root, &print_node2);
    printf("\n************Inorder*********\n");
    binary_tree_inorder(bt_root, &print_node2);
    printf("\n************Postorder*********\n");
    binary_tree_postorder(bt_root, &print_node2);
    binary_tree_destroy(bt_root);

    printf("\n*******Binary search tree*******\n");
    bst *tree = bst_create();
    bst_insert_node(tree, 8, "Root");
    bst_insert_node(tree, 4, "A");
    bst_insert_node(tree, 4, "A");
    bst_insert_node(tree, 12, "B");
    bst_insert_node(tree, 2, "C");
    bst_insert_node(tree, 6, "D");
    bst_insert_node(tree, 10, "E");
    bst_insert_node(tree, 14, "F");
    bst_insert_node(tree, 1, "G");
    bst_insert_node(tree, 3, "H");
    bst_insert_node(tree, 5, "I");
    bst_insert_node(tree, 7, "J");
    bst_insert_node(tree, 9, "K");
    bst_insert_node(tree, 11, "L");
    bst_insert_node(tree, 13, "M");
    bst_insert_node(tree, 15, "N");
    bst_print_tree(tree);
    Node *max = bst_get_maximum(tree);
    Node *min = bst_get_minimum(tree);
    if(max && min)
        printf("MaxTreeKey = %d\nMinTreeKey = %d\n", max->key, min->key);
    printf("\n*****Root removing****\n");
    bst_remove_node(tree, 8);
    bst_print_tree(tree);
    bst_destroy(tree);
    return 0;
}

void print_node(const char* data)
{
    printf("%s-", data);
}

void print_node2(int data)
{
    printf("%d-", data);
}
/*
 * Binary tree
                    8
          4                   12
     2          6       10           14
   1   3      5   7   9    11      13   15
*/

/*
 * Ternary tree
                                     root

            A                         B                              C

    E       F       G        H        I         J          K          L         M
*/
