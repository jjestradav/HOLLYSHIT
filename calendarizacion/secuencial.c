#include<stdio.h>
#include<stdlib.h>
#include"memoria.c"
#include"list.c"
#include <stdbool.h>

void FIFO(p** head,bloque** mem, int * memtotal);

void FIFO(p** head, bloque** mem,int * memtotal){

int tiempo=(*head)->horallegada;
p* ult = last(head);
int fin= ult->horallegada;
bool finished=false;
int cont=0;
while(tiempo<=20){
   printf("\n\n**********************\n\n"); 
    if(isEmpty(head)!= 0 ){
       if((*mem)!= NULL)
           limpiaId(mem);
       
        if((*head)->tama <= *memtotal) {
            pushM(mem,(*head)->id,(*head)->tama,(*head)->duracion,memtotal);
              pop(head);

        }
        else
        {
          if(buscaEspacio(mem,(*head)->id,(*head)->duracion,(*head)->tama)){
              pop(head);
          }
             print_list(head);
        }
         printf("\n\n**********************\n\n");        
     }
//else
        if(isEmpty(head)== 0 && isEmptyM(mem)!= 0 && tiempo>(int)tiempo/2){
             if(!Terminado(mem)){
                 tiempo++;
                restaDuracion(mem);
                limpiaId(mem);
                cont=0;
                while(cont <= cantMem-1 && cantMem != 0){
                    if(verificaCero(mem)){
                        int pos=retornaPos_En_Cero(mem);
                        popM(mem,pos,memtotal);
                
                    }
                    else
                    break;

                    cont++;
                } 
                 print_listM(mem);  
              continue;  
            }
            else
                break;
            
        }

        tiempo++;
        restaDuracion(mem);
        cont=0;
        while(cont <= cantMem-1 && cantMem != 0){
            if(verificaCero(mem)){
                int pos=retornaPos_En_Cero(mem);
                popM(mem,pos,memtotal);
                
            }
            else
             break;

            cont++;
        } 
 print_listM(mem);  

    }
}

