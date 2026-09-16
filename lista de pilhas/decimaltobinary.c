#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct pilhaPE{
    int tamanho;
    int topo;
    char *pilha;
}pilhaPE;

void iniciar(pilhaPE *p){
    p->tamanho = MAX;
    p->topo = -1;
    char *tmp = malloc(sizeof(char) * MAX);
    if(tmp == NULL){
        printf("\n Erro: Falha ao alocar memoria.");
        return;
    }
    p->pilha = tmp;
    return;
}

int isEmpty(pilhaPE *p){
    if(p->topo == -1){
        return 1;
    }
    return 0;
}

int isFull(pilhaPE *p){
    if(p->topo + 1 == p->tamanho){
        return 1;
    }
    return 0;
}

int push(pilhaPE *p, char ele){
    if(!isFull(p)){
        p->pilha[++p->topo] = ele;
        return 1;
    }
    return 0;
}

char pop(pilhaPE *p){
    if(!isEmpty(p)){
        return p->pilha[p->topo--];
    }
    return '\0';
}

void renicia(pilhaPE *p){
    p->tamanho = 0;
    p->topo = -1;
    free(p->pilha);
}

void decimal_to_binary(int decimal){
    if(decimal == 0){
        printf("\n0");
        return;
    }
    pilhaPE pilha;
    pilhaPE *p = &pilha;
    iniciar(p);
    while (decimal > 0)
    {
        push(p,(decimal % 2) + '0');
        decimal = decimal / 2;
    }
    printf("\n");
    while (!isEmpty(p))
    {
        printf("%c",pop(p));
    }
    renicia(p);
}

int main(){
    int decimal;
    printf("\nInsira o decimal para converter em binario:\n-> ");
    scanf("%d",&decimal);
    decimal_to_binary(decimal);
    return 0;
}