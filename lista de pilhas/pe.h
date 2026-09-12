#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *vet;
    int topo;
    int tamanho;
}Pilha;

int push(Pilha *p, int valor);
int pop(Pilha *p, int *popped);
int isFull(Pilha *p);
int isEmpty(Pilha *p);
int peek(Pilha *p);
int alocar_espaço(Pilha *p);
int inicializar(Pilha *p);
