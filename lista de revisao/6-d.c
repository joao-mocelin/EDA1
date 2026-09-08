#include <stdio.h>

struct nodo{
    int x;
    struct nodo *esq;
    struct nodo *dir;
};

struct descritor{
    unsigned int posicao;
    struct nodo *primeiro, *ultimo, *link;
};

int contaNodo(struct descritor *p){
    if(p->primeiro == NULL){
        return 0;
    }
    if(p->primeiro == p->ultimo){
        return 1;
    }
    unsigned int cont = p->posicao;
    struct nodo *aux = p->link;
    while(aux->dir != NULL){
        cont++;
        aux = aux->dir;
    }
    return cont;
}

int main(){
    struct nodo a1,a2,a3,a4,a5,a6,a7,a8;
    struct descritor p = {4,&a1,&a8,&a4};
    a1.dir = &a2;
    a2.dir = &a3;
    a3.dir = &a4;
    a4.dir = &a5;
    a5.dir = &a6;
    a6.dir = &a7;
    a7.dir = &a8;
    a8.dir = NULL;
    printf("\n %d",contaNodo(&p));
    return 0;
}