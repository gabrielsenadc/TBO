#include <stdio.h>
#include <stdlib.h>
#include "crivoChar.h"

typedef struct num numType;

struct list{
    char *num;
    long int size;
};


listType * createList(int size){
    listType * list = malloc(sizeof(listType));

    list->num = calloc(size - 1, sizeof(char));
    list->size = size - 1;

    for(long int i = 0; i < list->size; i++){
        list->num[i] = '1';
    }

    return list;
}

void execute(listType * list){
    for(long int n = 0; n < list->size; n++){
        if(list->num[n] == '0') continue;
        for(long int i = n + 1; i < list->size; i++){
            if((i + 2) % (n + 2) == 0) list->num[i] = '0';
        }
    }
}

void printList(listType * list){
    for(long int i = 0; i < list->size; i++){
        if(list->num[i] == '1') printf("%ld ", i + 2);
    }
    printf("\n");
}

void freeList(listType * list){
    free(list->num);
    free(list);
}