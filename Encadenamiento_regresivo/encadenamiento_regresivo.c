#include <stdio.h>
#include <stdlib.h>
#include "encadenamiento_regresivo.h"

typedef struct node_signo{
    int *signo; // siendo 0 negativo 1 positivo
    char *valor;
}node_signo;


node_signo *node_signo_create(){
    node_signo *ns = (node_signo *)malloc(sizeof(node_signo));

    if(ns == NULL){
        printf("Error al asignar memoria! Terminando programa\n");
        exit(1); // cortar la ejecucion del programa
    }

    ns->signo = calloc(1,sizeof(int));
    ns->valor = malloc(sizeof(char));
    return ns;
}

void node_signo_set_valor(node_signo *ns, char *valor){
    ns->valor = valor;
}


char *node_signo_get_valor(node_signo *ns){
    return ns->valor;
}

void node_signo_set_signo(node_signo *ns, int *signo){
    *(ns->signo) = *signo;
}

int *node_signo_get_signo(node_signo *ns){
    return ns->signo;
}

node_signo **node_signo_nodos_forman_regla(node_signo *ns, int *tam_lista){
    int positivo = 0;

    //R1
    if(*(ns->valor) == 'C'){
        node_signo **lista = (node_signo **)malloc(2 * sizeof(node_signo *));

        if(lista == NULL){
            printf("Error al asignar memoria en nodos forman regla function\n");
            exit(1);
        }

        char *l1 = malloc(sizeof(char));
        *l1 = 'A';
        node_signo *n1 = node_signo_create();
        node_signo_set_signo(n1,&positivo);
        node_signo_set_valor(n1,l1);


        char *l2 = malloc(sizeof(char));
        *l2 = 'B';
        node_signo *n2 = node_signo_create();
        node_signo_set_signo(n2,&positivo);
        node_signo_set_valor(n2,l2);

        lista[0] = n1;
        lista[1] = n2;
        *tam_lista = 2;
        return lista;
    }
    // Regla 2
    else if(*(ns->valor) == 'G'){
        node_signo **lista = (node_signo **)malloc(3 * sizeof(node_signo *));

        if(lista == NULL){
            printf("Error al asignar memoria en nodos forman regla function\n");
            exit(1);
        }

        char *l1 = malloc(sizeof(char));
        *l1 = 'D';
        node_signo *n1 = node_signo_create();
        node_signo_set_signo(n1,&positivo);
        node_signo_set_valor(n1,l1);


        char *l2 = malloc(sizeof(char));
        *l2 = 'E';
        node_signo *n2 = node_signo_create();
        node_signo_set_signo(n2,&positivo);
        node_signo_set_valor(n2,l2);


        char *l3 = malloc(sizeof(char));
        *l3 = 'F';
        node_signo *n3 = node_signo_create();
        node_signo_set_signo(n3,&positivo);
        node_signo_set_valor(n3,l3);

        lista[0] = n1;
        lista[1] = n2;
        lista[2] = n3;
        *tam_lista = 3;
        return lista;
    }
    // Regla 3
    else if(*(ns->valor) == 'J'){
        node_signo **lista = (node_signo **)malloc(2 * sizeof(node_signo *));

        if(lista == NULL){
            printf("Error al asignar memoria en nodos forman regla function\n");
            exit(1);
        }

        char *l1 = malloc(sizeof(char));
        *l1 = 'H';
        node_signo *n1 = node_signo_create();
        node_signo_set_signo(n1,&positivo);
        node_signo_set_valor(n1,l1);

        char *l2 = malloc(sizeof(char));
        *l2 = 'I';
        node_signo *n2 = node_signo_create();
        node_signo_set_signo(n2,&positivo);
        node_signo_set_valor(n2,l2);

        lista[0] = n1;
        lista[1] = n2;
        *tam_lista = 2;
        return lista;
    }
    // Regla 4
    else if(*(ns->valor) == 'K'){
        node_signo **lista = (node_signo **)malloc(2 * sizeof(node_signo *));

        if(lista == NULL){
            printf("Error al asignar memoria en nodos forman regla function\n");
            exit(1);
        }


        char *l1 = malloc(sizeof(char));
        *l1 = 'C';
        node_signo *n1 = node_signo_create();
        node_signo_set_signo(n1,&positivo);
        node_signo_set_valor(n1,l1);

        char *l2 = malloc(sizeof(char));
        *l2 = 'G';
        node_signo *n2 = node_signo_create();
        node_signo_set_signo(n2,&positivo);
        node_signo_set_valor(n2,l2);

        lista[0] = n1;
        lista[1] = n2;
        *tam_lista = 2;
        return lista;
    }
    // Regla 5
    else if(*(ns->valor) == 'L'){
        node_signo **lista = (node_signo **)malloc(2 * sizeof(node_signo *));

        if(lista == NULL){
            printf("Error al asignar memoria en nodos forman regla function\n");
            exit(1);
        }

        char *l1 = malloc(sizeof(char));
        *l1 = 'G';
        node_signo *n1 = node_signo_create();
        node_signo_set_signo(n1,&positivo);
        node_signo_set_valor(n1,l1);


        char *l2 = malloc(sizeof(char));
        *l2 = 'J';
        node_signo *n2 = node_signo_create();
        node_signo_set_signo(n2,&positivo);
        node_signo_set_valor(n2,l2);

        lista[0] = n1;
        lista[1] = n2;
        *tam_lista = 2;
        return lista;
    }
    // Regla 6
    else if(*(ns->valor) == 'M'){
        node_signo **lista = (node_signo **)malloc(2 * sizeof(node_signo *));

        if(lista == NULL){
            printf("Error al asignar memoria en nodos forman regla function\n");
            exit(1);
        }

        char *l1 = malloc(sizeof(char));
        *l1 = 'K';
        node_signo *n1 = node_signo_create();
        node_signo_set_signo(n1,&positivo);
        node_signo_set_valor(n1,l1);

        char *l2 = malloc(sizeof(char));
        *l2 = 'L';
        node_signo *n2 = node_signo_create();
        node_signo_set_signo(n2,&positivo);
        node_signo_set_valor(n2,l2);

        lista[0] = n1;
        lista[1] = n2;
        *tam_lista = 2;
        return lista;
    }

    *tam_lista = 0;
    printf("El nodo con valor %c no es resultado de una regla, es nodo base \n", *(ns->valor));
    return NULL;

}


