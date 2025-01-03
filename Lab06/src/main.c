#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include <time.h>
#include <string.h>

extern void sort(Item *a, int lo, int hi);

double read_sort_print(char * path, int size){
    FILE * file = fopen(path, "r");
    if(!file){
        printf("Arquivo inexistente\n");
        exit(1);
    }
    
    Item * vet = calloc(size, sizeof(int));
    for(int i = 0; i < size; i++) fscanf(file, "%d", &vet[i]);

    clock_t start = clock ();
    sort(vet, 0, size - 1);
    clock_t end = clock ();

    for(int i = 0; i < size; i++) printf("%d ", vet[i]);

    free(vet);
    fclose(file);
    return (( double ) end - (double) start ) / CLOCKS_PER_SEC ;
}

int main(int argc, char *argv[]){
    if(argc <= 1){
        printf("Sem parametros!\n");
        return 1;
    }

    int n = 0;
    if(!strcmp(argv[1], "1K")) n = 1000;
    if(!strcmp(argv[1], "100K")) n = 100000;
    if(!strcmp(argv[1], "1M")) n = 1000000;
    if(!strcmp(argv[1], "10M")) n = 10000000;

    char path[100];
    sprintf(path, "../input/%s/%d.txt", argv[2], n);

    double time = read_sort_print(path, n);

    printf("\ntime: %lf\n",time);
    return 0;
}