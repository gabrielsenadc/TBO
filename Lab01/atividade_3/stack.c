#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct cellType cellType;

struct stackType{
    cellType * top;
};

struct cellType{
    void *data;
    cellType *next;
};

stackType * createStack(){
    stackType * stack = malloc(sizeof(stackType));

    stack->top = NULL;

    return stack;
}

void push(stackType * stack, void * data){
    cellType * cell = malloc(sizeof(cellType));

    cell->data = data;
    cell->next = stack->top;

    stack->top = cell;
}

void * pop(stackType * stack){
    if(stack->top == NULL) return NULL;
    cellType * aux = stack->top;

    stack->top = aux->next;

    void * data = aux->data;
    free(aux);

    return data;
}

void freeStack(stackType * stack){
    free(stack);
}