#include <stdlib.h>
#include "item.h"
#define push2(A, B) push(B); push(A)

//quick bottom-up original

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
        if (hi <= lo) continue;

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
