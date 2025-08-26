#include "differentiate.h"

double *differentiate(double* data, int n){
    if((n == 0) || (n == 1)){
        return NULL;
    }

    double *diff = (double*) malloc(sizeof(double)*(n-1));
    for(int i=0; i<(n-1); ++i){
        diff[i] = data[i+1] - data[i];
    }
    return diff;
}
