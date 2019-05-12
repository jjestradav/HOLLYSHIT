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
void paginacion(char *arg[], p **head)
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
            // page *plantilla = malloc(sizeof(page));
            // plantilla->id=0;
            // plantilla->tama=tampage;
            // plantilla->duracion=0;
            // plantilla->sobrante=0;
            matriz[i][j] = NULL;
        }
    }
    int instante = 1;
    while (isEmpty(head)!=0 && isEmptyP(*matriz, cantfilas, cantfilas)!=0)
    {
        for (int i = 0; i < cantfilas; i++)
        {
            for (int j = 0; j < cantfilas; j++)
            {
                
                if ((*head)!=NULL && (*head)->horallegada <= instante)
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
                            espera=*head;
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

        for (int i = 0; i < cantfilas; i++)
        {
            for (int j = 0; j < cantfilas; j++)
            {
                if (matriz[i][j] != NULL)
                {
                    printf("%d %d       ", matriz[i][j]->id, matriz[i][j]->sobrante);
                }
                else
                {
                    printf("%s      ", "---");
                }
            }
            printf("\n");
        }
        printf("\n");

        if (*head!=NULL && espera->next != NULL)
        {
            espera = espera->next;
        }
        if ((*head)!=NULL && espera->horallegada <= instante)
        {
            printf("%s", "En espera");
            printf("%d %s", espera->id, "\n");
        }
        // printf("%s", "pagebreak");
        instante++;
    }
}