#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *data;
    size_t count;
    size_t capacity;
}Stack;


Stack *create_stack(){
    Stack *pila = malloc(sizeof(Stack));
    if(pila == NULL){
        printf("Error al asignar memoria en crear pila\n");
        exit(1);
    }
    pila->count = 0;
    pila->capacity = 2;
    pila->data = calloc(2 , sizeof(int));
    if(pila->data == NULL){
        printf("Error al asignar memoria en crear pila\n");
        exit(1);
    }

    return pila;
}

void push(Stack *pila, int number){

    // Comprobar si es necesario redimensionar la pila
    if(pila->count >= pila->capacity){
        // Nueva capacidad para la pila
        pila->capacity = pila->capacity * 2;
        // Reasignamos memoria
        pila->data = realloc(pila->data , pila->capacity * sizeof(int));
        if(pila->data == NULL){
            printf("Error al asignar memoria en push\n");
            exit(1);
        }
    }

    // Agregamos el elemento a la pila
    pila->data[pila->count] = number;
    pila->count++;

}

void pop(Stack *pila){
    // solo si la pila tiene elementos
    if(pila->count > 0){
        pila->count--;
    }
}

// funcion para liberar la memoria
void freeStack(Stack *pila){
    free(pila->data);
    free(pila);
}

int peek(Stack *pila){

    if(pila->count == 0){
        printf("Error al acceder a pila vacia");
        exit(1);
    }

    int last = pila->data[pila->count - 1];

    return last;
}


int main(void)
{
    Stack *ptr = create_stack();

    push(ptr,15);
    push(ptr,1);
    push(ptr,12);
    pop(ptr);
    push(ptr,0);
    push(ptr,8);
    pop(ptr);
    push(ptr,7);

    printf("%d\n",peek(ptr));
    freeStack(ptr);
    ptr = NULL;

    return 0;
}

