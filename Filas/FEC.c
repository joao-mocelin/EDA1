#include "FEC.h"

int iniciar(FEC *f){
    int *tmp = (int*)malloc(sizeof(int) * TAM);
    if(tmp == NULL){
        return 0;
    }
    f->vet = tmp;
    f->Cauda = -1;
    f->Frente = 0;
    f->tamFila = 0;
    f->TamVet = TAM;
    return 1;
}

int vazia(FEC *f){
    if(f->tamFila == 0){
        return 1;
    }
    return 0;
}

int cheia(FEC *f){
    if(f->tamFila == f->TamVet){
        return 1;
    }
    return 0;
}

int destruir(FEC *f){
    if(f->vet != NULL){
        free(f->vet);
    }
    f->Cauda = -1;
    f->Frente = 0;
    f->tamFila = 0;
    f->TamVet = 0;
    return 1;
}

void reiniciar(FEC *f){
    destruir(f);
    iniciar(f);
}

int inserir(FEC *f, int dado){
    if(cheia(f)){
        return 0;
    }
    f->Cauda = (f->Cauda + 1) % f->TamVet;
    f->vet[f->Cauda] = dado;
    f->tamFila++;
    return 1;
}

int remover(FEC *f, int *dado){
    if(vazia(f)){
        return 0;
    }
    *dado = f->vet[f->Frente];
    f->Frente = (f->Frente + 1) % f->TamVet;
    f->tamFila--;
    return 1;
}