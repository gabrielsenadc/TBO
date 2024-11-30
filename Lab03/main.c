#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include <time.h>

extern void sort(Item *a, int lo, int hi);

double read_sort_print(char * path, int size){
    FILE * file = fopen(path, "r");
    Item * vet = calloc(size, sizeof(int));
    for(int i = 0; i < size; i++) fscanf(file, "%d", &vet[i]);

    clock_t start = clock ();
    sort(vet, 0, size);
    clock_t end = clock ();

    for(int i = 0; i < size; i++) printf("%d ", vet[i]);

    free(vet);
    fclose(file);
    return (( double ) end - (double) start ) / CLOCKS_PER_SEC ;
}

int main(){
    double time = read_sort_print("in/unif_rand/1Kunif_rand.txt", 1000);

    printf("\ntime: %lf\n",time);
    return 0;
}