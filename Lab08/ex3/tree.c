#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct treeType{
    int chave;
    int valor;
    int size;
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
    tree->size = 1;
    return tree;
}

int getSize(treeType * tree){
    if(tree == NULL) return 0;
    return tree->size;
}

treeType * rotateRight(treeType * n){
    treeType *t = n->left;
    n->left = t->right;
    t->right = n;

    t->size = getSize(n);
    n->size = 1 + getSize(n->right) + getSize(n->left);

    return t;
}

treeType * rotateLeft(treeType * n){
    treeType *t = n->right;
    n->right = t->left;
    t->left = n;

    t->size = getSize(n);
    n->size = 1 + getSize(n->right) + getSize(n->left);

    return t;
}

treeType * insertRootTree(treeType * tree, int chave){
    if(tree == NULL) return createCell(chave);

    tree->size++;

    if(chave > tree->chave){
        tree->right = insertRootTree(tree->right, chave);
        tree = rotateLeft(tree);
    }
        
    if(chave < tree->chave){
        tree->left = insertRootTree(tree->left, chave);
        tree = rotateRight(tree);
    }

    return tree;
}

treeType * insertRandomTree(treeType * tree, int chave){
    if(tree == NULL) return createCell(chave);
    double prob = (double) RAND_MAX / (getSize(tree) + 1);

    tree->size++;

    if(rand() < prob) return insertRootTree(tree, chave);
    
    if(chave > tree->chave) tree->right = insertRandomTree(tree->right, chave);
    if(chave < tree->chave) tree->left = insertRandomTree(tree->left, chave);

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

    printf("(%d, size:%d ", tree->chave, tree->size);

    printf("l:");
    printTree(tree->left);
    printf(" r:");
    printTree(tree->right);
    printf(")");
}

int height(treeType * tree){
    if(tree == NULL) return -1;

    int left = height(tree->left) + 1;
    int right = height(tree->right) + 1;

    return left > right ? left : right;
}