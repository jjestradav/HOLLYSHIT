#include <stdlib.h> 
#include <math.h>
long double * tablaPoisson;

void creaTabla(int lambda){
    tablaPoisson = calloc(sizeof(long double), 3*lambda);
    tablaPoisson[0] = exp(-1*lambda);
    int i =0; int ifactorial = 1;
    while(i++ <3*lambda){
        ifactorial *=i;
        tablaPoisson[i] = tablaPoisson[i-1]+
                        tablaPoisson[0]*
                        pow(lambda,i)/ifactorial;
    }
    tablaPoisson[i-1] =1.0;
}

int valorPoisson(long double r){
    int respuesta =0;
    while(r>tablaPoisson[respuesta++]);
    return respuesta-1;   
}


/*int kfactorial(int n){
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
}*/

