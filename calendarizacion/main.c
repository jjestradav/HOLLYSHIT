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
//     pushM(&blo,1,40,2,&a);//[0]
//     pushM(&blo,2,30,3,&a);//[1] 0
//     pushM(&blo,3,30,2,&a);//[2] 1 0 
//     pushM(&blo,4,30,2,&a);//[3] 2 1 0
//     pushM(&blo,5,30,4,&a);//[4] 3 2 1 0
//     pushM(&blo,6,30,5,&a);//[5] 4 3 2 1 
//     pushM(&blo,7,30,2,&a);//[6] 5 4 3 2

    
//     for (bloque *l = blo; l != NULL; l = l->next)
//     {
//         printf("%d, %d, %d, %d\n", l->id, l->tama, l->duracion, cantMem);
//     }
//     printf("\n\n\n\n\n");
//     popM(&blo,0);
//     popM(&blo,1);
//     popM(&blo,3);
//     popM(&blo,4);
//     popM(&blo,4);
//     //popM(&blo,6);
   
// for (bloque *l = blo; l != NULL; l = l->next)
//     {
//         printf("%d, %d, %d, %d\n", l->id, l->tama, l->duracion, cantMem);
//     }



    FILE *fp;
    char *filename = "/home/jose/Documents/HOLLYSHIT/file.txt";
    read_gen(fp, filename, &head);
    // for (p *l = head; l != NULL; l = l->next)
    // {
    //     printf("%d, %d, %d, %d\n", l->id, l->horallegada, l->duracion, l->tama);
    // }
    // dequeue(&head);
    // printf("\n");
    // printf("\n");
    // printf("\n");
    // printf("\n");
    // printf("\n");
    // printf("*********************************************************************************************************\n");
    // for (p *l = head; l != NULL; l = l->next)
    // {
    //     printf("%d, %d, %d, %d\n", l->id, l->horallegada, l->duracion, l->tama);
    // }


    
    FILE *f;
    FILE * tex;
    char* name="config.txt";
    read_config(f,name,arg);

    char* str1="../";
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