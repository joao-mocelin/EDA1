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

int valida_expressao(char *str){
    pilhaPE elements;
    pilhaPE *p = &elements;
    iniciar(p);
    int lenght = strlen(str);
    if(lenght == 0){
        renicia(p);
        return 1;
    }
    for(int i = 0; i < lenght; i++){
        if(!(str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']' || str[i] == '{' || str[i] == '}')){
            continue;
        }
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            push(p, str[i]);
        }
        else{ // ']' or '}' or ')'
            if(isEmpty(p)){
                renicia(p);
                return 0;
            }
            if(abs(str[i] - pop(p)) > 2){
                renicia(p);
                return 0;
            }
        }
    }
    if(isEmpty(p)){
        renicia(p);
        return 1;
    }
    renicia(p);
    return 0;    
}

int main(){
    char str[MAX];
    printf("\nInsira a expressao:\n-> ");
    scanf(" %99[^\n]", str);
    if(valida_expressao(str)){
        printf("\nA expressao %s eh valida.",str);
    }
    else{
        printf("\nA expressao %s eh invalida.",str);
    }
    return 0;
}