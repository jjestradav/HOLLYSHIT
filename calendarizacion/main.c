#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "read.c"
#include "list.c"
#include "paginacion.c"
#include "memoria.c"
#include"secuencial.c"

int a=220;
int main()
{
    char *arg[4];
    p *head = NULL;
    bloque* blo=NULL;
    FILE *fp;
    char *filename = "../file.txt";
    read_gen(fp, filename, &head);
    FILE *f;
    FILE * tex;
    char* name="config.txt";
    read_config(f,name,arg);

    char* str1="../Salida/";
    char* str2= arg[3];
    char * filename2 = (char *) malloc(1 + strlen(str1)+ strlen(str2) );
    strcpy(filename2, str1);
    strcat(filename2, str2);
        printf("\n%s\n",filename2);
    

        if (!strcmp(arg[0],"Secuencial"))
        {
            
            if (!strcmp(arg[1],"FIFO"))
            {
                tex=fopen(filename2,"w");
                int tamtotal=atoi(arg[2]);
                int tamaOri=tamtotal;
                FIFO(&head,&blo,&tamtotal,tex,filename2,tamaOri,"FIFO");
                fclose(tex);
            }
            else
            if (!strcmp(arg[1],"BF"))
            {
                tex=fopen(filename2,"w");
                int tamtotal = atoi(arg[2]);
                int tamaOri=tamtotal;
                BestFit(&head, &blo,&tamtotal,tex ,filename2,tamaOri,"Best Fit");
                fclose(tex);
            }
            else
            if (!strcmp(arg[1],"WF"))
            {
                tex=fopen(filename2,"w");
                int tamtotal = atoi(arg[2]);
                int tamaOri=tamtotal;
                WorstFit(&head, &blo, &tamtotal,tex ,filename2,tamaOri,"Worst Fit");
                fclose(tex);
            }
        }
        else
        if(!strcmp(arg[0],"Paginacion")){
            tex=fopen(filename2,"w");
            paginacion(arg , &head, tex, filename2);
              fclose(tex);
        }
    

    return 0;
}