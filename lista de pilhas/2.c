#include "pse.h"

typedef struct{
    Nodo *base;
    Nodo *topo;
}DescritorPSE;

int inverte(DescritorPSE *p){
    if(p == NULL || p->base == NULL || p->topo == NULL){
        return 0;
    }
    Nodo *ant = NULL;
    Nodo *atual = p->topo;
    Nodo *post;
    while (atual != NULL)
    {
        post = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = post;
    }
    p->topo = p->base;
    p->base = atual;
    return 1;
}

int main(){
    Nodo a = {10,NULL}, b = {20, NULL}, c = {30,NULL}, d = {40, NULL}, e = {50, NULL};
    a.prox = &b;
    b.prox = &c;
    c.prox = &d;
    d.prox = &e;
    DescritorPSE pilha = {&e,&a};
    DescritorPSE *p = &pilha;
    Nodo *aux = p->topo;
    printf("\nTOPO");
    while(aux != NULL){
        printf(" -> | %d |", aux->x);
        aux = aux->prox;
    }
    printf(" BASE\n");
    inverte(p);
    aux = p->topo;
    printf("\nTOPO");
    while(aux != NULL){
        printf(" -> | %d |", aux->x);
        aux = aux->prox;
    }
    printf(" BASE\n");
    return 0;
}