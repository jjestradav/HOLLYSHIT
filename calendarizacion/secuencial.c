#include<stdio.h>
#include<stdlib.h>
#include"memoria.c"
#include"list.c"
#include <stdbool.h>

void FIFO(p** head,bloque** mem, int * memtotal);

void FIFO(p** head, bloque** mem,int * memtotal){

int tiempo = 0;
bool finished=false;
p* ult = last(head);
int fin= ult->horallegada;
int cont=0;
while(!finished){
   printf("\n\nIter no.%d**********************\n\n",tiempo);
      if(tiempo==9){
          printf("\nHola\n");
      } 
    if(isEmpty(head)!= 0 ){
        //    print_list(head);
        //     printf("\n");
        //     print_listM(mem);
         if(mem != NULL)
                    juntarBloques(mem);
  //print_list(head);
            // printf("\n");
            // print_listM(mem);
        if((*head)->tama <= *memtotal) {
            pushM(mem,(*head)->id,(*head)->tama,(*head)->duracion,memtotal);
              pop(head);

        }
        else
        {
         
          if(buscaEspacio(mem,(*head)->id,(*head)->duracion,(*head)->tama)){
             // print_listM(mem);
              pop(head);
          }

             print_list(head);
             //print_listM(mem);
        }
             
     }
//else
        if(isEmpty(head)== 0 && isEmptyM(mem)!= 0){

             if(!Terminado(mem)){
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
                 
                   tiempo++;
                restaDuracion(mem);
                limpiaId(mem);
                if(mem != NULL)
                    juntarBloques(mem);
                 print_listM(mem); 

              continue;  
            }
            else
                break;
            
        }

        tiempo++;
        restaDuracion(mem);
          if((*mem)!= NULL)
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
         //print_listM(mem);  
  if(mem != NULL)
        juntarBloques(mem);

 print_listM(mem);  

    }
}

