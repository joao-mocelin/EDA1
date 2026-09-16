#include "pse.h"

int contaNodos(Pilha *p){
    if(p == NULL || p->topo == NULL){
        return 0;
    }
    Nodo *aux = p->topo;
    int cont = 0;
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
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
    printf("\n numero de nodos = %d",contaNodos(p));
    return 0;
}   