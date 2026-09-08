#include <stdio.h>

struct teste{
    int inteiro;
    float real;
    char nome[30];
    char rua[30];
    int *apont;
};

int main(){
    struct teste *p = NULL , x = {321, 2.39, "Silva", "Timbo", NULL};
    int y = 101;
    p = &x; //p aponta para x
    p->apont = &y; // p.apont aponta para y
}
