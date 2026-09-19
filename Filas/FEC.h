#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct{
    int tamFila;
    int Frente;
    int Cauda;
    int TamVet;
    int *vet;
}FEC;

int iniciar(FEC *f);
int vazia(FEC *f);
int cheia(FEC *f);
int destruir(FEC *f);
void reiniciar(FEC *f);
int inserir(FEC *f, int dado);
int remover(FEC *f, int *dado);