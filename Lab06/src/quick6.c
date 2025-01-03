#include <stdlib.h>
#include "item.h"
#include "insertion_sort.c"
#define push2(A, B) push(B); push(A)

//quick bottom-up com mediana e CUTOFF

#define CUTOFF 9

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

//Stack
int *stack = NULL;
int maxSize = 0;
int top = -1;

void stack_init(int max) {
    stack = malloc(max * sizeof(int));
    top = -1;
    maxSize = max;
}

int stack_empty() {
    return top == -1;
}

void push(int item) {
    if (top >= maxSize - 1) {
        exit(EXIT_FAILURE);
    }

    stack[++top] = item;
}

int pop() {
    if (stack_empty()) {
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

//Quick Sort
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

void sort(Item *a, int lo, int hi) {
    stack_init(hi - lo + 1);
    push2(lo, hi);

    while(!stack_empty()) {
        lo = pop(); 
        hi = pop();
        if (hi <= lo + CUTOFF - 1) {
            insertion_sort(a, lo, hi);
            continue;;
        }

        int median = median_of_3(a, lo, hi);
        exch(a[lo], a[median]);

        int i = partition(a, lo, hi);

        if (i-lo > hi-i) {
            push2(lo, i-1);
            push2(i+1, hi);
        } else {
            push2(i+1, hi);
            push2(lo, i-1);
        }
    }

    free(stack);
}
