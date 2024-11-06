#include <stdio.h>
#include <stdlib.h>
#include "crivo.h"

typedef struct num numType;

struct list{
    char *num;
    int size;
};


listType * createList(int size){
    listType * list = malloc(sizeof(listType));

    list->num = calloc(size + 1, sizeof(char));
    list->size = size + 1;

    return list;
}



void execute(listType * list){
    for(int n = 2; n < list->size; n++){
        if(list->num[n] == 1) continue;
        for(int i = n * 2; i < list->size; i += n){
            list->num[i] = 1;
        }
    }
}

void printList(listType * list){
    for(int i = 2; i < list->size; i++){
        if(list->num[i] == 0) printf("%d ", i);
    }
    printf("\n");
}

void freeList(listType * list){
    free(list->num);
    free(list);
}