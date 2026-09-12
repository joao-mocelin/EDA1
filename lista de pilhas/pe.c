#include "pe.h"

int inicializar(Pilha *p){ //return 1 if not possible to alocate memory
    p->vet = malloc(sizeof(int) * 5);
    if(p->vet == NULL){
        return 1;
    }
    p->tamanho = 5;
    p->topo = -1; // topo -1 significa vazia
    return 0;
}

int isEmpty(Pilha *p){ //return 1 if empty
    if(p->vet == NULL || p->topo == -1){
        return 1;
    }
    return 0;
}

int isFull(Pilha *p){ //return 1 if full
    if(p->topo == p->tamanho - 1){
        return 1;
    }
    return 0;
}

int alocar_espaco(Pilha *p){ //return 1 == vet doubles it's size; return 0 == can't realloc memory block
    int *aux = realloc(p->vet, sizeof(int) * p->tamanho * 2);
    if(aux == NULL){
        printf("\nErro ao alocar memoria.");
        return 0;
    }
    p->vet = aux;
    p->tamanho *= 2;
    return 1;
}

int push(Pilha *p, int valor){ // return -1 == couldn't initialize stack; return 0 == couldn't expand stack;
    // return 1 == sucessfull operation
    if(p->vet == NULL){
        if(inicializar(p) == 1){
            return -1;
        }
    }
    if(isFull(p) == 1){
        if(alocar_espaco(p) == 0){
            return 0;
        }
    }
    p->vet[p->topo + 1] = valor;
    p->topo++;
    return 1;
}

int pop(Pilha *p, int *popped){ //return 0 == empty or not initialized stack
    if(p->vet == NULL || p->topo == -1){
        return 0;
    }
    *popped = p->vet[p->topo];
    p->topo--;
    return 1;
}

int peek(Pilha *p){
    if(p->vet == NULL || p->topo == -1){
        return 0;
    }
    return p->vet[p->topo];
}

void imprime_pilha(Pilha *p){
    if(p->vet == NULL || p->topo == -1){
        printf("\nPilha vazia");
        return;
    }
    for(int i = p->topo; i >= 0; i--){
        printf("\n| %d | -> %d",i , p->vet[i]);
    }
    return;
}