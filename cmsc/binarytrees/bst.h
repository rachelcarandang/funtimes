#ifndef BST_H
#define BST_H

#include<stdio.h>
#include<stdlib.h>

struct node {
	unsigned short x;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

struct bst {
	Node * root;
};
typedef struct bst BST;

/* Adds a postive short value to the tree */
BST * bst_insert(BST *tree, unsigned short newValue);
Node * insertHelper(Node *node, unsigned short x);

/* Prints all the nodes in the order (i.e. from smallest value in tree to the largest value in order). 
   Each value should be followed by a newline. */ 
void bst_traverseInOrder(BST * tree); 

/* returns "True" (i.e. 1) if findMe is located somewhere in the tree, otherwise "False" (i.e. 0). */ 
int bst_isValueInTree(BST * tree, unsigned short findMe);
int searchHelper(Node *node, unsigned short x);


#endif
