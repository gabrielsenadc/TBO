#ifndef stack_h
#define stack_h

typedef struct stackType stackType;

stackType * createStack();

void push(stackType * stack, void * data);

void * pop(stackType * stack);

void freeStack(stackType * stack);

int empty(stackType * stack);

#endif