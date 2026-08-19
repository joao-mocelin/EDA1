#include <stdio.h>
#include <stdlib.h>

struct teste{
    int inteiro;
    float real;
    char nome[30];
    struct teste *self;
};

int main(){
    struct teste x = {115,2.5,"smith",NULL}, *p = NULL;
    p = &x;
    p->self = &x;
    return 1;
}