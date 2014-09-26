#include<stdio.h>
/*
 * An error has slipped into this source code
 * Change ONE letter to compile
 */
#define lady(t,h,i,n,k) h##i##n##t
#define sexy lady(g,m,a,i,l)//@@@@
void sexy() {
    printf(":%s\n", (0)?"(":")");
}
