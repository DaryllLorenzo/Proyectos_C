// arraylist.h

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdio.h>

typedef struct{
    int *items;           // Elementos del array
    size_t count;         // Cantidad actual de elementos
    size_t max_capacity;  // Capacidad máxima del array
}Arraylist;

void initArrayList(Arraylist *a);
void freeArrayList(Arraylist *a);
void append(Arraylist *a, int item);

// Continuara

#endif // ARRAYLIST_H
