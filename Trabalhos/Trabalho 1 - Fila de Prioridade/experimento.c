#include "arq.h"

/*
 * experimento.c - Comparacao de desempenho FDE x FDE_r (itens 3.3 e 4 da tarefa)
 *
 * Para cada tamanho de base N (500, 1000, ..., 9000):
 *   1. sorteia N registros distintos do dataset (Fisher-Yates), em ordem aleatoria;
 *   2. insere a MESMA base, na MESMA ordem, na FDE e na FDE_r;
 *   3. calcula a media de iteracoes de laco por insercao:
 *        sem ref = FDE (sem referencial)   com ref = FDE_r (com referencial movel)
 *        economia = quanto a FDE_r economiza de iteracoes em relacao a FDE, em %
 *   4. repete os passos 2 e 3 com a chave = ranking (item 3) e chave = matricula (item 4).
 *
 * Saida: tabela na tela e o arquivo resultados.csv
 *        (separador ';' e virgula decimal, para abrir direto no Excel em portugues).
 *
 * Compilar: gcc experimento.c FDE.c FDE_r.c -o experimento
 * Executar: com o dataset_v1.csv na mesma pasta do executavel.
 */

#define ARQ_DATASET  "dataset_v1.csv"
#define ARQ_SAIDA    "resultados.csv"
#define MAX_REG      10000
#define N_INICIAL    500
#define N_FINAL      9000
#define N_PASSO      500
#define QTD_TAMANHOS ((N_FINAL - N_INICIAL) / N_PASSO + 1)   /* 18 bases */
#define SEMENTE      2025   /* semente fixa: o experimento e reproduzivel */
#define REPETICOES   1      /* > 1: tira a media de varias amostras por N (curvas mais suaves) */

