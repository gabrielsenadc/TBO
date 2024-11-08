#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    treeType * tree = createTree();

    int n = 1000000;
    srand(time(NULL));

    clock_t start, stop;
    start = clock();

    for(int i = 0; i < n; i++){
        tree = insertTree(tree, rand());
    }
    
    int h = height(tree);
    
    stop = clock();
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;

    //printTree(tree);
    printf("\nheight = %d\n", h);

    freeTree(tree);

    printf("tempo: %lfs\n", time_taken);
    return 0;
}