/*
Ponteiro para os dados: Em vez de um array fixo int dados[MAX], utilizamos um
ponteiro int *dados.
Rastreamento de Capacidade: Adicionamos uma variável capacidade na struct para
sabermos qual é o limite atual antes de precisar redimensionar.
O Redimensionamento (realloc): Se o Push detectar que o limite foi atingido, nós usamos
realloc para dobrar o espaço disponível em tempo de execução.
Atenção ao Memory Leak: Sempre que utilizar malloc ou realloc, você é o único
responsável por limpar a memória. Esquecer de usar o free() (como fizemos na função
destruir) é um dos erros mais comuns e perigosos no desenvolvimento em C/C++.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *dados;
    int capacidade;
    int topo;
}Pilha;

Pilha * inicializar(){
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("\nFalha ao alocar memoria!");
        return NULL;
    }
    p->capacidade = 5; //Começamos com uma pilha de tamanho 5
    p->dados = malloc(sizeof(int) * p->capacidade);
    p->topo = -1;
    if(p->dados == NULL){
        printf("\nFalha ao alocar memoria!");
        free(p);
        return NULL;
    }
    printf("\nPilha alocada com tamanho %d",p->capacidade);
    return p;
}

int isFull(Pilha *p){
    return p->topo == p->capacidade - 1;
}

int isEmpty(Pilha *p){
    return p->topo < 0;
}

void push(Pilha *p, int valor){
    if(isFull(p)){
        p->capacidade *= 2; //dobra a capacidade
        p->dados = realloc(p->dados,sizeof(int) * p->capacidade);
        if(p->dados == NULL){
            printf("\nFalha ao alocar memoria!");
            return;
        }
        printf("\nPilha alocada com tamanho %d",p->capacidade);
    }
    p->topo++;
    p->dados[p->topo] = valor;
}

int pop(Pilha *p){
    if(isEmpty(p)){
        printf("\nPilha vazia.");
        return -1;
    }
    int valor = p->dados[p->topo];
    p->dados[p->topo] = 0;
    p->topo--;
    return valor;
}

Pilha *destruir(Pilha *p){
    if(p == NULL){
        return NULL;
    }
    free(p->dados);
    free(p);
    return NULL;
}

int main(){
printf("--- INICIANDO TESTES DA PILHA ---\n");

    // 1. Cria a pilha de forma limpa e transparente
    Pilha *minhaPilha = inicializar();
    if (minhaPilha == NULL) return 1;

    // 2. Testando o Push (Forçando o limite para testar o realloc)
    printf("\n--- TESTE 1: EMPILHANDO ELEMENTOS ---");
    // Vamos inserir 7 elementos para estourar o limite inicial de 5
    for(int i = 1; i <= 7; i++) {
        push(minhaPilha, i * 10); // Inserindo 10, 20, 30, 40, 50, 60, 70
    }

    // 3. Testando o Pop (Verificando a regra LIFO)
    printf("\n\n--- TESTE 2: DESEMPILHANDO ELEMENTOS ---");
    // Deve sair na ordem reversa: 70, 60, 50...
    for(int i = 0; i < 3; i++) {
        int removido = pop(minhaPilha);
        printf("\nDesempilhado: %d", removido);
    }

    // 4. Testando a destruição da pilha
    printf("\n\n--- TESTE 3: LIMPANDO A MEMORIA ---");
    minhaPilha = destruir(minhaPilha);
    
    if (minhaPilha == NULL) {
        printf("\n[Status] Memoria liberada e ponteiro definido como NULL com sucesso!\n");
    }

    return 0;
}