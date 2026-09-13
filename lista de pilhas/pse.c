#include "pse.h"

void inicializar(Pilha *p){
    p->topo = NULL;
}

int isEmpty(Pilha *p){
    if(p == NULL || p->topo == NULL){
        return 1; //vazia
    }
    return 0; // contem elementos 
}

int push(Pilha *p, int valor){
    Nodo *aux = malloc(sizeof(Nodo));
    if (aux == NULL) {
        return 0; // Falha na alocação
    }
    if(p->topo == NULL){
        p->topo = aux;
        aux->prox = NULL;
        return 1;
    }
    aux->prox = p->topo;
    p->topo = aux;
    aux->x = valor;
    return 1;
}

int pop(Pilha *p){
    int valor = 0;
    if(p->topo == NULL){
        return valor;
    }
    valor = p->topo->x;
    Nodo *aux = p->topo;
    p->topo = aux->prox;
    free(aux);
    return valor;
}

int peek(Pilha *p){
    int valor = 0;
    if(isEmpty(p) == 1){
        return valor;
    }
    valor = p->topo->x;
    return valor;
}

void imprime_pilha(Pilha *p){
    if(isEmpty(p) == 1){
        printf("\nPilha vazia");
        return;
    }
    Nodo *aux = p->topo;
    printf("\nTOPO");
    while(aux != NULL){
        printf(" -> | %d |", aux->x);
        aux = aux->prox;
    }
    printf(" BASE\n");
    return;
}