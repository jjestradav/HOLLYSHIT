#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "read.c"
int main(){
        char* arg[4];
        FILE *fp;
        char *filename = "config.txt";
        read_config(fp, filename, arg);
        for(int i=0; i< 4; i++){
            printf("\n");
            printf("%s", arg[i]); 
            printf("\n");
        }
    return 0;
}