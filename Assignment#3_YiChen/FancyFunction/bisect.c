//
// Created by Yi Chen
// on 2/16/20.
//



#include <assert.h>
#include <math.h>


double bisect(double right, double left, double (*f)(double)){
    assert(f(right) * f(left) < 0);

    double half = (right + left) / 2;
    double diff = fabs(right - left);

    while (diff>0.00000001 && f(half)!=0) {
        if (f(right) * f(half) < 0){
            left = half;
            diff = fabs(right - left);
            half = (right + left) / 2;
        }
        else if (f(left) * f(half) < 0){
            right = half;
            diff = fabs(right - left);
            half = (right + left) / 2;
        }
    }
    return half;
}
