#ifndef MEMORIA_C
#define MEMORIA_C
#include <stdio.h>
#include <stdlib.h>

typedef struct bloque bloque;
void pushM(bloque **head, int id, int tama, int duracion, int* tamtotal);
void popM(bloque **head, int pos);
void print_listM(bloque **head);

typedef struct bloque
{
    int id;
    int tama;
    int duracion;
    struct bloque *next;
} bloque;

static int cantMem=0;
void pushM(bloque **head, int id, int tama, int duracion, int* tamtotal)
{
    bloque *current = *head;
    bloque *temp = (bloque *)malloc(sizeof(bloque));
    temp->id = id;
    temp->tama = tama;
    temp->duracion = duracion;
    temp->next = NULL;

    if (current == NULL)
    {
        bloque *temp2 = (bloque *)malloc(sizeof(bloque));
        temp2->id = 0;
        temp2->tama = *tamtotal - temp->tama;
        *tamtotal-=temp->tama;
        temp2->duracion = 0;
        temp->next = temp2;
        temp2->next = NULL;
        *head = temp;
        cantMem += 2;
    }
    else
    {
        bloque * aux = NULL;
        while (current->next != NULL){
            aux=current;
            current = current->next;
        }

        aux->next = temp;
        free(current);
        bloque *temp2 = (bloque *)malloc(sizeof(bloque));
        temp2->id = 0;
        temp2->tama = *tamtotal - temp->tama;
        *tamtotal-=temp->tama;
        temp2->duracion = 0;
        temp->next = temp2;
        temp2->next = NULL;
        cantMem ++;
    }
}
void popM(bloque **head, int pos)
{
    if ((*head) == NULL)
    {
        return;
    }
    bloque *t = NULL;
    bloque* t2 = NULL;
    bloque * t3= NULL;
    int cont = 0;
    t = (*head);
    while (t->next != NULL && cont <= pos)
    {
  
        if (cont == pos)
        {
            t->id = 0;
            t->duracion = 0;
            if (t->next->duracion == 0 && t2 != NULL)
            {

                t->next->tama += t->tama;
                t2->next = t->next;
                t->next = NULL;
                free(t);
                cantMem--;
                if(t3 != NULL){
                    t2 = t2->next;
                    t3 = t3->next;
                    if(t3->duracion==0){
                        t3->tama+=t2->tama;
                        t3->next=t2->next;
                        t2->next = NULL;
                        free(t2);
                        return;
                    }
                }
                return;
            }
            if(t2 != NULL){
            if (t2->duracion == 0)
            {
                t2->tama+=t->tama;
                t2->next=t->next;
                t->next=NULL;
                free(t);
                cantMem--;
                return;
            }
                }
        }
        t3 = t2;
        t2 = t;
        t = t->next;
        cont++;
    }

}
void print_listM(bloque **head)
{
    bloque *current = *head;

    while (current != NULL)
    {
        printf("%d, %d, %d\n", current->id, current->duracion,
               current->tama);
        current = current->next;
    }
}
int isEmptyM(bloque **head){
    return ((*head)==NULL ? 0:1);
}

#endif