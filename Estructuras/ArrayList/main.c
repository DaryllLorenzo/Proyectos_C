#include "Arraylist.c"

int main() {
    Arraylist a;
    initArrayList(&a); // Inicializar el Arraylist

    // Agregar elementos al Arraylist
    for (int i = 0; i < 10; i++) {
        append(&a, i);
    }

    for (int i = 0; i < a.count; i++) {
        printf("Element %d: %d\n", i, a.items[i]);
    }

    freeArrayList(&a); // Liberar la memoria antes de terminar
    return 0;
}