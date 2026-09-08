#include <stdio.h>

struct teste2{
    int inteiro;
    float real;
    char nome[30];
    struct teste2 *self;
};

int main(){
    struct teste2 x = {115, 2.5, "Smith", NULL}, *p = NULL;
    p = &x; // o ponteiro de struct teste2 aponta para a struct x
    p->self = &x; // o ponteiro *self da struct para qual p aponta recebe o endereço de x
}