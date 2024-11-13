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
    printf("%d ", tree->n);
}


void preorder(treeType * tree, void (*visit)(treeType*)){
    if(tree == NULL) return;

    visit(tree);

    preorder(tree->left, visit);
    preorder(tree->right, visit);
}

void postorder(treeType * tree, void (*visit)(treeType*)){
    if(tree == NULL) return;

    postorder(tree->left, visit);
    postorder(tree->right, visit);

    visit(tree);
}

void inorder(treeType * tree, void (*visit)(treeType*)){
    if(tree == NULL) return;

    inorder(tree->left, visit);
    visit(tree);
    inorder(tree->right, visit);
}