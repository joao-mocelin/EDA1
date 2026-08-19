#include <stdio.h>
#include <stdlib.h>

#define SELECT 4 //QUAL BLOCO DE CODIGO COMPILAR

#if SELECT == 1

struct nodo{
    int x;
    struct nodo *link;
};

int contaNodo(struct nodo *p){
    if(p == NULL){
        return 0;
    }
    struct nodo *aux = p;
    int cont = 0;
    while(aux != NULL){
        cont++;
        aux = aux->link;
    }
    return cont;
}

int main(){
    struct nodo a = {100,NULL};
    struct nodo b = {200, NULL};
    a.link = &b;
    printf("\n Quant. de nos = %d",contaNodo(&a));
    return 0;
}
#endif

#if SELECT == 2

struct nodo{
    int x;
    struct nodo *link;
};

int contaNodo(struct nodo *p){
    if(p == NULL || p->link == NULL){
        return 0;
    }
    int cont = 1;
    struct nodo *aux = p;
    while(aux->link != p){
        cont++;
        aux = aux->link;
    }
    return cont;
}

int main(){
    struct nodo a = {100,NULL};
    struct nodo b = {200, &a};
    a.link = &b;
    int cont = contaNodo(&a);
    printf("\n Quant. de nos = %d", cont);
    return 0;
}

#endif

#if SELECT == 3

struct nodo{
    int x;
    struct nodo *link;
};

int contaNodo(struct nodo *p){
    if(p == NULL || p->link == NULL){
        return 0;
    }
    struct nodo *aux = p;
    int cont = 1;
    while (aux->link != aux)
    {
        cont++;
        aux = aux->link;
    }
    return cont;
}

int main(){
    struct nodo a = {100,NULL};
    struct nodo b = {200, &b};
    a.link = &b;
    int cont = contaNodo(&a);
    printf("\n Quant. de nos = %d", cont);
    return 0;
}

#endif

#if SELECT == 4

struct nodo{
    int dado;
    struct nodo *esq, *dir;
};

struct descritor{
    int posicao;
    struct nodo *primeiro, *ultimo, *link;
};

int contaNodo(struct descritor *p){
    if(p == NULL || p->posicao == -1 || (p->primeiro == NULL && p->link == NULL && p->ultimo == NULL)){
        return 0;
    }
    if(p->primeiro == p->ultimo){
        return 1;
    }
    int cont = p->posicao;
    struct nodo *aux = p->link;
    while(aux->dir != NULL){
        cont++;
        aux = aux->dir;
    }
    return cont;
}

int main(){
    // -------------------------------------------------------------
    // TESTE 1: Lista Vazia (Cenário C1 da imagem)
    // -------------------------------------------------------------
    struct descritor d1;
    d1.posicao = -1; //
    d1.primeiro = NULL;
    d1.ultimo = NULL;
    d1.link = NULL;

    printf("=== TESTE 1 (Lista Vazia) ===\n");
    printf("Quantidade de nos: %d (Esperado: 0)\n\n", contaNodo(&d1));

    // -------------------------------------------------------------
    // TESTE 2: Lista com 1 Nó (Cenário C2 da imagem)
    // -------------------------------------------------------------
    struct descritor d2;
    
    // Aloca a memória para o nó 'X'
    struct nodo *noX = (struct nodo *) malloc(sizeof(struct nodo));
    noX->dado = 10;
    noX->esq = NULL;
    noX->dir = NULL;

    // Configura o descritor apontando para o nó
    d2.posicao = 1;
    d2.primeiro = noX;
    d2.ultimo = noX;
    d2.link = noX;

    printf("=== TESTE 2 (Lista com 1 No) ===\n");
    printf("Quantidade de nos: %d (Esperado: 1)\n\n", contaNodo(&d2));

    // -------------------------------------------------------------
    // TESTE 3: Lista com 3 Nós (Para testar se o loop realmente funciona)
    // -------------------------------------------------------------
    struct descritor d3;
    
    struct nodo *no1 = (struct nodo *) malloc(sizeof(struct nodo));
    struct nodo *no2 = (struct nodo *) malloc(sizeof(struct nodo));
    struct nodo *no3 = (struct nodo *) malloc(sizeof(struct nodo));

    // Encadeamento do no1
    no1->esq = NULL;
    no1->dir = no2;

    // Encadeamento do no2
    no2->esq = no1;
    no2->dir = no3;

    // Encadeamento do no3
    no3->esq = no2;
    no3->dir = NULL;

    // Configuração do Descritor para 3 nós
    d3.posicao = 2;
    d3.primeiro = no1;
    d3.ultimo = no3;
    d3.link = no2;

    printf("=== TESTE 3 (Lista com 3 Nos) ===\n");
    printf("Quantidade de nos: %d (Esperado: 3)\n\n", contaNodo(&d3));

    // Liberação da memória alocada
    free(noX);
    free(no1);
    free(no2);
    free(no3);

    return 0;
}
#endif