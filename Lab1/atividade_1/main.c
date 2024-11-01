#include <stdio.h>
#include <stdlib.h>
#include "crivo.h"

int main(){
    listType * list = createList(23);

    execute(list);

    printList(list);

    return 0;
}