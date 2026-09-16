#include <stdio.h>
#include <stdlib.h>

typedef struct FEC{
    int front;
    int rear;
    int tam;
    int *vet;
}FEC;

void iniciar_FEC(FEC *f){
    int *tmp = (int*)malloc(sizeof(int) * 10);
    if(tmp == NULL){
        printf("\nERRO: Falha ao alocar memoria.");
        return;
    }
    f->vet = tmp;
    f->tam = 10;
    f->front = 0;
    f->rear = -1;
}

int isEmpty_FEC(FEC *f){
    if(f->rear < f->front){
        return 1;
    }
    return 0;
}

int isFull_FEC(FEC *f){
    if(f->rear == f->tam - 1){
        return 1;
    }
    return 0;
}

int contaElementos_FEC(FEC *f){
    if(isEmpty_FEC(f)){
        return 0;
    }
    return f->rear - f->front + 1;
}

int inserir_FEC(FEC *f, int ele){
    if(isFull_FEC(f)){
        return 0;
    }
    f->vet[++f->rear] = ele;
    return 1;
}

int remover_FEC(FEC *f, int *removido){
    if(isEmpty_FEC(f)){
        return 0;
    }
    *removido = f->front;
    f->front++;
}

int duplicar_FEC(FEC *f){
    int *tmp = (int*)realloc(f->vet, sizeof(int) * (f->tam * 2));
    if(tmp == NULL){
        printf("\nERRO: Falha ao alocar memoria.");
        return 0;
    }
    f->vet = tmp;
    f->tam *= 2;
    return 1;
}