#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "read.c"
#include "list.c"
#include "paginacion.c"
p *head = NULL;
int main()
{
    char *arg[4];

    FILE *fp;
    char *filename = "/home/jose/Documents/HOLLYSHIT/file.txt";
    read_gen(fp, filename, &head);
    for (p *l = head; l != NULL; l = l->next)
    {
        printf("%d, %d, %d, %d\n", l->id, l->horallegada, l->duracion, l->tama);
    }
    dequeue(&head);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("*********************************************************************************************************\n");
    for (p *l = head; l != NULL; l = l->next)
    {
        printf("%d, %d, %d, %d\n", l->id, l->horallegada, l->duracion, l->tama);
    }

    // FILE *f;
    // char* name="config.txt";
    // read_config(f,name,arg);

    // 
       
    //    char* nombre1="Secuencial";
    //    printf("%s",arg[0]);
    //     if (arg[0] == nombre1)
    //     {
    //         printf("entro\n");
    //         if (arg[1] == "BF")
    //         {
    //         }
    //         if (arg[1] == "FIFO")
    //         {
    //         }
    //         if (arg[1] == "WF")
    //         {
    //         }
    //     }
    //     if(arg[0]=="Paginacion"){
    //         paginacion(arg);
    //     }
    

    return 0;
}