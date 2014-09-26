#include<stdio.h>
/*
 * An error has slipped into this source code
 * Change ONE letter to compile
 */
#define woman(t,h,i,n,k) h##i##n##t
#define man woman(g,m,a,i,l)//@tfairane
void man() {
    printf(":%s\n", (0)?"(":")");
}
