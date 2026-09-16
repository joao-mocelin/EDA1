#include "pde.h"

int inverte(Pilha *p){
    if(isEmpty(p) || p->base == p->topo){
        return 1;
    }
    Nodo *atual = p->topo;
    Nodo *aux1;
    while(atual != NULL){
        aux1 = atual->post;
        atual->post = atual->ant;
        atual->ant = aux1;
        atual = atual->ant;
    }
    Nodo *aux2 = p->topo;
    p->topo = p->base;
    p->base = aux2;
    return 0;
}

int main(){
    Pilha stack;
    Nodo a = {10,NULL,NULL}, b = {20,NULL,NULL}, c = {30,NULL,NULL}, d = {40,NULL,NULL}, e = {50,NULL,NULL};
    Pilha *p = &stack;
    p->topo = &a;
    p->base = &e;
    a.post = &b;
    b.ant = &a;
    b.post = &c;
    c.ant = &b;
    c.post = &d;
    d.ant = &c;
    d.post = &e;
    e.ant = &d;
    imprime_pilha(p);
    if(inverte(p)){
        return 1;
    }
    imprime_pilha(p);
    return 0;
}