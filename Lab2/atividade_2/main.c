#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <time.h>

int main(){
    treeType * tree = createTree();

    int n = 10000000;
    srand(time(NULL));

    for(int i = 0; i < n; i++){
        tree = insertTree(tree, rand());
    }

    clock_t start_rec = clock ();

    rec_preorder(tree, printTree);
    printf("\n");

    clock_t end_rec = clock ();

    clock_t start_iter = clock ();
    
    iter_preorder(tree, printTree);
    printf("\n");

    clock_t end_iter = clock ();
    
    double rec_seconds = (( double ) end_rec - start_rec ) / CLOCKS_PER_SEC ;
    double iter_seconds = (( double ) end_iter - start_iter ) / CLOCKS_PER_SEC ;
    printf ("tempo rec: %lfs \n" , rec_seconds);
    printf ("tempo iter: %lfs \n" , iter_seconds);

    freeTree(tree);
    return 0;
}