#include <time.h>
long double random_R(){
    time_t t;
    srand((unsigned)time(&t));
    return ((double)rand()/RAND_MAX);
}

int ramdom_Between(int min, int  max){
    time_t t;
    srand((unsigned)time(&t));
    return (int)(rand() % (max - min + 1)) + min;
}