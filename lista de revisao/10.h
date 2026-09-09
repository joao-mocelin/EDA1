#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int x;
    struct nodo *link;
}Nodo;

typedef struct{
    int tamvet;
    Nodo *vet;
}descritor;

int contaNodo(descritor *p);