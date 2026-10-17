#include "arq.h"

FDE *cria_FDE(void){
	FDE *tmp = malloc(sizeof(FDE)); //falta casting caso vá compilar em c++
	if(tmp == NULL){
		printf("\nErro ao alocar memoria.");
		return NULL;
	}
	tmp->cauda = tmp->frente = NULL;
	tmp->tamanho = tmp->numIter = 0;
	return tmp;
}