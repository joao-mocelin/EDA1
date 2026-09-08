#include <stdio.h>

struct yyy {
    int k;
    struct yyy *a;
    struct yyy *b;
}*pt1,*pt2;

int main(){
    struct yyy y1 = {1,NULL,NULL}, y2 = {2,NULL,NULL}, y3 = {3,NULL,NULL};
    // estado B1
    y1.b = &y2;
    pt2 = &y2;
    pt1 = &y3;
    pt2->a = &y1;
    // estado B2
    pt1 = &y3;
    y1.b = &y3;
    pt1->a = &y1;
    pt1->b = pt2;
    pt2->a = pt1;
    return 0;
}