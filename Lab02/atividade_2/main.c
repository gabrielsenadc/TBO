#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <time.h>

double time_rec_preorder(treeType * tree){
    clock_t start = clock ();
    rec_preorder(tree, printTree);
    clock_t end = clock ();

    return (( double ) end - (double) start ) / CLOCKS_PER_SEC ;
}

double time_rec_postorder(treeType * tree){
    clock_t start = clock ();
    rec_postorder(tree, printTree);
    clock_t end = clock ();

    return (( double ) end - (double) start ) / CLOCKS_PER_SEC ;
}

double time_rec_inorder(treeType * tree){
    clock_t start = clock ();
    rec_inorder(tree, printTree);
    clock_t end = clock ();

    return (( double ) end - (double) start ) / CLOCKS_PER_SEC ;
}

double time_iter_preorder(treeType * tree){
    clock_t start = clock ();
    iter_preorder(tree, printTree);
    clock_t end = clock ();

    return (( double ) end - (double) start ) / CLOCKS_PER_SEC ;
}

double time_iter_postorder(treeType * tree){
    clock_t start = clock ();
    iter_postorder(tree, printTree);
    clock_t end = clock ();

    return (( double ) end - (double) start ) / CLOCKS_PER_SEC ;
}

double time_iter_inorder(treeType * tree){
    clock_t start = clock ();
    iter_inorder(tree, printTree);
    clock_t end = clock ();

    return (( double ) end - (double) start ) / CLOCKS_PER_SEC ;
}



int main(){
    treeType * tree = createTree();

    int n = 10000000;
    srand(time(NULL));

    for(int i = 0; i < n; i++){
        tree = insertTree(tree, rand());
    }

    double seconds_rec_pre = time_rec_preorder(tree);
    double seconds_rec_in = time_rec_inorder(tree);
    double seconds_rec_post = time_rec_postorder(tree);
    double seconds_iter_pre = time_iter_preorder(tree);
    double seconds_iter_in = time_iter_inorder(tree);
    double seconds_iter_post = time_iter_postorder(tree);

    printf ("\ntempo rec_pre: %lfs \n" , seconds_rec_pre);
    printf ("tempo rec_in: %lfs \n" , seconds_rec_in);
    printf ("tempo rec_post: %lfs \n" , seconds_rec_post);
    printf ("tempo iter_pre: %lfs \n" , seconds_iter_pre);
    printf ("tempo iter_in: %lfs \n" , seconds_iter_in);
    printf ("tempo iter_post: %lfs \n" , seconds_iter_post);

    freeTree(tree);
    return 0;
}