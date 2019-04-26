#include "poisson.c"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv){
int np;
int pid;
int memi;
int mema;
int durmi;
int durma;
int hlli;
int lambda;
if (argc< 8){
    printf("DEBE de ingresar 8 argumentos");
    printf("\n");
    return 1;
}else{
np=atoi(argv[1]);    
pid=atoi(argv[2]);
memi=atoi(argv[3]);
mema=atoi(argv[4]);
durmi=atoi(argv[5]);
durma=atoi(argv[6]);
hlli=atoi(argv[7]);
lambda=atoi(argv[8]);
for (int i=1; i<argc; i++){
    printf("%s", argv[i]);
    printf("\n");
}
printf("%d", np);
printf("\n");
printf("%d", pid);
printf("\n");
printf("%d", memi);
printf("\n");
printf("%d", mema);
printf("\n");
printf("%d", durmi);
printf("\n");
printf("%d", durma);
printf("\n");
printf("%d", hlli);
printf("\n");
printf("%d", lambda);
printf("\n");
return 1;
}
    
}
