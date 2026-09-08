#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int x;
    struct nodo *link;
};

int contaNodo(struct nodo *p);