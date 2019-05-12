#include<stdio.h>
#include<stdlib.h>
#include"memoria.c"
#include"list.c"
#include<string.h>
#include <stdbool.h>
#include <gnu/lib-names.h>
void FIFO(p** head,bloque** mem, int * memtotal,FILE * tex ,char* filename, int tamaOri, char* algoritmo);
void BestFit(p** head,bloque** mem, int * memtotal, FILE* tex, char* filename, int tamaOri, char* algoritmo);
void WorstFit(p** head,bloque** mem, int * memtotal,FILE * tex , char* filename, int tamaOri, char* algoritmo);
void printBegin(FILE* tex, char * filename, int tamaOri, char* algoritmo);
void printEnd(FILE* tex, char* filename);
void printTex(FILE* tex, char* filename,p** head, bloque** mem, int tiempo);
void printBegin(FILE * tex, char* filename, int tamaOri, char* algoritmo){
   
   // tex = fopen(filename, "w+");
    //char* msg="\\documentclass[10pt,a4paper]{article}\n\\usepackage[utf8]{inputenc}\n\\begin{document}\n\\begin{center}\n";
    fputs("\\documentclass[10pt,a4paper]{article}\n\\usepackage[utf8]{inputenc}\n\\begin{document}\n\\begin{center}\n",tex);
   fprintf(tex,"\\section*{Configuracion}\n\\begin{description}\n\\item[Algoritmo:] %s \n", algoritmo);
   fprintf(tex,"\\item[Tamaño total:] %d \n\\end{description}\n\\end{center}\n",tamaOri);
    //fclose(tex);
  
}
void printEnd(FILE * tex,char* filename){
    //tex = fopen(filename, "w+");
    char* msg="\\end{document}\n";
    fputs(msg,tex);
    //fclose(tex);
}
void FIFO(p** head, bloque** mem,int * memtotal, FILE* tex,char* filename, int tamaOri, char* algoritmo){
printBegin(tex,filename,tamaOri,algoritmo);
int currentSize = tamaOri;
int tiempo = 0;
bool finished=false;
p* ult = last(head);
int fin= ult->horallegada;
int cont=0;
while(!finished){
   printf("\n\nIter no.%d**********************\n\n",tiempo);
 
    if(isEmpty(head)!= 0 ){
         if(mem != NULL)
                    juntarBloques(mem);

        if((*head)->tama <= currentSize) {
                 if((*head)->horallegada <= tiempo){
                 if(pushMem(mem,(*head)->id,(*head)->tama,(*head)->duracion,tamaOri,&currentSize))
                            pop(head);
                 }
                 else{
                      printTex(tex,filename,head,mem,tiempo);
                     tiempo++;
                      if((*mem) != NULL){
                          restaDuracion(mem); 
                          limpiaId(mem);
                         juntarBloques(mem);
                     // print_listM(mem);
                      
                      }
                      
                      continue;
                 }
        }
        else
        {
         
          if(buscaEspacio(mem,(*head)->id,(*head)->duracion,(*head)->tama)){
             // print_listM(mem);
              pop(head);
          }

             //print_list(head);
             //print_listM(mem);
        }
             
     }
//else
        if(isEmpty(head)== 0 && isEmptyM(mem)!= 0){

             if(!Terminado(mem)){
                printTex(tex,filename,head,mem,tiempo); 
                tiempo++;
                restaDuracion(mem);
                limpiaId(mem);
                if(mem != NULL)
                    juntarBloques(mem);
               //  print_listM(mem); 

              continue;  
            }
            else
                break;
            
        }

        printTex(tex,filename,head,mem,tiempo); 
        tiempo++;
        restaDuracion(mem);
          if((*mem)!= NULL)
           limpiaId(mem);
             if(mem != NULL)
        juntarBloques(mem);
    }
    printEnd(tex,filename);
}

