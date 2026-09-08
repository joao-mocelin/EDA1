#include <stdio.h>

int main(){
    int *p = NULL, **pp = NULL, x = 321, y = 101;
    p = &x; // p aponta para x
    pp = &p; // pp aponta para p (que aponta para x) 
    *p = -3; // -3 é atribuido ao valor apontado por p (valor de x) == x = -3
    y = **pp; // é atribuido a y o valor apontado pelo ponteiro apontado por pp (y = -3)
}