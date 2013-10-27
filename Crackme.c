#include<stdlib.h>#include<stdio.h>
#define NOTICE "Find the key between 1-10000\nYou got only ONE chance :)\n"
int main(){printf(NOTICE);
int pass,salt=time(NULL)-1382912020;salt=salt*salt%10000;scanf("%d",&pass);
(pass==salt)?printf("GOOD JOB :) !!!\n"):printf("BAD BOY :( !!!\n");return 0;}
