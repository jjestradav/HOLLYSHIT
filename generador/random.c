#include <time.h>
void initialize(){
time_t t;
srand((unsigned)time(&t));
}

long double random_R(){
    return ((double)rand()/RAND_MAX);
}

int ramdom_Between(int min, int  max){
    return (int)(rand() % (max - min + 1)) + min;
}