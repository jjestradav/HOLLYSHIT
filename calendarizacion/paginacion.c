#include <math.h>
#include <stdbool.h>
typedef struct pagina
{
    int id;
    int duracion;
    int tama;
    int sobrante;
} page;
<<<<<<< HEAD

int filas=0;
int columnas=0;
void factoriza(int cantpaginas){
    int aux=-1000;
    int aux1;
    int aux2;
    int rows;
    int cols;
    for(int i=1; i<cantpaginas; i++){
        for(int j=1; j<cantpaginas; j++){
            if(i*j==cantpaginas){
             aux1= i*(-1);
             aux2= j*(-1);
            if(aux<aux1-aux2){
                aux = aux1-aux2;
                rows = i;
                cols = j;
            }
            }
        }
    }
    filas=rows;
    columnas=cols

=======
int filas=0;
int columnas=0;
bool isDone(int filas, int columnas, page *mat[filas][columnas]){
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            if((*mat) != NULL){
                    if(mat[i][j]->id > 0){
                        return false;
                    }
            }
            
        }
    }
    return true;
}
void factoriza(int cantpaginas){
    int aux=0;
    int rows;
    int cols;
    for(int i=1; i<=sqrt(cantpaginas); i++){
        if(cantpaginas%i<=aux){
		aux=cantpaginas%i;
		rows= cantpaginas/i;
		cols= i;
		}
	}
    filas=rows;
    columnas=cols;
>>>>>>> d944269394bc1ad080373aac6d859b3248600df1
}
int isEmptyP(page **mat, int filas, int columnas)
{
    int flag = 0;
    for (int i = 0; i < columnas; i++)
    {
        for (int j = 0; j < filas; j++)
        {
            if (&mat[i][j] == NULL)
            {
                flag += 1;
            }
        }
        return (flag == (filas * columnas) ? 0 : 1);
    }
}

void printBeginM(FILE *tex, char *filename, int tamaOri, int tamPag)
{

    // tex = fopen(filename, "w+");
    //char* msg="\\documentclass[10pt,a4paper]{article}\n\\usepackage[utf8]{inputenc}\n\\begin{document}\n\\begin{center}\n";
    fputs("\\documentclass[10pt,a4paper]{article}\n\\usepackage[utf8]{inputenc}\n\\begin{document}\n\\begin{center}\n", tex);
    fprintf(tex, "\\section*{Simulación de Manejo de Memoria}\n\\begin{description}\n\\item[Algoritmo:] %s \n", "Paginacion");
    fprintf(tex, "\\item[Tamaño total:] %d \n \\item[Tamaño de página:] %d\n\\item[Tamaño de la Matriz:] %d x %d ]\n\\end{description}\n\\end{center}\n", tamaOri,tamPag,filas,columnas);
    //fclose(tex);
}
void printEndM(FILE * tex,char* filename){
    //tex = fopen(filename, "w+");
    char* msg="\\end{document}\n";
    fputs(msg,tex);
    //fclose(tex);
}
void paginacion(char *arg[], p **head, FILE *tex, char *filename2)
{
    int tammemo = atoi(arg[2]);
    int tampage = atoi(arg[1]);
    int cantceldas = tammemo / tampage;
    factoriza(cantceldas);
    //int cantfilas = sqrt(cantceldas);
    page *matriz[filas][columnas];
    p *temp = NULL;
    p *espera = NULL;
    temp = *head;
    espera = temp;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] = NULL;
        }
    }
    bool flag1 = false;
    bool flag2= false;
    bool done= false;
    int instante = 1;
<<<<<<< HEAD
    printBeginM(tex, filename2, tammemo);
    while (isEmpty(head) != 0 && isEmptyP(*matriz, cantfilas, cantfilas) != 0)
=======
    printBeginM(tex, filename2, tammemo,tampage);
    while (isEmpty(head) != 0 && isEmptyP(*matriz, filas, columnas) != 0)
>>>>>>> d944269394bc1ad080373aac6d859b3248600df1
    {
     flag1=flag2=done=false;
     
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
              
              if( isEmpty(head) != 0){ 

                if ((*head) != NULL && (*head)->horallegada <= instante)
                {
                    if (matriz[i][j] == NULL)
                    {
                        page *nueva = malloc(sizeof(page));
                        matriz[i][j] = nueva;
                        nueva->id = (*head)->id;
                        nueva->duracion = (*head)->duracion;
                        nueva->sobrante = 0;
                        (*head)->tama -= tampage;
                        if ((tampage - (*head)->tama) >= 0)
                        {
                            nueva->sobrante = tampage - (*head)->tama;
                            dequeue(head);
                            espera = *head;
                            break;
                        }
                    }
                    else
                    {
                        matriz[i][j]->duracion -= 1;
                        if (matriz[i][j]->duracion == 0)
                        {
                            free(matriz[i][j]);
                            matriz[i][j] = NULL;
                        }
                    }
                }

              }
              else{
                  if(!isDone(filas,columnas,matriz)){
                      
                        //instante++;
                        flag1=true;
                        break;
                  }
                  else{
                        flag1=true;
                        done=true;
                  }
              }
            
                   if(flag1){
                   flag2 = true;
                   break;
               }
            }
            if(flag2){
                break;
            }
        }
        char * msg="\\begin{center}\n\nInstante: ";
        fprintf(tex,"%s%d%s",msg,instante,"\n\n");
        fprintf(tex,"\\hfill \n");
        fprintf(tex,"\\hfill \n");
        fprintf(tex,"\\hfill \n");
        fprintf(tex,"\\break \n");
         char* msg2="\\begin{tabular}\t";
        fprintf(tex,"%s",msg2);
        fprintf(tex,"{");
        for(int i=0; i<filas; i++){
            fprintf(tex, "c");
        }
        fprintf(tex,"}\n");
        for (int i = 0; i < filas; i++)
        {
            fprintf(tex, "\\hline ");
            for (int j = 0; j < columnas; j++)
            {
                char* tab;
                if (matriz[i][j] != NULL)
                {
                    fprintf(tex," P%d -%d &  ",matriz[i][j]->id, matriz[i][j]->sobrante);
                }
                else
                {
                    fprintf(tex," ----- &  ");
                }
            }
             fprintf(tex,"\\\\");
        }
        fprintf(tex,"\\hfill \n");
        fprintf(tex,"\\hfill \n");
        fprintf(tex,"\\hfill \n");
        fprintf(tex,"\\break \n");
        if (*head != NULL && espera->next != NULL)
        {
            espera = espera->next;
        }
        if ((*head) != NULL && espera->horallegada <= instante)
        {
            fprintf(tex,"%s", "En espera: \t");
            fprintf(tex,"P%d %s", espera->id, "\n");
        }
        char * msg5="\\end{tabular}\n\\end{center}\n\\pagebreak\n";
        fprintf(tex,"%s",msg5);
        // printf("%s", "pagebreak");

        if(flag1 && flag2 && done)
            break;

        instante++;
    }
    printEndM(tex, filename2);
}