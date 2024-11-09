#include <stdlib.h>
#include "BinaryTree.h"


typedef struct BinaryTree{
    BinaryTreeNode *root;
}BinaryTree;


BinaryTree BT_create(BinaryTreeNode *root){
    BinaryTree BT;

    BT.root = root;

    return BT;
}


BinaryTreeNode *BT_get_father(BinaryTree *tree, BinaryTreeNode *node) {
    // Caso de que algo sea NULL
    if (tree == NULL || tree->root == NULL || node == NULL) {
        return NULL;
    }

    // Si el nodo es padre de el nodo que buscamos, lo retornamos
    if (tree->root->left == node || tree->root->right == node) {
        return tree->root;
    }

    // Recorrer el subarbol izq
    BinaryTree bt_temp;
    bt_temp.root = tree->root->left;

    BinaryTreeNode *result = BT_get_father(&bt_temp, node);

    if (result != NULL) {
        return result; // Se encontro en el subarbol izq
    }

    // Proceder con el subarbol derecho si no aparecio en el izq
    bt_temp.root = tree->root->right;
    result = BT_get_father(&bt_temp, node);

    // Retorna el resultado final, o NULL si no se encontro
    return result;
}
