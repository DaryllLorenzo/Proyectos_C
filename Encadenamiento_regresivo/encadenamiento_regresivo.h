#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

typedef struct node_signo node_signo;
node_signo *node_signo_create();
void node_signo_set_valor(node_signo *ns, char *valor);
char *node_signo_get_valor(node_signo *ns);
void node_signo_set_signo(node_signo *ns, int *signo);
int *node_signo_get_signo(node_signo *ns);
node_signo **node_signo_nodos_forman_regla(node_signo *ns, int *tam_lista);
int esta_en_lista(node_signo *elemento, node_signo **lista, int *size_lista);
void se_cumple_meta(node_signo *meta, node_signo **hechos, int *size_hechos , int *todos_V);
void liberar_hechos(node_signo **hechos, int *size_hechos);
#endif
