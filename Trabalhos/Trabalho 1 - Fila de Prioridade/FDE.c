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

int isEmpty_FDE(FDE *f){
	if(f == NULL){
		return SUCESSO;
	}
	if(f->frente == NULL){
		return SUCESSO;
	}
	return FRACASSO;
}

int tamanho_FDE(FDE *f){
    if(f == NULL){
        return 0;
    }
    return f->tamanho;
}

int buscaNaFrente_FDE(FDE *f, Info *dados){
    if(isEmpty_FDE(f)){
        return FRACASSO;
    }
    if(dados == NULL){
        return FRACASSO;
    }
    *dados = f->frente->registro;
    return SUCESSO;
}

int buscaNaCauda_FDE(FDE *f, Info *dados){
    if(isEmpty_FDE(f)){
        return FRACASSO;
    }
    if(dados == NULL){
        return FRACASSO;
    }
    *dados = f->cauda->registro;
    return SUCESSO;
}

int reinicia_FDE(FDE *f){
    if(isEmpty_FDE(f)){
        f->numIter = 0;
        return SUCESSO;
    }
    Nodo *aux = f->frente;
    while(aux != NULL){
        aux = aux->next;
        free(f->frente);
        f->frente = aux;
    }
    f->cauda = f->frente = NULL;
    f->tamanho = 0;
    f->numIter = 0;
    return SUCESSO;
}

FDE *destruir_FDE(FDE *f){
    reinicia_FDE(f);
    free(f);
    return NULL;
}

int remove_FDE(FDE *f, Info *removido){
	if(isEmpty_FDE(f)){
		return FRACASSO;
	}
	if (removido != NULL){
		*removido = f->frente->registro;
	}
    Nodo *aux = f->frente;
	f->frente = f->frente->next;
	if(f->frente == NULL){
		f->cauda = NULL;
	}
	else{
		f->frente->prev = NULL;
	}
	free(aux);
	f->tamanho -= 1;
	return SUCESSO;
}

int insere_FDE(FDE *f, Info inserir){
    if(f == NULL){
        return FRACASSO;
    }
    Nodo *tmp = malloc(sizeof(Nodo));
    if(tmp == NULL){
        printf("\nErro ao alocar memoria.");
        return FRACASSO;
    }
    tmp->registro = inserir;
    tmp->next = tmp->prev = NULL;
    f->tamanho++;
    if(isEmpty_FDE(f)){
        f->frente = f->cauda = tmp;
        return SUCESSO;
    }
    if(tmp->registro.chave < f->cauda->registro.chave){
        Nodo *aux = f->cauda;
        f->cauda = tmp;
        tmp->prev = aux;
        aux->next = tmp;
        return SUCESSO;
    }
    Nodo *aux = f->frente;
    while(aux != NULL && aux->registro.chave >= tmp->registro.chave){
        aux = aux->next;
        f->numIter++;
    }
    if(aux == NULL){
        aux = f->cauda;
        f->cauda = tmp;
        tmp->prev = aux;
        aux->next = tmp;
        return SUCESSO;
    }
    else{
        tmp->next = aux;
        tmp->prev = aux->prev;
        if(aux->prev == NULL){
            f->frente = tmp;
        }
        else{
            aux->prev->next = tmp;
        }
        aux->prev = tmp;
        return SUCESSO;
    }
}

void imprime_FDE(FDE *f){
    if(isEmpty_FDE(f)){
        printf("\n[Fila Vazia]\n");
        return;
    }
    Nodo *aux = f->frente;
    printf("  FRENTE\n");
    int pos = 1;
    while(aux != NULL){
        printf("  %3d) chave %6d | %-8s | %s\n", pos, aux->registro.chave,
               aux->registro.nome, aux->registro.curso);
        aux = aux->next;
        pos++;
    }
    printf("  CAUDA   (tamanho %d)\n", f->tamanho);
}