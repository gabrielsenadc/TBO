#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    treeType * tree = createTree();

    int n = 1000000;

    for(int i = 0; i < n; i++){
        tree = insertRandomTree(tree, i);
    }
    
    int h = height(tree);
    printf("height = %d\n", h);

    freeTree(tree);
    
    return 0;
}