void BestFit(p** head,bloque** mem, int * memtotal, FILE* tex ,char* filename,int tamaOri, char* algoritmo){
    printBegin(tex,filename,tamaOri,algoritmo);

int currentSize = tamaOri;
int tiempo=0;
    p* aux = NULL;
    bool finished=false;
    while(!finished){
         printf("\n\nIter no.%d**********************\n\n",tiempo);
         if(tiempo == 17){
             printf("\nHola\n");
         }
        if(isEmpty(head)!= 0){
               if(mem != NULL)
                    juntarBloques(mem);

            if((*head)->tama <= currentSize) {
                if((*head)->horallegada <= tiempo){
                 if(pushMem(mem,(*head)->id,(*head)->tama,(*head)->duracion,tamaOri,&currentSize))
                            pop(head);
                  else{

                      tiempo++;
                      if((*mem) != NULL){
                          restaDuracion(mem); 
                      limpiaId(mem);
                      juntarBloques(mem);
                     // print_listM(mem);
                      printTex(tex,filename,head,mem,tiempo); 
                      }
                      
                      continue;
                  }          
                }
                else{
                         tiempo++;
                      if((*mem)!= NULL){ 
                        restaDuracion(mem); 
                        limpiaId(mem); 
                        juntarBloques(mem);
                        }
                        //print_listM(mem);
                        printTex(tex,filename,head,mem,tiempo); 
                        continue;
                    }
                }
            
            else{
                int pos= retornaPosBF(head,tiempo);
                if(pos != -1){
                    aux= popLpos(head,pos);
                    if( aux != NULL){
                        int posM=retornaPosMBF(mem,aux->tama);
                        if(posM != -1){
                            pushMpos(mem,aux->id,aux->tama,aux->duracion,posM);
                        }
                    }

                }
                 //print_list(head);
            }

        }
            if(isEmpty(head)== 0 && isEmptyM(mem)!= 0){
                    if(!Terminado(mem)){
                            tiempo++;
                        restaDuracion(mem);
                        limpiaId(mem);
                        if(mem != NULL)
                            juntarBloques(mem);

                         printTex(tex,filename,head,mem,tiempo);  
                        //print_listM(mem); 
                        continue;  
                    }
                    else{
                            finished=true;
                            continue;
                    }


            }


            tiempo++;
            
            if((*mem)!= NULL){
              restaDuracion(mem); 
              limpiaId(mem); 
              juntarBloques(mem);
              // print_listM(mem); 
            }
                
            printTex(tex,filename,head,mem,tiempo);  
                
        }

printEnd(tex,filename);
}

void WorstFit(p** head,bloque** mem, int * memtotal, FILE* tex ,char* filename,int tamaOri, char* algoritmo){
    printBegin(tex,filename,tamaOri,algoritmo);

int currentSize = tamaOri;
int tiempo=0;
    p* aux = NULL;
    bool finished=false;
    while(!finished){
         printf("\n\nIter no.%d**********************\n\n",tiempo);
         if(tiempo == 17){
             printf("\nHola\n");
         }
        if(isEmpty(head)!= 0){
               if(mem != NULL)
                    juntarBloques(mem);

            if((*head)->tama <= currentSize) {
                if((*head)->horallegada <= tiempo){
                 if(pushMem(mem,(*head)->id,(*head)->tama,(*head)->duracion,tamaOri,&currentSize))
                            pop(head);
                  else{

                      tiempo++;
                      if((*mem) != NULL){
                          restaDuracion(mem); 
                      limpiaId(mem);
                      juntarBloques(mem);
                     // print_listM(mem);
                      printTex(tex,filename,head,mem,tiempo); 
                      }
                      
                      continue;
                  }          
                }
                else{
                         tiempo++;
                      if((*mem)!= NULL){ 
                        restaDuracion(mem); 
                        limpiaId(mem); 
                        juntarBloques(mem);
                        }
                        //print_listM(mem);
                        printTex(tex,filename,head,mem,tiempo); 
                        continue;
                    }
                }
            
            else{
                int pos= retornaPosWF(head,tiempo);
                if(pos != -1){
                    aux= popLpos(head,pos);
                    if( aux != NULL){
                        int posM=retornaPosMWF(mem,aux->tama);
                        if(posM != -1){
                            pushMpos(mem,aux->id,aux->tama,aux->duracion,posM);
                        }
                    }

                }
                 //print_list(head);
            }

        }
            if(isEmpty(head)== 0 && isEmptyM(mem)!= 0){
                    if(!Terminado(mem)){
                            tiempo++;
                        restaDuracion(mem);
                        limpiaId(mem);
                        if(mem != NULL)
                            juntarBloques(mem);

                         printTex(tex,filename,head,mem,tiempo);  
                        //print_listM(mem); 
                        continue;  
                    }
                    else{
                            finished=true;
                            continue;
                    }


            }


            tiempo++;
            
            if((*mem)!= NULL){
              restaDuracion(mem); 
              limpiaId(mem); 
              juntarBloques(mem);
              // print_listM(mem); 
            }
                
            printTex(tex,filename,head,mem,tiempo);  
                
        }

printEnd(tex,filename);
}
// void printTex(FILE* tex, char* filename,p** head, bloque**mem, int tiempo){

