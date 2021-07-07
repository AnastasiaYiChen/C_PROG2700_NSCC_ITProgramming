/*
 * Author: Yi Chen
 * on 2/16/20.
 */



#include <stdio.h>
#include <math.h>


double bisect(double right, double left, double (*f)(double));

int main() {
    printf("Hello, World!\n");
    printf("cos %f", bisect(0,3,cos));
    return 0;
}
