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

treeType * insertTree(treeType * tree, int chave){
    if(tree == NULL) return createCell(chave);

    if(chave > tree->chave) tree->right = insertTree(tree->right, chave);
    if(chave < tree->chave) tree->left = insertTree(tree->left, chave);

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
    printf("%d ", tree->chave);
    printTree(tree->right);
}

int height(treeType * tree){
    if(tree == NULL) return -1;

    int left = height(tree->left) + 1;
    int right = height(tree->right) + 1;

    return left > right ? left : right;
}