/**
 * @brief esta_en_lista
 * @param elemento
 * @param lista
 * @param size_lista
 * @return Funcion para decir si un elemento(hecho)esta en la lista de hechos
 */
int esta_en_lista(node_signo *elemento, node_signo **lista, int *size_lista){
    int i = 0;
    for(; i< *size_lista ; i++){
        if( *(elemento->valor) == *(lista[i]->valor) ){
            return 1;
        }
    }
    return 0;

}

/**
 * @brief se_cumple_meta
 * @param meta : meta a la que llegar
 * @param hechos : lista de hechos
 * @param size_hechos : tamano de la lista de hechos
 * @param todos_V : para saber si todos los hechos de la lista de hijos se cumplen
 */
void se_cumple_meta(node_signo *meta, node_signo **hechos, int *size_hechos , int *todos_V){
    // crear puntero para tener el tam temporal de la lista de hijos del hecho meta
    int *size_lista = calloc(1,sizeof(int));
    if(size_lista == NULL){
        printf("Error al asignar memoria en size_lista\n");
        exit(1);
    }
    // Obtenemos la lista con su tamano
    node_signo **hechos_forman_regla = node_signo_nodos_forman_regla(meta,size_lista);
    int i = 0;

    // bucle para recorrer la lista de hechos hijos
    while(i < *size_lista){

        // si esta en la lista de hechos solo aumentamos el contador
        if(esta_en_lista(hechos_forman_regla[i], hechos, size_hechos) == 1){
            i++;
        }
        // caso que no este en la lista de hechos se llama a la funcion recursivamente
        // para realizar el mismo proceso hasta llegar a un nodo base o todo sean positivos
        else{
            se_cumple_meta(hechos_forman_regla[i] , hechos, size_hechos,todos_V);
            i++;
        }
    }

    // llegamos a nodo base
    if (hechos_forman_regla == NULL){
        // Nodo base no esta en la lista de hechos
        if( esta_en_lista(meta, hechos, size_hechos) == 0 ){ // si el nodo base no esta en los hechos
            // boolean a false por ende ya el el de arriba no va a ser verdadero y por tanto no se va a poder alcanzar la meta
            *todos_V = 0;
            printf("No se puede alcanzar la meta\n");
            free(size_lista);
            free(hechos_forman_regla);
            return;
        }
    }

    // En el caso que haya cumplido que todos sigan siendo V, podemos agregar el hecho meta de ese momento
    // (recordar que es una funcion recursiva) al arreglo de hechos
    if(*todos_V == 1){
        printf("Iteracion: Agregado a MT %c\n",*(meta->valor));
        hechos = (node_signo **)realloc(hechos, ( (*size_hechos) + 1 ) * sizeof(node_signo *) );
        hechos[*size_hechos] = meta;
        (*size_hechos)++;

    }
    free(size_lista);
    free(hechos_forman_regla);
}

void liberar_hechos(node_signo **hechos, int *size_hechos){
    int i = 0;

    while(i < *size_hechos){
        free(hechos[i]->signo);
        free(hechos[i]->valor);
        free(hechos[i]);
        i++;
    }

    free(size_hechos);
}
