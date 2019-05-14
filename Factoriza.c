#include <stdio.h>
#include <math.h>
int filas;
int columnas;
void factoriza(int cantpaginas){
    int aux=0;
    int rows;
    int cols;
    for(int i=1; i<=sqrt(cantpaginas); i++){
        if(cantpaginas%i<=aux){
		aux=cantpaginas%i;
		rows= cantpaginas/i;
		cols= i;
		}
	}
    filas=rows;
    columnas=cols;
}
int main(){
factoriza(25);
printf("%d",filas);
printf("\n");
printf("%d" ,columnas);

return 0; 
}
