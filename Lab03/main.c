#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include <time.h>

extern void sort(Item *a, int lo, int hi);

double read_sort_print(char * path, int size){
    FILE * file = fopen(path, "r");
    int n = 0;
    int * vet = calloc(n, sizeof(int));
    for(int i = 0; i < size; i++){
        fscanf(file, "%d", &n);
        vet[i] = n;
    }

    clock_t start = clock ();
    sort(vet, 0, size);
    clock_t end = clock ();

    for(int i = 0; i < size; i++){
        printf("%d ", vet[i]);
    }

    free(vet);
    fclose(file);
    printf("\n#######################################\n");
    return (( double ) end - (double) start ) / CLOCKS_PER_SEC ;
}

int main(){
    int n = 1000;
    
    /*double unif_rand_time = read_sort_print("in/unif_rand/1Kunif_rand.txt", 1000);
    double nearly_sorted_time = read_sort_print("in/nearly_sorted/1Knearly_sorted.txt", 1000);*/
    double sorted_time = read_sort_print("in/sorted/1Ksorted.txt", 1000);
    /*double reverse_sorted_time = read_sort_print("in/reverse_sorted/1Kreverse_sorted.txt", 1000);

    printf("\nunif_rand_time: %lf\n", unif_rand_time);
    printf("nearly_sorted_time: %lf\n", nearly_sorted_time);
    printf("sorted_time: %lf\n", sorted_time);
    printf("reverse_sorted_time: %lf\n", reverse_sorted_time);*/
    return 0;
}