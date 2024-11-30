#include <stdio.h>
#include "item.h"

void sort(Item *a, int lo, int hi){
    for(int i = lo; i < hi - 1; i++){
        int troca = 0;
        for(int j = lo; j < hi - 1 - i; j++){
            if(less(a[j + 1], a[j])) troca = 1;
                
            compexch(a[j], a[j + 1]);
        }
        if(!troca) break;
    }
}