#include <stdio.h>
#include <stdlib.h>
#define TAM 100

typedef struct{
    int tamanho;
    int topo1;
    int topo2;
    int *vet;
}pilha;

int instanciar(pilha *p){
    p->vet = malloc(sizeof(int) * TAM);
    if(p->vet == NULL){
        return 0;
    }
    p->tamanho = TAM;
    p->topo1 = -1;
    p->topo2 = TAM;
    return 1;
}

void destruir(pilha *p){
    p->tamanho = 0;
    p->topo1 = 0;
    p->topo2 = 0;
    free(p->vet);
}

int reiniciar(pilha *p){
    destruir(p);
    if(instanciar(p) == 0){
        return 0;
    }
    return 0;
}

int isEmpty(pilha *p){
    if(p->topo1 == -1 && p->topo2 == p->tamanho){
        return 1;
    }
    return 0;
}

int isFull(pilha *p){
    if(p->topo1 + 1 == p->topo2){
        return 1;
    }
    return 0;
}

int push(pilha *p,int valor, int option){
    if(isFull(p)){
        return 0;
    }
    if(option == 1){
        p->vet[p->topo1 + 1] = valor;
        p->topo1++;
        return 1;
    }
    if(option == 2){
        p->vet[p->topo2 - 1] = valor;
        p->topo2--;
        return 1;
    }
    return 0;
}

int pop(pilha *p, int *popped, int option){
    if(isEmpty(p)){
        return 0;
    }
    if(option == 1){
        if(p->topo1 == -1){
            return 0;
        }
        *popped = p->vet[p->topo1];
        p->topo1--;
        return 1;
    }
    if(option == 2){
        if(p->topo2 == p->tamanho){
            return 0;
        }
        *popped = p->vet[p->topo2];
        p->topo2++;
        return 1;
    }
    return 0;
}

int peek(pilha *p,int option){
    if(isEmpty(p)){
        return 0;
    }
    if(option == 1){
        if(p->topo1 == -1){
            return 0;
        }
        return p->vet[p->topo1];
    }
    if(option == 2){
        if(p->topo2 == p->tamanho){
            return 0;
        }
        return p->vet[p->topo2];
    }
    return 0;
}

int contaElementos(pilha *p, int option){
    if(isEmpty(p)){
        return 0;
    }
    if(option == 1){
        return p->topo1 + 1;
    }
    if(option == 2){
        return p->tamanho - p->topo2;
    }
    return 0;
}

int main() {
    pilha p;
    int valor_removido;

    // 1. Inicializa a estrutura
    if (instanciar(&p) == 0) {
        printf("Erro ao alocar memoria para a pilha.\n");
        return 1;
    }
    printf("Pilha instanciada com sucesso. Capacidade total: %d\n\n", p.tamanho);

    // 2. Testando o Push (Inserindo elementos)
    printf("--- Inserindo elementos ---\n");
    push(&p, 10, 1);
    push(&p, 20, 1);
    push(&p, 30, 1);
    printf("Pilha 1 tem %d elementos. Topo atual: %d\n", contaElementos(&p, 1), peek(&p, 1));

    push(&p, 99, 2);
    push(&p, 88, 2);
    printf("Pilha 2 tem %d elementos. Topo atual: %d\n\n", contaElementos(&p, 2), peek(&p, 2));

    // 3. Testando o Pop (Removendo elementos)
    printf("--- Removendo elementos ---\n");
    if (pop(&p, &valor_removido, 1)) {
        printf("Removido da Pilha 1: %d\n", valor_removido);
    }
    
    if (pop(&p, &valor_removido, 2)) {
        printf("Removido da Pilha 2: %d\n", valor_removido);
    }

    printf("\nApos remocoes:\n");
    printf("Pilha 1 tem %d elementos.\n", contaElementos(&p, 1));
    printf("Pilha 2 tem %d elementos.\n\n", contaElementos(&p, 2));

    // 4. Limpando a memória
    destruir(&p);
    printf("Estrutura destruida e memoria liberada.\n");

    return 0;
}