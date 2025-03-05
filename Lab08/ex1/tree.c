#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct treeType{
    int chave;
    int valor;
    treeType * left;
    treeType * right;
};

treeType * createTree(){
    return NULL;
}

treeType * createCell(int chave){
    treeType * tree = malloc(sizeof(treeType));
    tree->chave = chave;
    tree->left = NULL;
    tree->right = NULL;
    tree->valor = 0;
    return tree;
}

treeType * rotateRight(treeType * n){
    treeType *t = n->left;
    n->left = t->right;
    t->right = n;
    return t;
}

treeType * rotateLeft(treeType * n){
    treeType *t = n->right;
    n->right = t->left;
    t->left = n;
    return t;
}

treeType * insertTree(treeType * tree, int chave){
    if(tree == NULL) return createCell(chave);

    if(chave > tree->chave){
        tree->right = insertTree(tree->right, chave);
        tree = rotateLeft(tree);
    }
        
    if(chave < tree->chave){
        tree->left = insertTree(tree->left, chave);
        tree = rotateRight(tree);
    }

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

    printf("%d ", tree->chave);

    printf("l:");
    printTree(tree->left);
    printf(" r:");
    printTree(tree->right);
    printf(" ");
}

int height(treeType * tree){
    if(tree == NULL) return -1;

    int left = height(tree->left) + 1;
    int right = height(tree->right) + 1;

    return left > right ? left : right;
}