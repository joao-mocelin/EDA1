#include "10.h"

int contaNodo(descritor *p){
    int cont = 0;
    if(p == NULL || p->tamvet == 0){
        return cont;
    }
    for(int i = 0; i < p->tamvet; i++){
        Nodo *aux = &p->vet[i];
        if(!(aux == NULL)){
            while(aux != NULL){
                cont++;
                aux = aux->link;
            }
        }
    }
    return cont;
}

int inicializa(descritor *p){
    printf("\nQual o tamanho da lista?\n");
    scanf("%d",&p->tamvet);
    Nodo *aux = malloc(sizeof(Nodo) * p->tamvet);
    if(aux == NULL){
        return 0;
    }
    p->vet = aux;
    return 1;
}

int main() {
    descritor lista;
    lista.tamvet = 0;
    lista.vet = NULL;

    printf("--- TESTE DA FUNCAO INICIALIZA ---\n");
    if (!inicializa(&lista)) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // IMPORTANTE: Limpando o lixo de memória do malloc
    // Como alocamos Nodos, precisamos garantir que o próximo (link) seja nulo
    for (int i = 0; i < lista.tamvet; i++) {
        lista.vet[i].x = i * 10; 
        lista.vet[i].link = NULL;
    }

    printf("\n--- TESTE 1: CONTAGEM INICIAL ---\n");
    // Se o usuário digitou 3, deve contar 3 (pois o próprio vetor contém 3 nodos base)
    int total = contaNodo(&lista);
    printf("Total de nodos iniciais: %d\n", total);

    printf("\n--- TESTE 2: ADICIONANDO NODOS ENCADEADOS ---\n");
    if (lista.tamvet > 0) {
        printf("Adicionando 2 nodos extras ligados a posicao 0 do vetor...\n");
        
        // Criando nodos soltos
        Nodo *extra1 = (Nodo*)malloc(sizeof(Nodo));
        extra1->x = 100;
        extra1->link = NULL;

        Nodo *extra2 = (Nodo*)malloc(sizeof(Nodo));
        extra2->x = 200;
        extra2->link = NULL;

        // Costurando eles no primeiro elemento do vetor
        lista.vet[0].link = extra1;
        extra1->link = extra2;

        // Nova contagem
        total = contaNodo(&lista);
        // Esperado: tamvet (nodos base) + 2 (nodos extras)
        printf("Novo total de nodos contados: %d\n", total);
    }

    // Liberando a memória no final (boas práticas)
    if (lista.tamvet > 0) {
        // Libera os nodos encadeados na posição 0
        Nodo *atual = lista.vet[0].link;
        while (atual != NULL) {
            Nodo *prox = atual->link;
            free(atual);
            atual = prox;
        }
        // Libera o vetor em si
        free(lista.vet);
    }

    return 0;
}