#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int dado;
    struct Nodo *next;
    
}Nodo;

typedef struct{
    Nodo *Front;
    Nodo *Rear;
}FSE;

void iniciar_fila(FSE *f);
void destruir_fila(FSE *f);
void reiniciar_fila(FSE *f);
int isEmpty_fila(FSE *f);
int enqueue_fila(FSE *f, int dado);
int dequeue_fila(FSE *f, int *dado_retorno);
