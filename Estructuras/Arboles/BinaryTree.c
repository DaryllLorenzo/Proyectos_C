#include <stdlib.h>
#include "BinaryTree.h"


typedef struct BinaryTree{
    BinaryTreeNode *root;
}BinaryTree;

/**
 * @brief BT_create
 * @param root
 * @return Arbol binario
 */
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

/**
 * @brief BT_get_node
 * @param tree
 * @param data
 * @return El nodo a partir de un valor dado (caso de que la info de los nodos sea unica)
 */
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

/**
 * @brief BT_get_father
 * @param tree
 * @param node
 * @return el padre de un nodo dado
 */
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
    BinaryTreeNode **sons = (BinaryTreeNode **)calloc(num_sons, sizeof(BinaryTreeNode *));

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

/**
 * @brief BT_get_total_leaves
 * @param tree
 * @return total count of leaves
 */
int BT_get_total_leaves(BinaryTree *tree){
    int num_leaves = 0;

    if(tree->root != NULL){

        if(BTN_get_left(tree->root) == NULL && BTN_get_right(tree->root) == NULL){
            num_leaves++;
        }
        BinaryTree temp = BT_create(BTN_get_left(tree->root));
        num_leaves+=BT_get_total_leaves(&temp);
        temp.root = BTN_get_right(tree->root);
        num_leaves+=BT_get_total_leaves(&temp);
    }

    return num_leaves;
}

/**
 * @brief _Get_leaves_recursive
 * @param tree
 * @param leaves
 * @param iter
 *
 * Funcion "privada" solo para llenar el array de hojas
 */
static void _Get_leaves_recursive(BinaryTree *tree, BinaryTreeNode **leaves, int *iter){

    if(tree->root != NULL){
        if(BTN_get_left(tree->root) == NULL && BTN_get_right(tree->root) == NULL ){
            leaves[*iter] = tree->root;
            (*iter)++;
        }
        BinaryTree temp = BT_create(BTN_get_left(tree->root));
        _Get_leaves_recursive(&temp, leaves, iter);
        temp.root = BTN_get_right(tree->root);
        _Get_leaves_recursive(&temp, leaves, iter);
    }
}

/**
 * @brief BT_get_leaves
 * @param tree
 * @return arreglo de hojas
 */
BinaryTreeNode **BT_get_leaves(BinaryTree *tree){
    int total_leaves = BT_get_total_leaves(tree);
    BinaryTreeNode **leaves = (BinaryTreeNode **)calloc(total_leaves, sizeof(BinaryTreeNode *));

    if(leaves == NULL){
        printf("\n !! Error asignacion de memoria get_sons\n");
        exit(1);
    }
    int i = 0;

    _Get_leaves_recursive(tree, leaves, &i);

    return leaves;
}

/**
 * @brief BT_free_leaves
 * @param leaves
 * Para liberar el espacio utilizado por el arreglo de hojas
 * Siempre que haya un get_leaves debe haber un free_leaves
 */
void BT_free_leaves(BinaryTreeNode **leaves){
    if(leaves != NULL){
        free(leaves);
    }
}


/**
 * @brief _Find_node
 * @param tree
 * @param node
 * @return 1 si el nodo existe, 0 si no existe
 */
static int _Find_node(BinaryTree *tree, BinaryTreeNode *node){

    if(node == NULL){
        return 0;
    }

    if (tree->root == node) {
        return 1; // El nodo es la raíz
    }

    if (tree->root != NULL) {
        BinaryTree bt = BT_create(BTN_get_left(tree->root));
        if (_Find_node(&bt, node) == 1) {
            return 1; // Nodo encontrado en el subárbol izquierdo
        }
        bt.root = BTN_get_right(tree->root);
        if (_Find_node(&bt, node) == 1) {
            return 1; // Nodo encontrado en el subárbol derecho
        }
    }

    return 0; // Nodo no encontrado
}

/**
 * @brief BT_insert_node
 * @param tree
 * @param node
 * @param location
 * @param father
 *
 * Insertar nodo en el arbol, si el padre es NULL o el padre no existe, se asigna como root el nodo,
 * y la antigua raiz se le pone como hijo en base a la localizacion 'r' o 'l'
 *
 * Si el padre existe se agrega como hijo el nodo en base a la localizacion,
 * y el antiguo hijo se agrega como hijo del nuevo nodo a partir de la misma localizacion
 *
 */
void BT_insert_node(BinaryTree *tree, BinaryTreeNode *node, char location, BinaryTreeNode *father){

    if(node != NULL){

        int father_exist = 0; // 0 false - 1 true

        father_exist = _Find_node(tree , father);

        // caso de que si exista el padre
        if(father_exist == 1){

            if(location == 'r' || location == 'R'){

                BinaryTreeNode *temp = BTN_get_right(father);

                BTN_set_right(father , node);

                // donde pondriamos el resto del arbol, yo decidi ponerlo igual que la letra que se selecciono
                BTN_set_right(node,temp);

            }
            else if(location == 'l' || location == 'L'){

                BinaryTreeNode *temp = BTN_get_left(father);

                BTN_set_left(father , node);

                // donde pondriamos el resto del arbol, yo decidi ponerlo igual que la letra que se selecciono
                BTN_set_left(node,temp);
            }

            // Error en caso de que no selecciono l o r
            else{
                printf("Localizacion de inserccion erronea (debe ser r o l)\n");
                exit(1);
            }
        }

        // No existe el padre, se pone el nodo como raiz, y la raiz de va del lado que puso si l o r
        else{
            BinaryTreeNode *temp = tree->root;

            tree->root = node;

            if(location == 'r' || location == 'R'){
                BTN_set_right(tree->root, temp);
            }
            else if(location == 'l' || location == 'L'){
                BTN_set_left(tree->root, temp);
            }

            // Error en caso de que no selecciono l o r
            else{
                printf("Localizacion de inserccion erronea (debe ser r o l)\n");
                exit(1);
            }

        }
    }
}

/**
 * @brief BT_delete_node
 * @param tree
 * @param node
 * Funcion para borrar un nodo del arbol, borra el nodo y toda su descendencia
 * Una vez ejecutado esto, tener cuidado de no acceder/utilizar un nodo que por resultado de esto
 * fue liberado de la memoria.
 */
void BT_delete_node(BinaryTree *tree, BinaryTreeNode *node){

    if(node != NULL){

        BinaryTreeNode *father = BT_get_father(tree, node); // obtener el padre para eliminar posibles referencias

        //caso de que sea la raiz
        if(father == NULL){
            BTN_destroy(node); // eliminar todo el arbol
            tree = NULL;
        }
        // caso de no raiz
        else{
            // si el nodo es el hijo izq
            if(BTN_get_left(father) == node){
                BTN_set_left(father, NULL); //la referencia al hijo izq a null para evitar comportamientos inesperados y accesos no permitidos
            }
            else if(BTN_get_right(father) == node){
                BTN_set_right(father,NULL);//la referencia al hijo derecho a null para evitar comportamientos inesperados y accesos no permitidos
            }

            BTN_destroy(node); // ahora si eliminar el nodo y su descendencia
        }
    }
}

