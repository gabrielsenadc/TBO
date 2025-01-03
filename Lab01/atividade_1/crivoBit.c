#include <stdio.h>
#include <stdlib.h>
#include "crivo.h"
#include "bitmap.h"

typedef struct num numType;

struct list{
    bitmap *num;
    long int size;
};


listType * createList(int size){
    listType * list = malloc(sizeof(listType));

    list->num = bitmapInit(size + 1);
    list->size = size + 1;

    bitmapSetLength(list->num, size + 1);

    return list;
}

void execute(listType * list){
    for(int n = 2; n < list->size; n++){
        if(bitmapGetBit(list->num, n) == 1) continue;
        if(n * n > list->size) break;
        for(int i = n * 2; i < list->size; i += n){
            bitmapSetBit(list->num, i, 1);
        }
    }
}

void printList(listType * list){
    for(int i = 2; i < list->size; i++){
        if(bitmapGetBit(list->num, i) == 0) printf("%d ", i);
    }
    printf("\n");
}

void freeList(listType * list){
    bitmapLibera(list->num);
    free(list);
}