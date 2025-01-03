#include <stdlib.h>
#include "item.h"
#include "insertion_sort.c"

//quick top-down com CUTOFF

#define CUTOFF 9

int partition(Item *a, int lo, int hi) {
    int i = lo, j = hi+1;
    Item v = a[lo];

    while(1){
        while (less(a[++i], v)) if (i == hi) break;
        while (less(v, a[--j])) if (j == lo) break;

        if (i >= j) break;
        exch(a[i], a[j]);
    }

    exch(a[lo], a[j]);
    return j;
}

void sort(Item *a, int lo, int hi){
    if (hi <= lo + CUTOFF - 1) {
        insertion_sort(a, lo, hi);
        return;
    }
    
    int j = partition(a, lo, hi);

    sort(a, lo, j - 1);
    sort(a, j + 1, hi);
}