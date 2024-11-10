#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<stdio.h>
#include "BinaryTreeNode.h"

typedef struct BinaryTree BinaryTree;

BinaryTree BT_create(BinaryTreeNode *root);
BinaryTreeNode *BT_get_father(BinaryTree *tree, BinaryTreeNode *node);
BinaryTreeNode *BT_get_node(BinaryTree *tree, void *data);
int BT_get_node_level(BinaryTree *tree, BinaryTreeNode *node);
int BT_get_total_nodes(BinaryTree *tree);
void BT_print_preorder(BinaryTree *tree); // N-I-D
void BT_print_inorder(BinaryTree *tree); // I-N-D
void BT_print_postorder(BinaryTree *tree); // I-D-N

BinaryTreeNode **BT_get_sons(BinaryTreeNode *node);
void BT_free_sons(BinaryTreeNode **sons); // liberar sons, siempre que haya un get_sons debe haber un free_sons

#endif
