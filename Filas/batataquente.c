/*
Imagine uma roda de crianças brincando de "Batata Quente". A batata passa de mão em mão N vezes. Quando a contagem termina, quem está com a batata é eliminado. O jogo continua até sobrar apenas uma pessoa (o vencedor).
*/
#include "FSE.h"
#define MAOS 7

void passar_batata(FSE *f){
    int dado; 
    dequeue_fila(f,&dado);
    enqueue_fila(f,dado);
}

void queimar_maos(FSE *f){
    int dado;
    dequeue_fila(f, &dado);
}

int vencedor(FSE *f){
    if(f->Front == f->Rear && f->Front != NULL){
        return 1;
    }
    return 0;
}

int main(){
    FSE Fila;
    FSE *f = &Fila;
    iniciar_fila(f);
    for(int i = 1; i <= 7; i++){
        enqueue_fila(f,i);
    }
    while(!vencedor(f)){
        for(int i = 0; i < MAOS; i++){
            passar_batata(f);
        }
        queimar_maos(f);
    }
    int vencedor;
    dequeue_fila(f,&vencedor);
    printf("\nO vencedor eh o Jogador %d!",vencedor);
    return 0;
}