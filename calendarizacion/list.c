#ifndef LIST_C
#define LIST_C
#include <stdio.h>
#include <stdlib.h>

typedef struct proceso p;
void push(p **head, int id, int duracion, int horallegada, int tama);
void pop(p **head);
void dequeue(p **head);
void print_list(p **head);
int isEmpty();
p* last(p**head);

typedef struct proceso
{
    int id;
    int duracion;
    int horallegada;
    int tama;
    struct proceso *next;
} p;

int cant;
void push(p **head, int id, int horallegada, int duracion, int tama)
{
    p *current = *head;
    p *temp = (p *)malloc(sizeof(p));
    temp->id = id;
    temp->horallegada = horallegada;
    temp->duracion = duracion;
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
void pop(p **head)
{

    if((*head) == NULL)
        return;

    p *front = (*head);
    (*head) = (*head)->next;
    front->next = NULL;

    
    if(front == (*head))
        (*head)= NULL;

    free(front);
 




    // p *t, *u;
    // int i, d, h, tam;
    // if (head == NULL)
    // {
    //     printf("Linked list is already empty.\n");
    //     return;
    // }
    // if ((*head)->next == NULL)
    // {
    //     i = (*head)->id;
    //     d = (*head)->duracion;
    //     h = (*head)->horallegada;
    //     tam = (*head)->tama;

    //     free(*head);
    //     head = NULL;
    //     cant--;
    //     // printf("%d deleted from end successfully.\n", n);
    //     return;
    // }
    // t = *head;
    // while (t->next != NULL)
    // {
    //     u = t;
    //     t = t->next;
    // }
    // i = t->id;
    // d = t->duracion;
    // h = t->horallegada;
    // tam = t->tama;
    // u->next = NULL;
    // free(t);
    // cant--;
    // // printf("%d deleted from end successfully.\n", n);
}
void dequeue(p **head){ 
    if(head==NULL){
        printf("vacia");
        return;
    }
    p* t;
    int a , b ,c ,d;
    t=(*head);
    (*head)=(*head)->next;
    a = t->id;
    b= t->duracion;
    c= t->horallegada;
    d= t->tama;
    free(t);
    t=NULL;

}
void print_list(p **head)
{
    p *current = *head;

printf("\n *********En Cola:**********\n");
    while (current != NULL)
    {
        printf("%d, %d, %d, %d\n", current->id, current->horallegada, current->duracion,
               current->tama);
        current = current->next;
    }
    printf("\n ***********************\n");
}

int isEmpty(p** head){
    return((*head)==NULL ? 0:1);
}

p* last(p**head){
     p* current=(*head);
     while(current->next !=NULL)
        current = current->next;

        return current;
}




#endif