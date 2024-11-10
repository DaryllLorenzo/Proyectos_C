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


/**
 * @brief BT_get_node_level
 * @param tree
 * @param node
 * @return int level of the node
 */

int BT_get_node_level(BinaryTree *tree, BinaryTreeNode *node){
    if(node != NULL){
        if( node == tree->root){ //caso base de que llega a la raiz
            return 0;
        }
        else{
            //busca el nodo padre del nodo, luego llamamos
            //recursivamente para encontrar el nivel del padre,
            //y le sumamos 1 porq el nodo esta a un nivel mas bajo que el padre
            return BT_get_node_level(tree, BT_get_father(tree,node)) + 1;
        }
    }
    return -1; // el nodo no existe y devolvemos -1 para confirmarlo
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

/**
 * @brief BT_print_preorder
 * @param tree
 * N - I - D
 */
void BT_print_preorder(BinaryTree *tree){
    if(tree->root != NULL){
        BTN_print_main_info(tree->root);
        BinaryTree temp = BT_create(BTN_get_left(tree->root));
        BT_print_preorder(&temp);
        temp.root = BTN_get_right(tree->root);
        BT_print_preorder(&temp);
    }
}

/**
 * @brief BT_print_inorder
 * @param tree
 * I - N - D
 */

void BT_print_inorder(BinaryTree *tree){
    if(tree->root != NULL){
        BinaryTree temp = BT_create(BTN_get_left(tree->root));
        BT_print_inorder(&temp);
        BTN_print_main_info(tree->root);
        temp.root = BTN_get_right(tree->root);
        BT_print_inorder(&temp);
    }
}

/**
 * @brief BT_print_postorder
 * @param tree
 * I - D - N
 */
void BT_print_postorder(BinaryTree *tree){
    if(tree->root != NULL){
        BinaryTree temp = BT_create(BTN_get_left(tree->root));
        BT_print_postorder(&temp);
        temp.root = BTN_get_right(tree->root);
        BT_print_postorder(&temp);
        BTN_print_main_info(tree->root);
    }
}

/**
 * @brief BT_get_total_nodes
 * @param tree
 * @return int cantidad total de nodos
 * Recorrido preorder N - I - D para contar
 */
int BT_get_total_nodes(BinaryTree *tree) {
    int count = 0;
    if (tree->root != NULL) {
        count++; // Contar nodo
        BinaryTree temp = BT_create(BTN_get_left(tree->root));
        count += BT_get_total_nodes(&temp); // Contar subarbol izq
        temp.root = BTN_get_right(tree->root);
        count += BT_get_total_nodes(&temp); // Contar subarbol derecho
    }
    return count;
}

/**
 * @brief BT_get_sons
 * @param node
 * @return arreglo de hijos del nodo (recordar liberar cuando no se necesite el arreglo)
 */
BinaryTreeNode **BT_get_sons(BinaryTreeNode *node){
    int num_sons = 0;

    // Comprobar la cantidad de hijos para saber el espacio de memoria para asignar
    if(BTN_get_left(node) != NULL){
        num_sons++;
    }
    if(BTN_get_right(node) != NULL){
        num_sons++;
    }
    if(num_sons == 0){ // no tiene hijos
        return NULL;
    }
    // Asignar memoria para el arreglo de hijos en heap, recordar que cuando se termine de utilizar hay que liberarlo
    BinaryTreeNode **sons = (BinaryTreeNode **)calloc(num_sons,sizeof(BinaryTreeNode));

    if(sons == NULL){
        printf("\n !! Error asignacion de memoria get_sons\n");
        exit(1);
    }

    // Asignar los hijos al arreglo
    int contador = 0;
    if(BTN_get_left(node) != NULL){
        sons[contador] = BTN_get_left(node);
        contador++;
    }
    if(BTN_get_right(node) != NULL){
        sons[contador] = BTN_get_right(node);
        contador++;
    }

    return sons;
}

/**
 * @brief BT_free_sons
 * @param sons(arreglo de hijos que se obtiene de la funcion get_sons)
 */
void BT_free_sons(BinaryTreeNode **sons){
    if (sons != NULL) {
        free(sons);
    }
}
