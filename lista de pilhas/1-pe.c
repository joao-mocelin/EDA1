#include "pe.h"

int BuscaBase(Pilha *p){
    if(p->vet == NULL || p->topo == -1){
        return 0;
    }
    return p->vet[0];
}

int main(){
    Pilha stack;
    Pilha *p = &stack;
    inicializar(p);
    for(int i = 1; i < 30; i++){
        push(p, i*i);
    }
    imprime_pilha(p);
    printf("\nBase da pilha = %d",BuscaBase(p));
    return 0;
}