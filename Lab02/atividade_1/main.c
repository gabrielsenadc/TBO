#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    treeType * tree = createTree();

    int n = 1000000;
    srand(time(NULL));

    for(int i = 0; i < n; i++){
        tree = insertTree(tree, rand());
    }
    
    int h = height(tree);

    //printTree(tree);
    printf("\nheight = %d\n", h);

    freeTree(tree);
    
    return 0;
}