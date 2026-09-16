#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodoPSE{
    char site[20];
    struct NodoPSE *link;
}NodoPSE;

typedef struct PilhaPSE{
    NodoPSE *topo;
}PilhaPSE;

int isEmpty(PilhaPSE *p){
    if(p == NULL || p->topo == NULL){
        return 1;
    }
    return 0;
}

void inicializar(PilhaPSE *p){
    p->topo = NULL;
}

void destruir(PilhaPSE *p){
    if(isEmpty(p)){
        return;
    }
    NodoPSE *aux = p->topo;
    while (aux != NULL)
    {
        p->topo = aux->link;
        free(aux);
        aux = p->topo;
    }
}

int push(PilhaPSE *p, char *ele){
    NodoPSE *aux = malloc(sizeof(NodoPSE));
    if(aux == NULL){
        return 0;
    }
    aux->link = p->topo;
    strcpy(aux->site, ele);
    p->topo = aux;
    return 1;
}

int pop(PilhaPSE *p, char *popped){
    if(isEmpty(p)){
        return 0;
    }
    NodoPSE *aux = p->topo;
    p->topo = aux->link;
    strcpy(popped, aux->site);
    return 1;
}

char *peek(PilhaPSE *p){
    if(isEmpty(p)){
        return '\0';
    }
    return p->topo->site;
}

void reiniciar(PilhaPSE *p){
    destruir(p);
    inicializar(p);
}

int voltar(PilhaPSE *b, PilhaPSE *f){
    if(isEmpty(b)){
        system("cls");
        printf("\nNao eh possivel voltar agora.");
        return 0;
    }
    char site[20];
    pop(b,site);
    push(f,site);
    system("cls");
    return 1;
}

int novo_site(PilhaPSE *b, PilhaPSE *f){
    char site[20];
    printf("\nQual o nome do site que vai acessar?\n-> ");
    scanf(" %99[^\n]",site);
    push(b,site);
    reiniciar(f);
    system("cls");
    return 1;
}

int avancar(PilhaPSE *b, PilhaPSE *f){
    if(isEmpty(f)){
        system("cls");
        printf("\nNao eh possivel avancar agora.");
        return 0;
    }
    char site[20];
    pop(f,site);
    push(b,site);
    system("cls");
    return 1;
}

int main(){
    PilhaPSE tras, frente;
    PilhaPSE *b = &tras, *f = &frente;
    inicializar(b);
    inicializar(f);
    int option = -1;
    while(option != 0){
        printf("\n\n-------Navegador--------\n");
        if(isEmpty(b)){
            printf("-> Pagina Inicial\n\n");
        }
        else{
            printf("-> %s\n\n",b->topo->site);
        }
        printf("-> Novo site (1)\n");
        printf("-> Voltar    (2)\n");
        printf("-> Avancar   (3)\n");
        printf("\nInsira uma opcao ou 0 para sair.\n-> ");
        scanf("%d",&option);
        switch(option)
        {
        case 0:
            destruir(b);
            destruir(f);
            break;
        case 1:
            novo_site(b,f);
            break;
        
        case 2:
            voltar(b,f);
            break;

        case 3:
            avancar(b,f);
            break;

        default:
            printf("\nOpcao invalida.");
            break;
        }
    }
}