// //tex = fopen(filename,"w+");
//  if((*head) != NULL){
//     p* currentL=(*head);
//     bool flag = false;
//     // while(currentL != NULL){
//     //     if(currentL->horallegada <= tiempo){
//     //         if(!flag){
//     //         char * msg4="En cola \n\n\\begin{table}\\begin{tabular}{|c|c|}\n\\hline\n";
//     //         fprintf(tex,"%s",msg4);
//     //         }
//     //     fprintf(tex,"ID=%d & TAM=%d \\\\ \\hline\n",currentL->id,currentL->tama);
//     //     flag=true;
//     //     }
//     //     currentL = currentL->next;
//     // }
//     // if(flag){
//     // char * msg5="\\end{tabular}\n \\end{table}\n";
//     // fprintf(tex,"%s",msg5);
//     // }
//     }
//     if((*mem)!= NULL){
//     char * msg="\\begin{center}\n\nInstante: ";
//     fprintf(tex,"%s%d%s",msg,tiempo,"\n\n");
//     char* msg2="\\begin{tabular}{|c|c|}\n\\hline\n";
//     fprintf(tex,"%s",msg2);
//     bloque* currentM=(*mem);
//     while(currentM != NULL){
//         fprintf(tex,"ID=%d & TAM=%d \\\\ \\hline\n",currentM->id,currentM->tama);
//         currentM=currentM->next; 
//     }
//     char * msg3="\\end{tabular}\n\\end{center}\n\\pagebreak\n";
//     fprintf(tex,"%s",msg3);
//     }
//     else{
//         char * msg="\\begin{center}\nInstante: ";
//         fprintf(tex,"%s%d\n%s",msg,tiempo,"Memoria Vacia\\\\\n\\end{center}\n");
//         char *msg3="\n";
//         //fprintf(tex,"%s",msg3);
//     }
   
//   //  else{
//        // char * msg4="En cola: Vacia \n";
//         //fprintf(tex,"%s",msg4);
//         // char* msg5="\\end{table}\n";
//         // fprintf(tex,"%s",msg5);
//   //  }
//    // fclose(tex);
// }
void printTex(FILE* tex, char* filename,p** head, bloque**mem, int tiempo){

if((*mem) != NULL){
    char * msg="\\begin{center}\n\nInstante: ";
    fprintf(tex,"%s%d%s",msg,tiempo,"\n\n");
    char* msg2="\\begin{tabular}{|c|c|}\n\\hline\n";
    fprintf(tex,"%s",msg2);
    bloque* currentM = (*mem);
    p* currentL = (*head);

    while(currentM != NULL){
        fprintf(tex,"ID=%d & TAM=%d \\\\ \\hline\n",currentM->id,currentM->tama);
        currentM = currentM->next;
    }
    char * msg3="\\end{tabular}\n";
    fprintf(tex,"%s",msg3);
    bool flag = false;
    while(currentL != NULL){
        if(currentL->horallegada <= tiempo){
            if(!flag){
            char * msg4="\\\\\n\\hfill \\break\n\\hfill \\break\n\\hfill \\break\nEn cola\n\\\\\n\\begin{tabular}{|c|c|}\n\\hline\n";
            fprintf(tex,"%s",msg4);
            }
        fprintf(tex,"ID=%d & TAM=%d \\\\ \\hline\n",currentL->id,currentL->tama);
        flag=true;
        }
        currentL = currentL->next;
    }
    if(flag){
    char * msg5="\\end{tabular}\n\\end{center}\n\\pagebreak\n";
    fprintf(tex,"%s",msg5);
    }
    else{
        fprintf(tex,"\\end{center}\\pagebreak\n");
    }
}
     else{
        char * msg="\\begin{center}\nInstante: ";
        fprintf(tex,"%s%d\n%s",msg,tiempo,"Memoria Vacia\\\\\n\\end{center}\n");
        char *msg3="\n";
        fprintf(tex,"%s",msg3);
    }






}

