#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct cellType cellType;

struct filaType{
    cellType * in;
    cellType * out;
};

struct cellType{
    void *data;
    cellType *next;
};

filaType * createFila(){
    filaType * fila = malloc(sizeof(filaType));

    fila->in = fila->out = NULL;

    return fila;
}

void enqueue(filaType * fila, void * data){
    cellType * cell = malloc(sizeof(cellType));

    cell->data = data;
    cell->next = NULL;
    if(!fila->out) fila->out = cell;
    if(fila->in) fila->in->next = cell;

    fila->in = cell;
}

void * dequeue(filaType * fila){
    if(fila->out == NULL) return NULL;
    cellType * aux = fila->out;

    fila->out = aux->next;
    if(fila->out == NULL) fila->in = NULL;

    void * data = aux->data;
    free(aux);

    return data;
}

void freeFila(filaType * fila){
    free(fila);
}

int empty(filaType * fila){
    return !fila->out;
}
