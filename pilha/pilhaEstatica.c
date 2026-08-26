/*
    LIFO - Last In -> First Out
    O elemento que entrou por ultimo é sempre o primeiro a sair da pilha.
    A pilha é a estrutura de dados mais simples que iremos analisar
    Uma pilha pode ser operada - sofrer inserções, remoções ou buscas. Sempre pelo TOPO!
    Pilha estática -> usa um vetor estático como pilha e um int topo para guardar o indice do elemento que está no topo.
    Funções principais de uma pilha:
        isFull() -> retorna se a pilha está cheia ou não
        isEmpty() -> retorna se a pilha está vazia ou não
        Push() -> função que empilha um elemento novo na pilha. Para empilhar um elemento, primeiro temos que ver se há espaço.
        Pop() -> desempilha o ultimo elemento colocado na pilha. 
        Peek() -> retorna o valor do topo, sem mecher na pilha
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
    int dados[MAX];
    int topo;
}Pilha;

int isFull(Pilha *p){
    return p->topo == MAX - 1;
}

int isEmpty(Pilha *p){
    return p->topo < 0;
}

void push(Pilha *p, int valor){
    if(isFull(p)){
        printf("\n A pilha está cheia!");
        return;
    }
    p->topo++; //incrementa o topo
    p->dados[p->topo] = valor; // coloca o valor no topo da pilha
    printf("\nInserido %d",valor);
    return;
}

void pop(Pilha *p){
    if(isEmpty(p)){
        printf("\nA pilha esta vazia!");
        return;
    }
    printf("\nRemovido %d",p->dados[p->topo]);
    p->topo--;
    return;
}

int peek(Pilha *p){
    if(isEmpty(p)){
        printf("\nPilha vazia.");
        return 0;
    }
    return p->dados[p->topo];
}

int main(){
    Pilha p;
    p.topo = -1; //inicializa em -1 para dizer que está vazia
    for(int i = 0; i < MAX; i++){
        push(&p,i+99);
    }
    printf("\n topo = %d",peek(&p));
    pop(&p);
    printf("\n topo = %d",peek(&p));
    return 0;
}