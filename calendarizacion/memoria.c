#ifndef LIST_C
#define LIST_C
#include <stdio.h>
#include <stdlib.h>

typedef struct bloque bloque;
void push(bloque **head, int id, int tama, int duracion);
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
void push(bloque **head, int id, int tama, int duracion)
{
    bloque *current = *head;
    bloque *temp = (bloque *)malloc(sizeof(bloque));
    temp->id = id;
    temp->tama = tama;
    temp->next = NULL;

    if (current == NULL)
    {
        *head = temp;
        cant++;
    }
    else
    {
        while (current->next != NULL)
            current = current->next;

        current->next = temp;
        cant++;
    }
}
void pop(bloque **head, int pos)
{
    if ((*head) == NULL)
    {
        return;
    }
    bloque *t, t2;
    int cont = 0;
    t = (*head);
    while (t != NULL)
    {
        if (cont == pos)
        {
            t->id = 0;
            t->duracion = 0;
            break;
        }
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

#endif