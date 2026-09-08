#include <stdio.h>
#include <stdlib.h>

struct xxx {
    int w;
    struct xxx *b;
}*pt3,*pt2,*pt1; //declara variaveis globais do tipo ponteiro struct xxx com valor NULL (predefinido pelo compilador)

int main(){
    struct xxx x1 = {10,NULL}, x2 = {15, NULL}, x3 = {20,NULL};
    // estado A1
    pt1 = &x1;
    pt1->b = &x2;
    pt3 = &x2;
    pt2 = &x3;
    // estado A2
    pt1->b = pt2;
    pt2->b = pt3;
    pt3->b = NULL;
}
