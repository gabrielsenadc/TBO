#ifndef tree_h
#define tree_h

typedef struct treeType treeType;

treeType * createTree();

treeType * insertTree(treeType * tree, int n);

treeType * freeTree(treeType * tree);

void printTree(treeType * tree);

void preorder(treeType * tree, void (*visit)(treeType*));
void postorder(treeType * tree, void (*visit)(treeType*));
void inorder(treeType * tree, void (*visit)(treeType*));

#endif