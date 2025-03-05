#ifndef tree_h
#define tree_h

typedef struct treeType treeType;

treeType * createTree();

treeType * insertTree(treeType * tree, int n);

treeType * balanceamento(treeType * n);

treeType * freeTree(treeType * tree);

void printTree(treeType * tree);

int height(treeType * tree);

#endif