#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dado;
    char nome[50];
}data;

typedef struct nodo{
    data dt;
    struct nodo *link;
}Nodo;

typedef struct{
    int tamanho;
    Nodo *inicio;
}Descritor;

int reinicia(Descritor *p){
    if(p->inicio == NULL){
        p->tamanho = 0;
        return 0;
    }
    Nodo *aux = p->inicio;
    while(aux != NULL){
        p->inicio = aux->link;
        free(aux);
        aux = p->inicio;
    }
    p->tamanho = 0;
    return 1;
}

int insere(Descritor *p, Nodo *novo, int pos){
    if(p == NULL || pos > p->tamanho){
        return 0;
    }
    Nodo *aux = p->inicio;
    if(pos == 1){
        novo->link = p->inicio;
        p->inicio = novo;
        p->tamanho++;
        return 1;
    }
    for(int i = 1; i < pos - 1; i++){
        aux = aux->link;
    }
    novo->link = aux->link;
    aux->link = novo;
    p->tamanho++;
    return 1;
}
Nodo* criaNodo(int valor, const char* nome) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    novo->dt.dado = valor;
    strcpy(novo->dt.nome, nome);
    novo->link = NULL;
    return novo;
}

// Imprime o estado atual da lista
void imprimeLista(Descritor *p) {
    Nodo *aux = p->inicio;
    printf("Tamanho: %d | Elementos: ", p->tamanho);
    if (aux == NULL) printf("Lista Vazia");
    while(aux != NULL) {
        printf("[%d: %s] -> ", aux->dt.dado, aux->dt.nome);
        aux = aux->link;
    }
    printf("NULL\n\n");
}

// --- FUNÇÃO PRINCIPAL ---
int main() {
    Descritor lista;
    lista.inicio = NULL;
    lista.tamanho = 0;

    printf("--- PREPARANDO A LISTA INICIAL ---\n");
    // Adicionando manualmente para contornar a regra 'pos > p->tamanho'
    Nodo *n1 = criaNodo(10, "Dez");
    Nodo *n2 = criaNodo(20, "Vinte");
    n1->link = n2;
    lista.inicio = n1;
    lista.tamanho = 2;
    
    imprimeLista(&lista);


    printf("--- TESTANDO INSERCAO NO MEIO (pos = 2) ---\n");
    Nodo *nMeio = criaNodo(15, "Quinze");
    if (insere(&lista, nMeio, 2)) {
        printf("Sucesso ao inserir na posicao 2!\n");
    }
    imprimeLista(&lista);


    printf("--- TESTANDO INSERCAO NO INICIO (pos = 1) ---\n");
    Nodo *nInicio = criaNodo(5, "Cinco");
    if (insere(&lista, nInicio, 1)) {
        printf("Sucesso ao inserir na posicao 1!\n");
    }
    imprimeLista(&lista);


    printf("--- TESTANDO REINICIA ---\n");
    reinicia(&lista);
    printf("Lista reiniciada!\n");
    imprimeLista(&lista);

    return 0;
}