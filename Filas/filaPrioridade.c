#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int prioridade;
    int id_pessoa;
    struct Nodo *next;
}Nodo;

typedef struct{
    Nodo *Front;
}FilaPrioridade;

int isEmpty(FilaPrioridade *f){
    if(f->Front == NULL){
        return 1;
    }
    return 0;
}

int enqueue_prioridade(FilaPrioridade *f, int prioridade, int id_pessoa){
    Nodo *temp = malloc(sizeof(Nodo));
    if(temp == NULL){
        printf("\nErro de Memoria.");
        return 0;
    }
    temp->id_pessoa = id_pessoa;
    temp->prioridade = prioridade;
    temp->next = NULL;

    if(f->Front == NULL){
        f->Front = temp;
        return 1;
    }

    if(f->Front->prioridade < temp->prioridade){
        temp->next = f->Front;
        f->Front = temp;
        return 1;
    }

    Nodo *atual = f->Front;
    Nodo *anterior = NULL;
    while(atual != NULL && atual->prioridade >= temp->prioridade)
    {
        anterior = atual;
        atual = atual->next;
    }
    anterior->next = temp;
    temp->next = atual;
    return 1;
}

int dequeue(FilaPrioridade *f, int *id_retorno){
    if(isEmpty(f)){
        printf("\nFila Vazia.");
        return 0;
    }
    *id_retorno = f->Front->id_pessoa;
    Nodo *aux = f->Front;
    f->Front = f->Front->next;
    free(aux);
    return 1;
}