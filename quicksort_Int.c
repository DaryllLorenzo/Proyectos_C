#include <stdio.h>
#include <stdlib.h>

void quicksort(int *array, int length){

    // Caso base de parada
    if(length <= 1){
        return;
    }

    // Tomamos pivote el ultimo elemento
    int pivot = array[length - 1];

    // Crear arreglos temporales para ordenar los elementos
    int *smallest = malloc(length * sizeof(int));
    int *greater = malloc(length * sizeof(int));

    // Bucle para definir a donde va cada elemento
    int i = 0;
    int j = 0;
    int l = 0;
    for(i = 0; i < length - 1; i++){
        if(array[i] < pivot){
            smallest[j] = array[i];
            j++;
        }
        else{
            greater[l] = array[i];
            l++;
        }
    }

    // Llamadas recursivas para que se organicen
    quicksort(smallest, j);
    quicksort(greater, l);

    // Copiar los valores de nuevo al array
    for (i = 0; i < j; i++) {
        array[i] = smallest[i];
    }
    // Poner al pivote en su posicion correcta
    array[j] = pivot;

    for(i = 0; i < l; i++) {
        array[j + 1 + i] = greater[i];
    }

    // Liberar el espacio de memoria para los arreglos dinamicos
    free(smallest);
    free(greater);

}


int main(void) {
    int array[] = {7, 2, 5, 4,7}; // arreglo de prueba
    int length = sizeof(array) / sizeof(array[0]); // calcular la cantidad de elementos del arreglo
    quicksort(array,length);

    int i = 0;

    for(i = 0; i < length; i++){
        printf("%d\n",array[i]);
    }

    return 0;
}
