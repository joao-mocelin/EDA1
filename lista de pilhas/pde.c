#include "pde.h"

void inicializar(Pilha *p){
    p->base = NULL;
    p->topo = NULL;
    return;
}

int isEmpty(Pilha *p){
    if(p->topo == NULL){
        return 1;
    }
    return 0;
}

int push(Pilha *p, int valor){
    Nodo *aux = malloc(sizeof(Nodo));
    if(aux == NULL){
        return 0;
    }
    if(p->base == NULL){
        aux->ant = NULL;
        aux->post = NULL;
        aux->x = valor;
        p->topo = aux;
        p->base = aux;
        return 1;
    }
    aux->ant = NULL;
    aux->post = p->topo;
    aux->x = valor;
    p->topo->ant = aux;
    p->topo = aux;
    return 1;
}

int pop(Pilha *p, int *popped){
    if(isEmpty(p)){
        return 0;
    }
    if(p->base == p->topo){
        *popped = p->topo->x;
        free(p->topo);
        p->base = NULL;
        p->topo = NULL;
        return 1;
    }
    *popped = p->topo->x;
    Nodo *aux = p->topo->post;
    aux->ant = NULL;
    free(p->topo);
    p->topo = aux;
    return 1;
}

int peek(Pilha *p){
    if(isEmpty(p)){
        return 0;
    }
    return p->topo->x;
}

void destruir(Pilha *p){
    if(p->topo == NULL){
        free(p);
        return;
    }
    Nodo *aux = p->topo;
    while(aux != NULL){
        Nodo *remover = aux;
        aux = aux->post;
        free(remover);
    }
    return;
}