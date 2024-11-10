#include "BinaryTreeNode.h"
#include<stdlib.h>

/**
    Con posibilidad de agregar mas tipos de datos en el futuro
  **/
typedef enum DataTypes{
    NODE_INT,
    NODE_CHAR,
    NODE_FLOAT
}DataTypes;

/**
  Estructura de un Binary Tree Node
  void *main -> el contenido del nodo, puntero void para que sea como tipo de dato generico
  BTN *left -> Referencias a un BTN
  BTN *right -> Referencias a un BTN
  DataTypes dataType -> Tipos de datos como enum
  **/

typedef struct BinaryTreeNode{
    void *main;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    DataTypes dataType;
}BinaryTreeNode;

/**
 * @brief BTN_Create
 * @param dt
 * @return BinaryTreeNode
 *
 * Funcion para crear el BTN, darle su espacio en memoria con Calloc para que todo inicialice en 0 y los valores
 * en NULL
 *
 */

BinaryTreeNode *BTN_create(DataTypes dt){

    // Asignar espacio de memoria en heap al nodo
    BinaryTreeNode *btn = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));

    // fallo al asignar memoria malloc devuelve puntero null
    if(btn == NULL){
        printf("Error al asignar memoria! Terminando programa\n");
        exit(1); // cortar la ejecucion del programa
    }

    btn -> dataType = dt;
    btn -> main = NULL;
    btn -> left = NULL;
    btn -> right = NULL;

    return btn;
}

/**
 * @brief BTN_set_main_info
 * @param node
 * @param data
 *
 * node es el nodo al que le vamo a asignar su dato
 * utilizamos puntero void para la data para que el usuario me pueda mandar varios tipos de datos(como generic dataTypes)
 */

void BTN_set_main_info(BinaryTreeNode *node, void *data){

   if(node->dataType == NODE_INT){
       int *memory = (int *)malloc(sizeof(int));

       if(memory == NULL){
           printf("Error al asignar memoria! Terminando programa\n");
           exit(1); // cortar la ejecucion del programa
       }

       memory = (int *)data;
       node->main = memory;
   }
   else if(node->dataType == NODE_CHAR){
       char *memory = (char *)malloc(sizeof(char));

       if(memory == NULL){
           printf("Error al asignar memoria! Terminando programa\n");
           exit(1); // cortar la ejecucion del programa
       }
       memory = (char *)data;
       node->main = memory;
   }
   else if(node->dataType == NODE_FLOAT){
       float *memory = (float *)malloc(sizeof(float));

       if(memory == NULL){
           printf("Error al asignar memoria! Terminando programa\n");
           exit(1); // cortar la ejecucion del programa
       }
       memory = (float *)data;
       node->main = memory;
   }

}

/**
 * @brief BTN_destroy
 * @param node
 *
 * Funcion para eliminar un nodo, y ademas encargarse de limpiar el espacio que utilizo de the Heap
 *
 */
void BTN_destroy(BinaryTreeNode *node) {
  if (node == NULL) { // Caso base
    return;
  }

  BTN_destroy(node->left);
  BTN_destroy(node->right);

  if (node->main != NULL) {
    free(node->main); // Liberar memoria del dato
  }
  free(node); // Liberar memoria del nodo
}


/**
 * @brief BTN_set_left
 * @param father
 * @param data
 *
 * Asignar referencia de su hijo izquierdo
 */
void BTN_set_left(BinaryTreeNode *father, BinaryTreeNode *data){

    father->left = data;

}

/**
 * @brief BTN_set_right
 * @param father
 * @param data
 *
 * Asignar referencia de su hijo derecho
 */
void BTN_set_right(BinaryTreeNode *father, BinaryTreeNode *data){

    father->right = data;

}

/**
 * @brief BTN_print_main_info
 * @param node
 *
 * Funcion para printear la info main de un nodo por consola
 *
 */
void BTN_print_main_info(BinaryTreeNode *node){
    if(node-> main != NULL){
        if(node->dataType == NODE_INT){
            int *ptr = (int *)node->main;
            printf("Value: %d\n",*ptr);
        }
        else if(node->dataType == NODE_CHAR){
            char *ptr = (char *)node->main;
            printf("Value: %c\n",*ptr);
        }
        else if(node->dataType == NODE_FLOAT){
            float *ptr = (float *)node->main;
            printf("Value: %f\n",*ptr);
        }
    }
    else {
        printf("Probably NULL\n");
    }
}

/**
 * @brief BTN_get_left
 * @param node
 * @return BinaryTreeNode *left
 */

BinaryTreeNode *BTN_get_left(BinaryTreeNode *node){
    // hay q ver caso de null
    return node->left;
}


/**
 * @brief BTN_get_right
 * @param node
 * @return BinaryTreeNode *right
 */

BinaryTreeNode *BTN_get_right(BinaryTreeNode *node){
    // hay que ver caso null
    return node->right;
}

/**
 * @brief BTN_get_data_type
 * @param node
 * @return data type of the node
 */
DataTypes *BTN_get_data_type(BinaryTreeNode *node){
    return &node->dataType;
}


/**
 * @brief BTN_get_data
 * @param node
 * @return
 */

void *BTN_get_data(BinaryTreeNode *node){

    return node->main;
}

