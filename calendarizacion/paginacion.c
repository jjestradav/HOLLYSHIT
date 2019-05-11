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
        return (flag == (filas * columnas) ? 1 : 0);
    }
}
void paginacion(char *arg[], p **head)
{
    int tammemo = atoi(arg[2]);
    int tampage = atoi(arg[1]);
    int cantceldas = tammemo / tampage;
    int cantfilas = sqrt(cantceldas);
    page *matriz[cantfilas][cantfilas];
    p *temp = NULL;
    p *espera=NULL;
    temp = *head;
    espera = temp;
    for (int i = 0; i < cantfilas; i++)
    {
        for (int j = 0; j < cantfilas; j++)
        {
            // page *plantilla = malloc(sizeof(page));
            // plantilla->id=0;
            // plantilla->tama=tampage;
            // plantilla->duracion=0;
            // plantilla->sobrante=0;
            matriz[i][j] = NULL;
        }
    }
    int instante = 0;
    while (isEmpty(head) && !isEmptyP(*matriz, cantfilas, cantfilas))
    {
        for (int i = 0; i < cantfilas; i++)
        {
            for (int j = 0; j < cantfilas; j++)
            {
                if (temp->horallegada <= instante)
                {
                    if (matriz[i][j] == NULL)
                    {
                        page *nueva = malloc(sizeof(page));
                        matriz[i][j] = nueva;
                        nueva->id = temp->id;
                        nueva->duracion = temp->duracion;
                        temp->tama -= tampage;
                        if ((tampage - temp->tama) >= 0)
                        {
                            nueva->sobrante = tampage - temp->tama;
                            dequeue(head);
                            break;
                        }
                    }
                    else
                    {
                        matriz[i][j]->duracion -= 1;
                        if (matriz[i][j]->duracion == 0)
                        {
                            matriz[i][j] = NULL;
                        }
                    }
                }
                if (matriz[i][j] != NULL)
                {
                    printf("%d, %d, %s", matriz[i][j]->id, matriz[i][j]->sobrante, "\n");
                }
            }
           
            printf("\t");
        }
         if (espera->next != NULL)
            {
                espera = espera->next;
            }
        if (espera->horallegada <= instante)
        {
            printf("%s", "En espera");
            printf("%d %s", espera->id, "\t");
        }
        // printf("%s", "pagebreak");
         instante++;
    }
}