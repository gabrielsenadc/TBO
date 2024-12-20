#include <stdlib.h>
#include "item.h"

//merge bottom-up com cutoff e skip

#define SZ2 (sz+sz)
#define MIN(X,Y) ((X < Y) ? (X) : (Y))
#define CUTOFF 9

void insertion_sort(Item *a, int lo, int hi){
    for(int i = lo; i < hi; i++){
        for(int j = i; j > lo && less(a[j], a[j - 1]); j--) 
            exch(a[j - 1], a[j]);
    }
}

void merge(Item *a, Item *aux, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; k++) aux[k] = a[k];

    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++) { 
        if (i > mid) a[k] = aux[j++];
        else if (j > hi) a[k] = aux[i++];
        else if (less(aux[j], aux[i])) a[k] = aux[j++];
        else a[k] = aux[i++];
    }
}

void sort(Item *a, int lo, int hi) {
    int N = (hi - lo) + 1;
    int y = N - 1;
    Item *aux = malloc(N * sizeof(Item));
    
    for (int sz = 1; sz < N; sz = SZ2) {
        for (int lo = 0; lo < N-sz; lo += SZ2) {
            int x = lo + SZ2 - 1;
            if (less(a[lo+sz-1], a[lo+sz])) continue;
            if (x <= lo + CUTOFF - 1) insertion_sort(a, lo, MIN(x,y));
            else merge(a, aux, lo, lo+sz-1, MIN(x,y));
        }
    }
    free(aux);
}