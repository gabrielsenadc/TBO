#include <stdio.h>
#include "item.h"

void sort(Item *a, int lo, int hi){
    int swaped = 1;
    while(swaped){
        swaped = 0;
        for(int i = 0, j = hi - 1; i <= j; i++, j--){
            if(less(a[i + 1], a[i])) swaped = 1;
            compexch(a[i], a[i + 1]);

            if(less(a[j], a[j - 1])) swaped = 1;
            compexch(a[j - 1], a[j]);
        }
    }
    
}