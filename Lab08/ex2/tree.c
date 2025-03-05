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

treeType * insertTree(treeType * tree, int chave){
    if(tree == NULL) return createCell(chave);

    tree->size++;

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

treeType * particionamento(treeType * n, int k){
    int t = getSize(n->left);

    if(t > k){
        n->left = particionamento(n->left, k);
        n = rotateRight(n);
    }
    if(t < k){
        n->right = particionamento(n->right, k-t-1);
        n = rotateLeft(n);
    }

    return n;
}

treeType * balanceamento(treeType * n){
    if(getSize(n) < 2) return n;

    n = particionamento(n, getSize(n)/2);
    n->left = balanceamento(n->left);
    n->right = balanceamento(n->right);

    return n;
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