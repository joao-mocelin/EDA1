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

int isEmpty_FDE_r(FDE_r *f){
    if(f == NULL){
        return SUCESSO;
    }
    if(f->frente == NULL){
        return SUCESSO;
    }
    return FRACASSO;
}

int tamanho_FDE_r(FDE_r *f){
    if(f == NULL){
        return 0;
    }
    return f->tamanho;
}

int buscaNaFrente_FDE_r(FDE_r *f, Info *dados){
    if(isEmpty_FDE_r(f)){
        return FRACASSO;
    }
    if(dados == NULL){
        return FRACASSO;
    }
    *dados = f->frente->registro;
    return SUCESSO;
}

int buscaNaCauda_FDE_r(FDE_r *f, Info *dados){
    if(isEmpty_FDE_r(f)){
        return FRACASSO;
    }
    if(dados == NULL){
        return FRACASSO;
    }
    *dados = f->cauda->registro;
    return SUCESSO;
}

int reinicia_FDE_r(FDE_r *f){
    if(isEmpty_FDE_r(f)){
        f->numIter = 0;
        return SUCESSO;
    }
    Nodo *aux = f->frente;
    while(aux != NULL){
        aux = aux->next;
        free(f->frente);
        f->frente = aux;
    }
    f->frente = f->cauda = f->ref = NULL;
    f->tamanho = 0;
    f->numIter = 0;
    return SUCESSO;
}

FDE_r *destruir_FDE_r(FDE_r *f){
    reinicia_FDE_r(f);
    free(f);
    return NULL;
}

int remove_FDE_r(FDE_r *f, Info *removido){
    if(isEmpty_FDE_r(f)){
        return FRACASSO;
    }
    if (removido != NULL){
		*removido = f->frente->registro;
	}
    Nodo *aux = f->frente;
    f->frente = f->frente->next;
    if(f->frente == NULL){
        f->cauda = f->ref = NULL;
    }
    else{
        if(f->ref == aux){
            f->ref = f->frente;
        }
        f->frente->prev = NULL;
    }
    free(aux);
    f->tamanho -= 1;
    return SUCESSO;
}

int insere_FDE_r(FDE_r *f, Info inserir){
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
    if(isEmpty_FDE_r(f)){
        f->frente = f->cauda = tmp;
        f->tamanho++;
        f->ref = tmp;
        return SUCESSO;
    }
    Nodo *aux = f->ref;
    if(aux->registro.chave >= tmp->registro.chave){
        while(aux != NULL && aux->registro.chave >= tmp->registro.chave){
            aux = aux->next;
            f->numIter++;
        }
        if(aux == NULL){
            aux = f->cauda;
            f->cauda = tmp;
            tmp->prev = aux;
            aux->next = tmp;
            f->tamanho++;
            f->ref = tmp;
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
            f->tamanho++;
            f->ref = tmp;
            return SUCESSO;
        }
    }
    else{
        while(aux != NULL && aux->registro.chave < tmp->registro.chave){
            aux = aux->prev;
            f->numIter++;
        }
        if(aux == NULL){
            aux = f->frente;
            f->frente = tmp;
            tmp->next = aux;
            aux->prev = tmp;
            f->tamanho++;
            f->ref = tmp;
            return SUCESSO;
        }
        else{
            tmp->next = aux->next;
            tmp->prev = aux;
            aux->next->prev = tmp;
            aux->next = tmp;
            f->tamanho++;
            f->ref = tmp;
            return SUCESSO;
        }
    }
}

void imprime_FDE_r(FDE_r *f){
    if(isEmpty_FDE_r(f)){
        printf("\n[Fila Vazia]\n");
        return;
    }
    Nodo *aux = f->frente;
    printf("  FRENTE\n");
    int pos = 1;
    while(aux != NULL){
        printf("  %3d) chave %6d | %-8s | %s%s\n", pos, aux->registro.chave,
               aux->registro.nome, aux->registro.curso,
               (aux == f->ref) ? "   <-- ref" : "");
        aux = aux->next;
        pos++;
    }
    printf("  CAUDA   (tamanho %d)\n", f->tamanho);
}
