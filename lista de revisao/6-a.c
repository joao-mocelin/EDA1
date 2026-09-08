#include "nodo.h"

int contaNodo(struct nodo *p){
    if(p == NULL){
        return 0;
    }
    if(p->link == NULL){
        return 1;
    }
    int cont = 2;
    struct nodo *aux = p->link;
    while(aux->link != NULL){
        cont++;
        aux = aux->link;
    }
    return cont;
}

int main(){
    struct nodo a1,a2,a3,a4;
    a1.link = &a2;
    a2.link = &a3;
    a3.link = &a4;
    a4.link = NULL;
    printf("\n %d",contaNodo(&a1));
    return 0;
}