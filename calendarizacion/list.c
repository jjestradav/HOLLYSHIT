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
p* popLpos(p** head,int pos);
int retornaPosBF(p** head, int tiempo);
int retornaPosWF(p** head, int tiempo);
p* retornaPosL(p** head, int pos);
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
    t=(*head);
    (*head)=(*head)->next;
    t->next=NULL;
   
    if(t==(*head))
    (*head)=NULL;
   
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

p* popLpos(p** head,int pos){

    p * current = (*head);
    p* temp_node = NULL;

    if (pos == 0) {
        
        
        (*head) = (*head)->next;
        current->next = NULL;

        if(current==(*head))
            (*head)=NULL;

        return current;
    }

    for (int i = 0; i < pos-1; i++) {
        if (current->next == NULL) {
            return NULL;
        }
        current = current->next;
    }

    temp_node = current->next;
    current->next = temp_node->next;
    temp_node->next= NULL;
    return temp_node;

}

int retornaPosBF(p** head,int tiempo){

int pos=0;
int aux1=0;
if((*head)->horallegada <= tiempo)
    aux1=(*head)->tama;
    else 
    aux1 = -1;

p* current=(*head);
while(current != NULL){
    if(aux1 == -1){
        if(current->horallegada <= tiempo)
            aux1 = current->tama;
    }
    else
    {
      if(current->tama < aux1 && current->horallegada <= tiempo)
        aux1=current->tama;
    }

        current=current->next;
}
current = (*head);
while(current != NULL){
    if(current->tama == aux1){
        return pos;
    }
    current = current->next;
    pos++;
}
 return -1;
}
int retornaPosWF(p** head,int tiempo){

int pos=0;
int aux1=0;
if((*head)->horallegada <= tiempo)
    aux1=(*head)->tama;
    else 
    aux1 = -1;

p* current=(*head);
while(current != NULL){
    if(aux1 == -1){
        if(current->horallegada <= tiempo)
            aux1 = current->tama;
    }
    else
    {
      if(current->tama > aux1 && current->horallegada <= tiempo)
        aux1=current->tama;
    }

        current=current->next;
}
current = (*head);
while(current != NULL){
    if(current->tama == aux1){
        return pos;
    }
    current = current->next;
    pos++;
}
 return -1;
}
p* retornaPosL(p** head, int pos){
    p* current = (*head);
    int cont=0;
    while(current != NULL){
        if( cont == pos)
            return current;
     current = current->next;
     cont++;
    }
    return NULL;
}

#endif