/*

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *proximo;
}No;

typedef struct{
    No *topo;
}Pilha;

void inicializar(Pilha *p){
    p->topo = NULL;
}

int isEmpty(Pilha *p){ //return 1 = vazia
    return p->topo == NULL;
}

int push(Pilha *p, int valor){
    No *novo = malloc(sizeof(No));
    if(novo == NULL){
        return 0;
    }
    novo->dado = valor;
    novo->proximo = p->topo;
    p->topo = novo;
    return 1;
}

int pop(Pilha *p, int *valor){
    if(isEmpty(p) == 1){
        return 0;
    }
    No *aux = p->topo;
    p->topo = p->topo->proximo;
    *valor = aux->dado;
    free(aux);
    return 1;
}

int topo(Pilha *p, int *valor){
    if(isEmpty(p) == 1){
        return 0;
    }
    *valor = p->topo->dado;
    return 1;
}

void destruir(Pilha *p){
    int lixo;
    while(pop(p,&lixo));
}