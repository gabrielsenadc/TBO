#include <stdio.h>
#include <stdlib.h>
#include "crivo.h"
#include <time.h>

int main(){
    clock_t start, stop;
    start = clock();
    listType * list = createList(100);

    execute(list);
    stop = clock();
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;

    printList(list);

    freeList(list);
    
    printf("tempo: %lfs\n", time_taken);
    return 0;
}