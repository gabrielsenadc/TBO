#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    treeType * tree = createTree();

    tree = insertTree(tree, 4);
    tree = insertTree(tree, 2);
    tree = insertTree(tree, 5);
    tree = insertTree(tree, 3);
    tree = insertTree(tree, 1);
    tree = insertTree(tree, 6);
    

    //preorder(tree, printTree);
    //printf("\n");

    //postorder(tree, printTree);
    //printf("\n");

    inorder(tree, printTree);
    printf("\n");

    freeTree(tree);
    return 0;
}