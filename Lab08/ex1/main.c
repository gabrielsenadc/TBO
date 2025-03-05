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
    printf("height = %d\n", h);

    /*tree = insertTree(tree, 4);
    tree = insertTree(tree, 2);
    tree = insertTree(tree, 3);

    printTree(tree);
    printf("\n");*/

    freeTree(tree);
    
    return 0;
}