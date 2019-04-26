#include <stdio.h> 
#include <math.h>
int kfactorial(int n){
    int fac=1;
    for(int i=n; i>0; i--){
    fac= fac*i;
    }
    return fac; 
}
double calculapoisson(int lambda, int k){
    double power= pow(M_E,(-lambda));
    double x= pow(lambda, k);
    int factk= kfactorial(k);
    double result=(power*x)/factk;
    return result;
}

