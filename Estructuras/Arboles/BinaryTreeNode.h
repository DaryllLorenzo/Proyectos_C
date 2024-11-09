#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

#include<stdio.h>

typedef enum DataTypes DataTypes;

typedef struct BinaryTreeNode BinaryTreeNode;

BinaryTreeNode *BTN_create(DataTypes dt);
void BTN_set_main_info(BinaryTreeNode *node, void *data);
void BTN_set_left(BinaryTreeNode *father, BinaryTreeNode *data);
void BTN_set_right(BinaryTreeNode *father, BinaryTreeNode *data);
void BTN_print_main_info(BinaryTreeNode *node);
void BTN_destroy(BinaryTreeNode *node);
BinaryTreeNode *BTN_get_left(BinaryTreeNode *node);
BinaryTreeNode *BTN_get_right(BinaryTreeNode *node);

// Faltan "getters y setters"

#endif
