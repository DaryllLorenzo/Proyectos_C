#include <stdio.h>
#include "BinaryTreeNode.c"
#include "BinaryTree.c"
//#include "BinaryTree.h"
//#include "BinaryTreeNode.h"


int main(void){
    // arbol de prueba

    /*
                5
            /       \
          4          9
         / \        / \
        7  10      12 13
    */
    int raiz = 5;

    int izq1 = 4;
    int izq1izq = 7;
    int izq1der = 10;


    int der2 = 9;
    int der2izq = 12;
    int der2der = 13;


    BinaryTreeNode *btn1 = BTN_create(NODE_INT);
    BTN_set_main_info(btn1 , &raiz);


    BinaryTreeNode *btn2 = BTN_create(NODE_INT);
    BTN_set_main_info(btn2 , &izq1);


    BinaryTreeNode *btn3 = BTN_create(NODE_INT);
    BTN_set_main_info(btn3 , &izq1izq);
    BinaryTreeNode *btn4 = BTN_create(NODE_INT);
    BTN_set_main_info(btn4 , &izq1der);


    BTN_set_left(btn1 , btn2);
    BTN_set_left(btn2 , btn3);
    BTN_set_right(btn2 , btn4);


    BinaryTreeNode *btn11 = BTN_create(NODE_INT);
    BTN_set_main_info(btn11 , &der2);
    BinaryTreeNode *btn12 = BTN_create(NODE_INT);
    BTN_set_main_info(btn12 , &der2izq);
    BinaryTreeNode *btn13 = BTN_create(NODE_INT);
    BTN_set_main_info(btn13 , &der2der);


    BTN_set_right(btn1 , btn11);
    BTN_set_left(btn11 , btn12);
    BTN_set_right(btn11 , btn13);


    BinaryTree bt = BT_create(btn1);

    //BinaryTreeNode *btn_result = BT_get_father(&bt, btn11);

    //BTN_print_main_info(btn_result);


    int l = 10;

    //printf("%d",*BTN_get_data_type(btn1));

    BinaryTreeNode *bts = BT_get_node(&bt , &l);

    BTN_print_main_info(bts);

    return 0;
}
