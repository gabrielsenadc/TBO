#include <stdio.h>
#include <stdlib.h>
#include "josefo.h"

struct circleType{
    char *array;
    int m;
    int n;
};


circleType * createCircle(int n, int m){
    circleType * circle = malloc(sizeof(circleType));

    circle->array = calloc(n, sizeof(char));

    circle->m = m;
    circle->n = n;

    return circle;
}

void execute(circleType * circle){
    int current = 0;
    for(int i = 0; i < circle->n; i++){
        int j = 0;
        while(1){
            if(circle->array[current] == 0) j = (j + 1) % circle->n;
            if(j >= circle->m) break;
            current = (current + 1) % circle->n;
        }
        printf("%d ", current + 1);
        circle->array[current] = 1;
        current = (current + 1) % circle->n;
    }
    printf("\n");

}

void freeCircle(circleType * circle){
    free(circle->array);
    free(circle);
}