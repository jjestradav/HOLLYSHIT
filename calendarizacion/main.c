#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "read.c"
#include"list.c"
p* head=NULL;
int main(){
        char* arg[4];
        
        FILE *fp;
        char *filename = "procesos.txt";
        read_gen(fp, filename, &head);
           for(p *l = head; l != NULL; l = l->next) {
        printf("%d, %d, %d, %d\n", l->id,l->horallegada,l->duracion,l->tama);
    }
    
    return 0;
}