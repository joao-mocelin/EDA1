#include <stdio.h>

struct teste{
    int x;
    struct teste *esq;
    struct teste *dir;
}*p;

int main(){
    struct teste a = {1,NULL,NULL}, b = {2,NULL,NULL}, c = {3,NULL,NULL};
    // estado 1
    p = &c;
    p->esq = &a;
    a.dir = &b;
    // estado 2
    b.esq = &a;
    b.dir = p;
    p->esq = &b;
    a.dir = &b;
    return 0;
}