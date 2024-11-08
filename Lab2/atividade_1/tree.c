#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

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
    if(tree == NULL) return;

    printTree(tree->left);
    printf("%d ", tree->n);
    printTree(tree->right);
}

int height(treeType * tree){
    if(tree == NULL) return -1;

    int left = height(tree->left) + 1;
    int right = height(tree->right) + 1;

    return left > right ? left : right;
}