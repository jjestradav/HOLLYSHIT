#include <math.h>
typedef struct pagina
{
    int id;
    int duracion;
    int tama;
    int sobrante;
} page;

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
void printBeginM(FILE *tex, char *filename, int tamaOri)
{

    // tex = fopen(filename, "w+");
    //char* msg="\\documentclass[10pt,a4paper]{article}\n\\usepackage[utf8]{inputenc}\n\\begin{document}\n\\begin{center}\n";
    fputs("\\documentclass[10pt,a4paper]{article}\n\\usepackage[utf8]{inputenc}\n\\begin{document}\n\\begin{center}\n", tex);
    fprintf(tex, "\\section*{Configuracion}\n\\begin{description}\n\\item[Algoritmo:] %s \n", "Paginacion");
    fprintf(tex, "\\item[Tamaño total:] %d \n\\end{description}\n\\end{center}\n", tamaOri);
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
    int cantfilas = sqrt(cantceldas);
    page *matriz[cantfilas][cantfilas];
    p *temp = NULL;
    p *espera = NULL;
    temp = *head;
    espera = temp;
    for (int i = 0; i < cantfilas; i++)
    {
        for (int j = 0; j < cantfilas; j++)
        {
            matriz[i][j] = NULL;
        }
    }
    int instante = 1;
    printBeginM(tex, filename2, tammemo);
    while (isEmpty(head) != 0 &&isEmptyP(*matriz, cantfilas, cantfilas) != 0)
    {

        for (int i = 0; i < cantfilas; i++)
        {
            for (int j = 0; j < cantfilas; j++)
            {

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
        for(int i=0; i<cantfilas; i++){
            fprintf(tex, "c");
        }
        fprintf(tex,"}\n");
        for (int i = 0; i < cantfilas; i++)
        {
            fprintf(tex, "\\hline ");
            for (int j = 0; j < cantfilas; j++)
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
        instante++;
    }
    printEndM(tex, filename2);
}