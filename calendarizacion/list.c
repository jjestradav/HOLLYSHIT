#include <stdio.h>
#include <stdlib.h>
typedef struct proceso
{
    int id;
    int duracion;
    int horallegada;
    int tama;
    struct proceso *next;
} p;

p *head = NULL;
void push(int id, int duracion, int horallegada, int tama)
{
    p *t, *temp;
    t = (p *)malloc(sizeof(p));
    if (head == NULL)
    {
        head = t;
        head->id = id;
        head->duracion = duracion;
        head->horallegada = horallegada;
        head->tama = tama;
        head->next = NULL;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = t;
    t->id = id;
    t->duracion = duracion;
    t->horallegada = horallegada;
    t->tama = tama;
    t->next = NULL;
}
void pop()
{
    p *t, *u;
    int i, d, h, t;
    if (head == NULL)
    {
        printf("Linked list is already empty.\n");
        return;
    }
    if (head->next == NULL)
    {
        i = head->id;
        d = head->duracion;
        h = head->horallegada;
        t = head->tama;

        free(head);
        head = NULL;
        printf("%d deleted from end successfully.\n", n);
        return;
    }
    t = head;
    while (t->next != NULL)
    {
        u = t;
        t = t->next;
    }
    i = t->id;
    d= t->duracion;
    h= t->horallegada;
    t= t->tama;
    u->next = NULL;
    free(t);
    printf("%d deleted from end successfully.\n", n);
}
