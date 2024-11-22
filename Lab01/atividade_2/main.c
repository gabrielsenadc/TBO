#include <stdio.h>
#include "josefo.h"
#include <time.h>

int main(){
    clock_t start, stop;
    start = clock();
    circleType * circle = createCircle(9, 5);

    execute(circle);
    stop = clock();
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;

    freeCircle(circle);
    printf("tempo: %lfs\n", time_taken);

    return 0;
}