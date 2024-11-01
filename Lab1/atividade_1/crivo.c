#include <stdio.h>
#include <stdlib.h>
#include "crivo.h"

typedef struct num numType;

struct list{
    numType **array;
    int size;
};

struct num {
    int n;
    int primo;
};

numType * createNum(int n){
    numType * num = malloc(sizeof(numType));

    num->n = n;
    num->primo = 1;

    return num;
}

int ehMultiplo(numType * n1, numType * n2){
    return !(n2->n % n1->n);
}

void setPrimo(numType * n){
    n->primo = 0;
}

int getPrimo(numType * n){
    return n->primo;
}

void printNum(numType * n){
    printf("%d ", n->n);
}

listType * createList(int size){
    listType * list = malloc(sizeof(listType));

    list->array = calloc(size - 1, sizeof(numType*));
    list->size = size - 1;

    for(int i = 2; i <= size; i++){
        list->array[i - 2] = createNum(i);
    }

    return list;
}

void execute(listType * list){
    int n = 0;
    while(n < list->size){
        for(int i = n + 1; i < list->size; i++){
            if(ehMultiplo(list->array[n], list->array[i])) setPrimo(list->array[i]);
        }
        n++;
    }
}

void printList(listType * list){
    for(int i = 0; i < list->size; i++){
        if(getPrimo(list->array[i])) printNum(list->array[i]);
    }
    printf("\n");
}