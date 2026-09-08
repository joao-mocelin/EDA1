#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tamInfo;
    struct nodados *pt;
}NoDados;

int main(){
    NoDados p = {10,NULL}, q = {15,NULL};
    //A -> B
    p.pt = &q;
    //A -> C
    q.pt = &q;
    return 0;
}