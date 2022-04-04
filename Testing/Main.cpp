#include <stdio.h>

double y = 0;

void add(){y = y+2.;}

int main(void){
    printf("Value of y before: %lf\n", y);
    add();
    printf("Value of y after: %lf\n", y);
    return 0;}
