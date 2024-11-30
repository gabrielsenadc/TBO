#include <stdio.h>
#include "item.h"

void sort(Item *a, int lo, int hi){
    for(int i = lo; i < hi; i++){
        Item menor = i;
        for(int j = i + 1; j < hi; j++){
            if(less(a[j], a[menor])) menor = j;
        }
        exch(a[menor], a[i]);
    }
}