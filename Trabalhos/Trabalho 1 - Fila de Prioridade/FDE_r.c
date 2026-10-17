#include "arq.h"

FDE_r *cria_FDE_r(void){
	FDE_r *tmp = malloc(sizeof(FDE_r)); // falta casting caso vá compilar em c++
	if(tmp == NULL){
		printf("\nErro ao alocar memoria.");
		return NULL;
	}
	tmp->cauda = tmp->frente = tmp->ref = NULL;
	tmp->tamanho = tmp->numIter = 0;
	return tmp;
}