#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<stdio.h>
#include "BinaryTreeNode.h"

typedef struct BinaryTree BinaryTree;

// Empezar por funcion create y el tema de la memoria ya que el arbol si es dinamico

BinaryTree BT_create(BinaryTreeNode *root);

BinaryTreeNode *BT_get_father(BinaryTree *tree, BinaryTreeNode *node);

BinaryTreeNode *BT_get_node(BinaryTree *tree, void *data);


//BT_get_node_level

#endif
