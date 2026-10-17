#ifndef ARQ_H
#define ARQ_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FRACASSO 0

typedef struct Info{
	char curso[20];
	char nome[20];
	int matricula;
	int ranking;
	int chave; // Ranking ou Matrícula
}Info;

/* frente                    cauda
        [A] ⇄ [B] ⇄ [C] ⇄ [D]
 prev=NULL                   next=NULL
  next → anda para trás (rumo à cauda)
  prev → anda para frente (rumo à frente)
*/
typedef struct Nodo
{
	Info registro;
	struct Nodo *next;
	struct Nodo *prev;
}Nodo;

typedef struct{
	Nodo *frente;
	Nodo *cauda;
	int tamanho;
	long numIter;
}FDE;

typedef struct{
	Nodo *frente;
	Nodo *cauda;
	int tamanho;
	Nodo *ref;
	long numIter;
}FDE_r;

FDE *cria_FDE(void);
FDE_r *cria_FDE_r(void);



#endif