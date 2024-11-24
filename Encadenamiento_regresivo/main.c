#include "encadenamiento_regresivo.c"

int main(void){
    printf("Programa encadenamiento regresivo, Daryll Lorenzo Alfonso G-31\n\n");
    // definir base de conocimiento/reglas

    int *todos_V = calloc(1,sizeof(int));
    *todos_V = 1;

    int positivo = 1;
    char h1_val = 'D';
    char h2_val = 'E';
    char h3_val = 'L';
    char h4_val = 'F';
    char h5_val = 'A';
    char h6_val = 'B';
    char meta_val = 'M';

    // Definir hechos (arreglo de nodeSigno)
    node_signo *h1 = node_signo_create();
    node_signo_set_valor(h1,&h1_val);
    node_signo_set_signo(h1,&positivo);

    node_signo *h2 = node_signo_create();
    node_signo_set_valor(h2,&h2_val);
    node_signo_set_signo(h2,&positivo);

    node_signo *h3 = node_signo_create();
    node_signo_set_valor(h3,&h3_val);
    node_signo_set_signo(h3,&positivo);

    node_signo *h4 = node_signo_create();
    node_signo_set_valor(h4,&h4_val);
    node_signo_set_signo(h4,&positivo);

    node_signo *h5 = node_signo_create();
    node_signo_set_valor(h5,&h5_val);
    node_signo_set_signo(h5,&positivo);

    node_signo *h6 = node_signo_create();
    node_signo_set_valor(h6,&h6_val);
    node_signo_set_signo(h6,&positivo);

    node_signo *meta = node_signo_create();
    node_signo_set_valor(meta,&meta_val);
    node_signo_set_signo(meta,&positivo);


    // Hechos iniciales
    int *size_hechos = calloc(1,sizeof(int));
    *size_hechos = 6;
    node_signo **hechos = (node_signo **)malloc(*size_hechos * sizeof(node_signo *));
    hechos[0] = h1;
    hechos[1] = h2;
    hechos[2] = h4;
    hechos[3] = h3;
    hechos[4] = h5;
    hechos[5] = h6;
    // Hay que buscar si se cumple la meta

    se_cumple_meta(meta, hechos, size_hechos,todos_V);

    if( esta_en_lista(meta, hechos, size_hechos) ){
        int z = 0;
        printf("\nMemoria de trabajo\n");
        for(; z< *size_hechos; z++){
            printf("%c...%p\n",*(hechos[z]->valor), hechos[z]);
        }
        printf("Se llega a la meta\n\n");
        liberar_hechos(hechos, size_hechos);
    }
    else{
        liberar_hechos(hechos, size_hechos);
        free(meta);
    }

    free(todos_V);

    return 0;
}
