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
    char *filename = "/home/jonathan/Desktop/Sistemas Operativos/HOLLYSHIT/file.txt";
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
    char* name="config.txt";
    read_config(f,name,arg);

        if (!strcmp(arg[0],"Secuencial"))
        {
            
            if (!strcmp(arg[1],"FIFO"))
            {
                printf("Aqui!!!!\n");
                int tamtotal=atoi(arg[2]);
                     FIFO(&head,&blo,&tamtotal);
                     //print_listM(&blo);
            }
            else
            if (!strcmp(arg[1],"BF"))
            {

            }
            else
            if (!strcmp(arg[1],"WF"))
            {

            }
        }
        else
        if(arg[0]=="Paginacion"){
            // paginacion(arg);
        }
    

    return 0;
}