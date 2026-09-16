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

void inverte_str(char *str){
    int lenght = strlen(str), i = 0, j = 0;
    pilhaPE stack;
    pilhaPE *pilha = &stack;
    iniciar(pilha);
    if(lenght == 0){
        return;
    }
    for (i = 0; i <= lenght; i++)
    {
        if(str[i] == ' ' || str[i] == '\0'){
            while(j < i){
                str[j] = pop(pilha);
                j++;
            }
            j++;
            continue;
        }
        push(pilha, str[i]);
    }
    renicia(pilha);
}

int main(){
    char str[MAX];
    printf("\nInsira a frase a ser invertida:\n-> ");
    scanf(" %99[^\n]", str);
    inverte_str(str);
    printf("\n %s",str);
    return 0;
}