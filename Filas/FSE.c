#include "FSE.h"

void iniciar_fila(FSE *f){
    f->Front = f->Rear = NULL;
}

int isEmpty_fila(FSE *f){
    if(f->Front == NULL && f->Rear == NULL){
        return 1;
    }
    return 0;
}

void destruir_fila(FSE *f){
    if(isEmpty_fila(f)){
        return;
    }
    f->Rear = NULL;
    Nodo *aux = f->Front;
    while(aux != NULL){
        f->Front = aux->next;
        free(aux);
        aux = f->Front;
    }
}

void reiniciar_fila(FSE *f){
    if(isEmpty_fila(f)){
        return;
    }
    destruir_fila(f);
    iniciar_fila(f);
}

int enqueue_fila(FSE *f, int dado){
    Nodo *new = malloc(sizeof(Nodo));
    if(new == NULL){
        printf("\nERRO: Falha na alocacao de memoria.");
        return 0;
    }
    new->dado = dado;
    new->next = NULL;
    if(isEmpty_fila(f)){
        f->Rear = f->Front = new;
        return 1;
    }
    f->Rear->next = new;
    f->Rear = new;
    return 1;
}

int dequeue_fila(FSE *f, int *dado_retorno){
    if(isEmpty_fila(f)){
        printf("\nERRO: Fila vazia. Impossivel desenfileirar.");
        return 0;
    }
    *dado_retorno = f->Front->dado;
    Nodo *aux = f->Front;
    f->Front = f->Front->next;
    free(aux);
    if(f->Front == NULL){
        f->Rear = NULL;
    }
    return 1;
}