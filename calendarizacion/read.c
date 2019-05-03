#include"list.c"
#include<string.h>
#define MAX 75
void read_config(FILE *file, char *filename, char *arg[])
{
    file = fopen(filename, "r");
    char s[MAX];
    int i = 0;
    while (!feof(file))
    {
        fgets(s, MAX, file);
        char *aux = calloc(sizeof(char), 15);
        for (int j = 0; j < MAX; j++)
        {
            if (s[j] == ' ')
                break;
            else
                aux[j] = s[j];
        }
        arg[i++] = aux;
    }
    fclose(file);
}

void read_gen(FILE *file, char *filename, p**head)
{
    file = fopen(filename, "r");
    char s[MAX];
    int i = 0;
    int array[4];
    int cant=0;
    while (!feof(file))
    {
        
        char aux[6];
        fscanf(file,"%s",aux);
        if(cant==3){
            array[3]=atoi(aux);
             push(head, array[0],array[1],array[2],array[3]);
            cant=0;
        }
        else
        array[cant++]=atoi(aux);
        
       
    }
    fclose(file);
}

