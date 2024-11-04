#include <stdio.h>
#include <stdlib.h>
#include "crivoBit.h"
#include "bitmap.h"

typedef struct num numType;

struct list{
    bitmap *num;
    long int size;
};


listType * createList(int size){
    listType * list = malloc(sizeof(listType));

    list->num = bitmapInit(size + 1);
    list->size = size;

    bitmapSetLength(list->num, size);

    return list;
}

void execute(listType * list){
    for(long int n = 2; n < list->size; n++){
        if(bitmapGetBit(list->num, n) == 1) continue;
        for(long int i = n + 1; i < list->size; i++){
            if(i % n == 0) bitmapSetBit(list->num, i, 1);
        }
    }
}

void printList(listType * list){
    for(long int i = 0; i < list->size; i++){
        if(bitmapGetBit(list->num, i) == 0) printf("%ld ", i + 2);
    }
    printf("\n");
}

void freeList(listType * list){
    bitmapLibera(list->num);
    free(list);
}