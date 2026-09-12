#include "pse.h"

int buscaBase(Pilha *p){
    if(isEmpty(p) == 1){
        printf("\nPilha vazia");
        return 0;
    }
    Nodo *aux = p->topo;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    return aux->x;
}

int main(){
    Pilha stack;
    Pilha *p = &stack;
    Nodo a = {10,NULL}, b = {20, NULL}, c = {30,NULL}, d = {40, NULL}, e = {50, NULL};
    a.prox = &b;
    b.prox = &c;
    c.prox = &d;
    d.prox = &e;
    p->topo = &a;
    imprime_pilha(p);
    printf("\nBase da pilha = %d",buscaBase(p));
    return 0;
}