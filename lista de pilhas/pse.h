#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int x;
    struct no *prox;
}Nodo;

typedef struct{
    Nodo *topo;
}Pilha;

void inicializar();
void imprime_pilha(Pilha *p);
int isEmpty(Pilha *p);
int push(Pilha *p, int valor);
int pop(Pilha *p);
int peek(Pilha *p);