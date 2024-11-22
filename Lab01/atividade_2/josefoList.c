#include <stdio.h>
#include <stdlib.h>
#include "josefo.h"

typedef struct cellType cellType;

struct circleType{
    cellType *first;
    cellType *last;
    int m;
    int n;
};

struct cellType{
    cellType *next;
    int n;
};

void addCell(circleType * circle, int n){
    cellType * cell = malloc(sizeof(cellType));

    cell->n = n;

    if(n == 1) circle->first = circle->last = cell;
    

    cell->next = circle->first;
    circle->last->next = cell;

    circle->last = cell;
}

cellType * removeCell(cellType *prev, cellType * cell, int * n){
    (*n)++;
    if(*n <= 5) return removeCell(cell, cell->next, n);
    
    printf("%d ", cell->n);

    prev->next = cell->next;
    
    cellType * aux = cell->next;
    if(cell->next == cell) aux = NULL;
    free(cell);
    return aux;
    
}

circleType * createCircle(int n, int m){
    circleType * circle = malloc(sizeof(circleType));

    circle->first = NULL;
    circle->m = m;
    circle->n = n;

    for(int i = 1; i <= n; i++) {
        addCell(circle, i);
    }

    return circle;
}

void execute(circleType * circle){
    while(circle->first != NULL){
        int n = 1;

        circle->first = removeCell(NULL, circle->first, &n);
    }
    printf("\n");
}

void freeCircle(circleType * circle){
    free(circle);
}