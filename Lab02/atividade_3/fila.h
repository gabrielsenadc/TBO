#ifndef fila_h
#define fila_h

typedef struct filaType filaType;

filaType * createFila();

void enqueue(filaType * fila, void * data);

void * dequeue(filaType * fila);

void freeFila(filaType * fila);

int empty(filaType * fila);

#endif