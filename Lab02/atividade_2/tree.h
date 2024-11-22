#ifndef tree_h
#define tree_h

typedef struct treeType treeType;

treeType * createTree();

treeType * insertTree(treeType * tree, int n);

treeType * freeTree(treeType * tree);

void printTree(treeType * tree);

void rec_preorder(treeType * tree, void (*visit)(treeType*));
void rec_postorder(treeType * tree, void (*visit)(treeType*));
void rec_inorder(treeType * tree, void (*visit)(treeType*));

void iter_preorder(treeType * tree, void (*visit)(treeType*));
void iter_postorder(treeType * tree, void (*visit)(treeType*));
void iter_inorder(treeType * tree, void (*visit)(treeType*));

#endif