#ifndef MEMORIA_C
#define MEMORIA_C
#include <stdio.h>
#include <stdlib.h>

typedef struct bloque bloque;
void push(bloque **head, int id, int tama, int duracion, int tamtotal);
void pop(bloque **head, int pos);
void print_list(bloque **head);

typedef struct bloque
{
    int id;
    int tama;
    int duracion;
    struct bloque *next;
} bloque;

int cant;
void push(bloque **head, int id, int tama, int duracion, int tamtotal)
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
        temp2->tama = tamtotal - temp->tama;
        temp2->duracion = 0;
        temp->next = temp2;
        temp2->next = NULL;
        *head = temp;
        cant += 2;
    }
    else
    {
        while (current->next != NULL)
            current = current->next;

        current->next = temp;
        bloque *temp2 = (bloque *)malloc(sizeof(bloque));
        temp2->id = 0;
        temp2->tama = tamtotal - temp->tama;
        temp2->duracion = 0;
        temp->next = temp2;
        temp2->next = NULL;
        cant + 2;
    }
}
void pop(bloque **head, int pos)
{
    if ((*head) == NULL)
    {
        return;
    }
    bloque *t, *t2;
    int cont = 0;
    t = (*head);
    while (t->next != NULL && pos < cont)
    {
        if (cont == pos)
        {
            t->id = 0;
            t->duracion = 0;
            if (t->next->duracion == 0)
            {
                t->next->tama += t->tama;
                t2->next = t->next;
                t->next = NULL;
                free(t);
            }
            if (t2->duracion == 0)
            {
                t2->tama+=t->tama;
                t2->next=t->next;
                t->next=NULL;
                free(t);
            }
        }
        t2 = t;
        t = t->next;
        cont++;
    }

}
void print_list(bloque **head)
{
    bloque *current = *head;

    while (current != NULL)
    {
        printf("%d, %d, %d, %d\n", current->id, current->duracion,
               current->tama);
        current = current->next;
    }
}
int isEmpty(bloque **head){
    return ((*head)==NULL ? 0:1);
}

#endif