#include <stdio.h>
#include <unistd.h>
#include "poisson.c"
#include "random.c"
int main(int argc, char **argv)
{
    int np;     //numero de proceso
    int pid;    //id de proceso
    int memi;   // memoria minima
    int mema;   //memoria maxima
    int durmi;  // duracion minima
    int durma;  // duracion  maxima
    int hlli;   // hora de llegada inicial
    int lambda; //lambda
    if (argc < 8)
    {
        printf("DEBE de ingresar 8 argumentos");
        printf("\n");
        return 0;
    }
    else
    {
        np = atoi(argv[1]);
        pid = atoi(argv[2]);
        memi = atoi(argv[3]);
        mema = atoi(argv[4]);
        durmi = atoi(argv[5]);
        durma = atoi(argv[6]);
        hlli = atoi(argv[7]);
        lambda = atoi(argv[8]);
        creaTabla(lambda);
        for (int i = 0; i < np; i++)
        {
            printf("%d", pid);
            printf("\t");
            printf("%d", hlli);
            printf("\t");
            printf("%d", ramdom_Between(durmi, durma));
            printf("\t");
            printf("%d", ramdom_Between(memi, mema));
            printf("\n");
            pid = pid + 1;
            long double random= random_R();
            int proba = valorPoisson(random);
            hlli = hlli + proba;
            sleep(1);
        }
        return 1;
    }
    return 0;
}

//  printf("\n");
// creaTabla(2);
// printf("%d", valorPoisson(random_R()));
// printf("\n");
// for(int i=0; i< 3*2; i++){
//     printf("%Lf", tablaPoisson[i]);
//     printf("\n");