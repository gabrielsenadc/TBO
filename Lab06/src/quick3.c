#include <stdlib.h>
#include "item.h"

//quick top-down com mediana

int get_bigger(Item *a, int i, int j, int k){
    if(a[i] > a[j] && a[i] > a[k]) return i;
    else if(a[j] > a[k]) return j;
    else return k;
}

int median_of_3(Item *a, int lo, int hi){
    int mid = (lo + hi) / 2;

    int bigger = get_bigger(a, lo, mid, hi);

    if(bigger == lo) return a[mid] > a[hi] ? mid : hi;
    else if(bigger == mid) return a[lo] > a[hi] ? lo : hi;
    else return a[mid] > a[lo] ? mid : lo;
        
}

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
    if(hi <= lo) return;

    int median = median_of_3(a, lo, hi);
    exch(a[lo], a[median]);
    
    int j = partition(a, lo, hi);

    sort(a, lo, j - 1);
    sort(a, j + 1, hi);
}