int main(void){

    Info dataset[MAX_REG];   /* 10.000 registros, ~520 KB na pilha */

    /* ================= 1. Leitura do CSV ================= */
    FILE *arq = fopen(ARQ_DATASET, "r");
    if(arq == NULL){
        printf("\nNao foi possivel abrir %s. Ele precisa estar na mesma pasta do programa.\n",
               ARQ_DATASET);
        return 1;
    }

    char linha[256];
    int total = 0;
    int descartadas = 0;

    if(fgets(linha, sizeof linha, arq) == NULL){   /* descarta o cabecalho */
        printf("\nArquivo vazio.\n");
        fclose(arq);
        return 1;
    }

    /* formato de cada linha: Nome,Matricula,Ranking,Curso */
    while(total < MAX_REG && fgets(linha, sizeof linha, arq) != NULL){
        Info r;
        if(sscanf(linha, "%19[^,],%d,%d,%19[^\r\n]",
                  r.nome, &r.matricula, &r.ranking, r.curso) == 4){
            r.chave = 0;
            dataset[total] = r;
            total++;
        }
        else{
            descartadas++;
        }
    }
    fclose(arq);

    printf("\n%d registros lidos de %s", total, ARQ_DATASET);
    if(descartadas > 0){
        printf(" (%d linhas mal formatadas descartadas)", descartadas);
    }
    printf("\n");

    if(total < N_FINAL){
        printf("Registros insuficientes: o experimento precisa de pelo menos %d.\n", N_FINAL);
        return 1;
    }

    /* ================= 2. Experimento ================= */
    int    tamanhos[QTD_TAMANHOS];
    double semRef_ranking[QTD_TAMANHOS],   comRef_ranking[QTD_TAMANHOS];
    double semRef_matricula[QTD_TAMANHOS], comRef_matricula[QTD_TAMANHOS];
    double economia_ranking[QTD_TAMANHOS], economia_matricula[QTD_TAMANHOS];

    srand(SEMENTE);

    printf("Semente: %d | Repeticoes por tamanho: %d | Ordem de insercao: aleatoria\n\n",
           SEMENTE, REPETICOES);
    printf("Media sem ref = media de iteracoes do laco por insercao na FDE (sem referencial movel)\n");
    printf("Media com ref = media de iteracoes do laco por insercao na FDE_r (com referencial movel)\n");
    printf("Economia      = quanto a FDE_r economiza em relacao a FDE (positivo: FDE_r melhor)\n\n");
    printf("%7s | %-39s| %-39s\n", "", "CHAVE: RANKING", "CHAVE: MATRICULA");
    printf("%7s |%s |%s\n", "Tamanho",
           " Media sem ref Media com ref    Economia",
           " Media sem ref Media com ref    Economia");

    for(int t = 0; t < QTD_TAMANHOS; t++){
        int N = N_INICIAL + t * N_PASSO;
        double somaSem_rank = 0, somaCom_rank = 0, somaSem_mat = 0, somaCom_mat = 0;

        for(int rep = 0; rep < REPETICOES; rep++){

            /* --- 2.1 Sorteio da base: embaralha o dataset inteiro (Fisher-Yates)
                   e usa os N primeiros. Sem repeticao e em ordem aleatoria. --- */
            for(int i = total - 1; i > 0; i--){
                int j = rand() % (i + 1);
                Info aux = dataset[i];
                dataset[i] = dataset[j];
                dataset[j] = aux;
            }

            /* --- 2.2 Mesma base, duas chaves: k = 1 ranking, k = 2 matricula --- */
            for(int k = 1; k <= 2; k++){

                for(int i = 0; i < N; i++){
                    if(k == 1){
                        dataset[i].chave = dataset[i].ranking;
                    }
                    else{
                        dataset[i].chave = dataset[i].matricula;
                    }
                }

                FDE   *fila   = cria_FDE();
                FDE_r *fila_r = cria_FDE_r();
                if(fila == NULL || fila_r == NULL){
                    printf("\nFalha ao criar as filas.\n");
                    return 1;
                }

                /* FDE sem referencial */
                fila->numIter = 0;
                for(int i = 0; i < N; i++){
                    if(insere_FDE(fila, dataset[i]) != SUCESSO){
                        printf("\nFalha ao inserir na FDE (N = %d).\n", N);
                        return 1;
                    }
                }

                /* FDE com referencial movel: mesma base, mesma ordem */
                fila_r->numIter = 0;
                for(int i = 0; i < N; i++){
                    if(insere_FDE_r(fila_r, dataset[i]) != SUCESSO){
                        printf("\nFalha ao inserir na FDE_r (N = %d).\n", N);
                        return 1;
                    }
                }

                /* conferencia: as duas filas precisam ter recebido todos os itens */
                if(tamanho_FDE(fila) != N || tamanho_FDE_r(fila_r) != N){
                    printf("\nTamanho inconsistente apos as insercoes (N = %d).\n", N);
                    return 1;
                }

                /* media de iteracoes do laco por insercao */
                double mediaSemRef = (double) fila->numIter   / N;
                double mediaComRef = (double) fila_r->numIter / N;

                if(k == 1){
                    somaSem_rank += mediaSemRef;
                    somaCom_rank += mediaComRef;
                }
                else{
                    somaSem_mat += mediaSemRef;
                    somaCom_mat += mediaComRef;
                }

                fila   = destruir_FDE(fila);
                fila_r = destruir_FDE_r(fila_r);
            }
        }

        tamanhos[t]         = N;
        semRef_ranking[t]   = somaSem_rank / REPETICOES;
        comRef_ranking[t]   = somaCom_rank / REPETICOES;
        semRef_matricula[t] = somaSem_mat  / REPETICOES;
        comRef_matricula[t] = somaCom_mat  / REPETICOES;

        /* economia em %: 1 - (com ref / sem ref) */
        economia_ranking[t] = semRef_ranking[t] > 0
                            ? (1.0 - comRef_ranking[t] / semRef_ranking[t]) * 100.0 : 0.0;
        economia_matricula[t] = semRef_matricula[t] > 0
                            ? (1.0 - comRef_matricula[t] / semRef_matricula[t]) * 100.0 : 0.0;

        printf("%7d | %13.2f %13.2f %10.1f%% | %13.2f %13.2f %10.1f%%\n",
               N,
               semRef_ranking[t],   comRef_ranking[t],   economia_ranking[t],
               semRef_matricula[t], comRef_matricula[t], economia_matricula[t]);
    }

    /* ================= 3. Gravacao do resultados.csv ================= */
    FILE *saida = fopen(ARQ_SAIDA, "w");
    if(saida == NULL){
        printf("\nNao foi possivel criar %s.\n", ARQ_SAIDA);
        return 1;
    }

    fprintf(saida, "Tamanho da base;"
                   "Ranking - media sem ref (FDE);Ranking - media com ref (FDE_r);Ranking - economia (%%);"
                   "Matricula - media sem ref (FDE);Matricula - media com ref (FDE_r);Matricula - economia (%%)\n");
    for(int t = 0; t < QTD_TAMANHOS; t++){
        double valores[6] = { semRef_ranking[t],   comRef_ranking[t],   economia_ranking[t],
                              semRef_matricula[t], comRef_matricula[t], economia_matricula[t] };
        fprintf(saida, "%d", tamanhos[t]);
        for(int v = 0; v < 6; v++){
            char num[32];
            snprintf(num, sizeof num, "%.4f", valores[v]);
            for(char *p = num; *p != '\0'; p++){   /* ponto -> virgula (Excel em portugues) */
                if(*p == '.'){
                    *p = ',';
                }
            }
            fprintf(saida, ";%s", num);
        }
        fprintf(saida, "\n");
    }
    fclose(saida);

    printf("\nResultados gravados em %s\n", ARQ_SAIDA);
    return 0;
}