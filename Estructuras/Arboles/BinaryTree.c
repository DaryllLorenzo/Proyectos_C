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


BinaryTreeNode *BT_get_node(BinaryTree *tree, void *data){

    if (tree->root == NULL){
        return NULL;
    }

    // Caso de que el tipo de dato sea Entero (valor 0 en el enum)
    if( *BTN_get_data_type(tree->root) == 0 ){

        // casteamos a entero porque es puntero void
        if( *((int *)BTN_get_data(tree->root)) == *((int *)data) ){  // caso base
            return tree->root;
        }

        // recusividad
        BinaryTree bt = BT_create(BTN_get_left(tree->root));
        BinaryTreeNode *result = BT_get_node(&bt, data);

        if (result != NULL){
            return result;  //encontro el nodo por la izq
        }

        bt.root = BTN_get_right(tree->root); //seteamos para buscar por el subarbol derecho
        result = BT_get_node(&bt, data);

        return result; // devolvemos lo que encontro ya sea el nodo o NULL

    }

    // Caso de que el tipo de dato sea char (valor 1 en el enum)
    else if ( *BTN_get_data_type(tree->root) == 1 ){

        // casteamos a char porque es puntero void
        if( *((char *)BTN_get_data(tree->root)) == *((char *)data) ){
            return tree->root;
        }

        // recusividad
        BinaryTree bt = BT_create(BTN_get_left(tree->root));
        BinaryTreeNode *result = BT_get_node(&bt, data);

        if (result != NULL){
            return result;  //encontro el nodo por la izq
        }

        bt.root = BTN_get_right(tree->root);
        result = BT_get_node(&bt, data);

        return result;

    }

    // Caso de que el tipo de dato sea float (valor 2 en el enum)
    else if ( *BTN_get_data_type(tree->root) == 2 ){

        // casteamos a float porque es puntero void
        if( *((float *)BTN_get_data(tree->root)) == *((float *)data) ){
            return tree->root;
        }


        // recusividad
        BinaryTree bt = BT_create(BTN_get_left(tree->root));
        BinaryTreeNode *result = BT_get_node(&bt, data);

        if (result != NULL){
            return result;  //encontro el nodo por la izq
        }

        bt.root = BTN_get_right(tree->root); //ponemos a buscar por la derecha
        result = BT_get_node(&bt, data);

        return result; // devolvemos lo que encontro ya sea el nodo o NULL

    }

    return NULL;

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
    BinaryTree bt_temp = BT_create(BTN_get_left(tree->root));

    BinaryTreeNode *result = BT_get_father(&bt_temp, node);

    if (result != NULL) {
        return result; // Se encontro en el subarbol izq
    }

    // Proceder con el subarbol derecho si no aparecio en el izq
    bt_temp.root = BTN_get_right(tree->root);
    result = BT_get_father(&bt_temp, node);

    // Retorna el resultado final, o NULL si no se encontro
    return result;
}
