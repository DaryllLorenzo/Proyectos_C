#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *data;
    int start_pos;
    int insert_count;
    int capacity;
}queue;

// cola de enteros
queue *queue_create(){
    queue *queue = malloc(sizeof(queue));
    queue->capacity = 2;
    queue->start_pos = 0;
    queue->insert_count = 0;

    int *data = calloc(queue->capacity,  sizeof(int));
    if(queue->data == NULL){
        printf("Error al asignar memoria data");
        return NULL;
    }

    return queue;
}

//metodo de agregar 
int queue_add(queue *queue , int *elemento){

    if( queue->capacity <  queue->insert_count ){
        queue->capacity = queue->capacity * 2;
        queue->data = realloc(queue->data, queue->capacity * sizeof(int) );
        if(queue-> data == NULL){
            printf("Error al reasignar memoria queue_add");
            return 0; // An error has ocurred asigning memory
        }
    }
    queue->data[queue->insert_count] = *elemento;
    (queue->insert_count)++;
    return 1; // the item has been added succesfully

}

int queue_delete(queue *queue){
    if(queue->insert_count > queue->start_pos){
        (queue->start_pos)++;
        return queue->data[ (queue->start_pos) - 1];
    }
    return -1;
}

int queue_peek(queue *queue){
    if( (queue->insert_count) > 0){
        return queue->data[ queue->start_pos ];
    }
    return -1;
}

void queue_free(queue *queue){
    free(queue->data);
    free(queue);
}

int main(){


    return 0;
}