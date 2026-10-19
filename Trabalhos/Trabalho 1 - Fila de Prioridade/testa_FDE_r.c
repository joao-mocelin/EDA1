#include "arq.h"


int main(void){
    FDE_r *Fila_teste = cria_FDE_r();
    if(Fila_teste == NULL){
        printf("\nFalha ao iniciar a Fila\n");
        return -1;
    }

    int option = -1;     
    int chave = -1;      
    int lidos;
    int c;
    int contItens = 0;

    while(option != 0){
        printf("\n========== Teste da FDE com referencial movel ==========\n");
        if(chave == 1){
            printf("Prioridade atual: RANKING\n");
        }
        else if(chave == 2){
            printf("Prioridade atual: MATRICULA\n");
        }
        else{
            printf("Prioridade atual: (escolhida na proxima insercao)\n");
        }
        printf("\n1) Inserir");
        printf("\n2) Remover");
        printf("\n3) Buscar na Frente");
        printf("\n4) Buscar na Cauda");
        printf("\n5) Tamanho da Fila");
        printf("\n6) Testar Fila Vazia");
        printf("\n7) Reiniciar Fila");
        printf("\n8) Imprimir Fila (frente -> cauda)");
        printf("\n0) Destruir Fila e sair.");
        printf("\n\nOpcao: ");

        lidos = scanf("%d", &option);
        while((c = getchar()) != '\n' && c != EOF);   
        if(lidos == EOF){          
            option = 0;
        }
        else if(lidos != 1){       
            printf("\nDigite apenas numeros.\n");
            option = -1;
            continue;
        }

        system("cls");

        switch (option)
        {
        case 1: {
            Info dados;
            printf("\nInserir na Fila\n");

            printf("\nNome: ");
            scanf(" %19[^\n]", dados.nome);
            while((c = getchar()) != '\n' && c != EOF);  //limpa o buffer

            printf("Curso: ");
            scanf(" %19[^\n]", dados.curso);
            while((c = getchar()) != '\n' && c != EOF);

            printf("Matricula: ");
            while(scanf("%d", &dados.matricula) != 1 && !feof(stdin)){
                while((c = getchar()) != '\n' && c != EOF);
                printf("Valor invalido. Matricula: ");
            }
            while((c = getchar()) != '\n' && c != EOF);

            printf("Ranking: ");
            while(scanf("%d", &dados.ranking) != 1 && !feof(stdin)){
                while((c = getchar()) != '\n' && c != EOF);
                printf("Valor invalido. Ranking: ");
            }
            while((c = getchar()) != '\n' && c != EOF);

            if(isEmpty_FDE_r(Fila_teste)){
                chave = -1;
            }
            while(chave != 1 && chave != 2){
                printf("\nOrdenar a prioridade por ranking (1) ou por matricula (2)? ");
                if(scanf("%d", &chave) != 1){
                    chave = -1;
                }
                while((c = getchar()) != '\n' && c != EOF);
                if(chave != 1 && chave != 2){
                    printf("Valor invalido.");
                }
            }

            if(chave == 1){
                dados.chave = dados.ranking;
            }
            else{
                dados.chave = dados.matricula;
            }

            Fila_teste->numIter = 0;   
            if(insere_FDE_r(Fila_teste, dados) == SUCESSO){
                printf("\nInserido com sucesso (chave %d). Iteracoes do laco: %ld\n",
                       dados.chave, Fila_teste->numIter);
            }
            else{
                printf("\nFalha ao inserir.\n");
            }
            break;
        }

        case 2: {
            Info removido;
            if(remove_FDE_r(Fila_teste, &removido) == SUCESSO){
                printf("\nRemovido: %s | %s | matricula %d | ranking %d | chave %d\n",
                       removido.nome, removido.curso, removido.matricula,
                       removido.ranking, removido.chave);
            }
            else{
                printf("\nFila vazia, nada a remover.\n");
            }
            break;
        }

        case 3: {
            Info frente;
            if(buscaNaFrente_FDE_r(Fila_teste, &frente) == SUCESSO){
                printf("\nFrente: %s | %s | matricula %d | ranking %d | chave %d\n",
                       frente.nome, frente.curso, frente.matricula,
                       frente.ranking, frente.chave);
            }
            else{
                printf("\nFila vazia.\n");
            }
            break;
        }

        case 4: {
            Info cauda;
            if(buscaNaCauda_FDE_r(Fila_teste, &cauda) == SUCESSO){
                printf("\nCauda: %s | %s | matricula %d | ranking %d | chave %d\n",
                       cauda.nome, cauda.curso, cauda.matricula,
                       cauda.ranking, cauda.chave);
            }
            else{
                printf("\nFila vazia.\n");
            }
            break;
        }

        case 5:
            printf("\nTamanho da fila: %d\n", tamanho_FDE_r(Fila_teste));
            break;

        case 6:
            if(isEmpty_FDE_r(Fila_teste)){
                printf("\nA fila ESTA vazia.\n");
            }
            else{
                printf("\nA fila NAO esta vazia.\n");
            }
            break;

        case 7:
            if(reinicia_FDE_r(Fila_teste) == SUCESSO){
                chave = -1;   
                printf("\nFila reiniciada. Tamanho: %d\n", tamanho_FDE_r(Fila_teste));
            }
            else{
                printf("\nFalha ao reiniciar.\n");
            }
            break;

        case 8:
            printf("\n");
            imprime_FDE_r(Fila_teste);
            break;

        case 0:
            Fila_teste = destruir_FDE_r(Fila_teste);
            printf("\nFila destruida. Ate mais!\n");
            break;

        default:
            printf("\nOpcao invalida.\n");
            break;
        }
    }

    return 0;
}