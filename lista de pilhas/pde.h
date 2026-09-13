#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int x;
    struct no *ant;
    struct no *post;
}Nodo;

typedef struct{
    Nodo *topo;
    Nodo *base;
}Pilha;

void imprime_pilha(Pilha *p);
void inicializar(Pilha *p);
int isEmpty(Pilha *p);
int push(Pilha *p, int valor);
int pop(Pilha *p, int *popped);
int peek(Pilha *p);
void destruir(Pilha *p);