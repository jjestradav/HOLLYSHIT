#include <string.h>
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

void read_gen(FILE *file, char *filename, int *arreglo)
{
    file = fopen(filename, "r");
    char s[MAX];
    int i = 0;
    while (!feof(file))
    {
        fgets(s, MAX, file);
        if (s[i] == "\t")
            break;
        else
            arreglo[i] = atoi(s);
    }
    fclose(file);
}