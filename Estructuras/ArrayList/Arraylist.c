#include <stdlib.h>
#include "Arraylist.h" // Incluye el archivo de cabecera

// Inicializar el Arraylist
void initArrayList(Arraylist *a) {
    a->count = 0;              
    a->max_capacity = 2;           // Capacidad inicial de 2 elementos
    a->items = calloc(2 , sizeof(int) );
}

// Función para liberar la memoria del Arraylist
void freeArrayList(Arraylist *a) {
    free(a->items);
    a->items = NULL; // Evitar punteros colgantes
}

// Función para agregar un elemento
void append(Arraylist *a, int item) {
    // Duplicar capacidad max si la lista esta llena
    if (a->count >= a->max_capacity) {
        a->max_capacity *= 2;
        a->items = realloc(a->items, a->max_capacity * sizeof(int)); // Reasignar memoria
    }
    a->items[a->count] = item; // Agregamos el nuevo elemento
    a->count++; // Incrementar el contador de elementos
}


// Continuara