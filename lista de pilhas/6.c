#include "pe.h"

int numeroDeEmpilhados(Pilha *p){
    return p->topo + 1;
}
//usaremos um método para acessar a pilha para garantir o encapsulamento e não usarmos diretamente p->topo