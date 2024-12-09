#include <stdio.h>
#include "PQ.h"

int main(){
    PQ * pq = PQ_create(10);

    PQ_insert(pq, 2);
    PQ_insert(pq, 1);
    PQ_insert(pq, 3);

    while(!PQ_is_empty(pq)){
        printf("%d\n", PQ_delmin(pq));
    }

    return 0;
}