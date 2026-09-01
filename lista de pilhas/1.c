/*
Construa uma operação int buscaNaBase(Pilha *p, info *pReg) que permite acesso a informação na base da pilha
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float x;
    float y;
}info;

typedef struct No{
    info dados;
    struct No *prox;
}No;

typedef struct{
    No *topo;
}Pilha;

void inicializar(Pilha *p){
    p->topo = NULL;
}

int push(Pilha *p, info dado){
    No *novo = malloc(sizeof(No));
    if(novo == NULL){
        return 0; // falha ao alocar memoria
    }
    novo->dados = dado;
    novo->prox = p->topo;
    p->topo = novo;
    return 1;
}

void destruir(Pilha *p){
    No *aux;
    while(p->topo != NULL){
        aux = p->topo;
        p->topo = aux->prox;
        free(aux);
    }
}

int buscaNaBase(Pilha *p, info *pReg){
    if(p->topo == NULL){
        return 0;
    }
    No *aux = p->topo;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    *pReg = aux->dados;
    return 1;
}

int main(void){
    Pilha p;
    info reg, aux;

    inicializar(&p);

    /* Teste 1: pilha vazia deve retornar 0 */
    if(buscaNaBase(&p, &reg))
        printf("Teste 1 FALHOU: base = (%.2f, %.2f)\n", reg.x, reg.y);
    else
        printf("Teste 1 OK: pilha vazia, retorno 0\n");

    /* Teste 2: com um unico elemento, ele e a propria base */
    aux.x = 1.0; aux.y = 1.5;
    push(&p, aux);

    if(buscaNaBase(&p, &reg))
        printf("Teste 2: base = (%.2f, %.2f)  [esperado: (1.00, 1.50)]\n", reg.x, reg.y);
    else
        printf("Teste 2 FALHOU: retornou 0\n");

    /* Teste 3: com varios elementos, a base continua sendo o primeiro inserido */
    aux.x = 2.0; aux.y = 2.5;
    push(&p, aux);
    aux.x = 3.0; aux.y = 3.5;
    push(&p, aux);

    if(buscaNaBase(&p, &reg))
        printf("Teste 3: base = (%.2f, %.2f)  [esperado: (1.00, 1.50)]\n", reg.x, reg.y);
    else
        printf("Teste 3 FALHOU: retornou 0\n");

    /* Teste 4: o topo nao pode ter mudado */
    printf("Teste 4: topo = (%.2f, %.2f)  [esperado: (3.00, 3.50)]\n",
           p.topo->dados.x, p.topo->dados.y);

    destruir(&p);
    return 0;
}