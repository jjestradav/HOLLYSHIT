#define MAX 75
void read_config(FILE *file, char *filename, char* arg[])
{
    file = fopen(filename, "r");
    char str[MAX];
    char s[MAX];
    int i = 0;
    while (!feof(file))
    {  
        fscanf(file, "%s", s);
        arg[i] = s;
        i++;
         printf("%s", s);
         printf("\n");
    }
    fclose(file);
}

void read_gen(FILE *file, char *filename, int *arreglo)
{
}