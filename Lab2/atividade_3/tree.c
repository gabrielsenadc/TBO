#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "fila.h"

struct treeType{
    int n;
    treeType * left;
    treeType * right;
};

treeType * createTree(){
    return NULL;
}

treeType * createCell(int n){
    treeType * tree = malloc(sizeof(treeType));
    tree->n = n;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

treeType * insertTree(treeType * tree, int n){
    if(tree == NULL) return createCell(n);

    if(n > tree->n) tree->right = insertTree(tree->right, n);
    if(n <= tree->n) tree->left = insertTree(tree->left, n);

    return tree;
}

treeType * freeTree(treeType * tree){
    if(tree == NULL) return NULL;

    freeTree(tree->left);
    freeTree(tree->right);

    free(tree);
    return NULL;
}

void printTree(treeType * tree){
    printf("%d ", tree->n);
}

void BFS(treeType * tree, void (*visit)(treeType*)){
    filaType * fila = createFila();

    enqueue(fila, tree);

    while(!empty(fila)){
        tree = dequeue(fila);
        visit(tree);
        if(tree->left) enqueue(fila, tree->left);
        if(tree->right) enqueue(fila, tree->right);
    }

    freeFila(fila);
}
