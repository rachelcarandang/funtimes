#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

/* Adds a postive short value to the tree */
BST * bst_insert(BST *tree, unsigned short newValue) {
	if (tree==NULL) {
		tree=(BST*)malloc(sizeof(BST));
		tree->root=(Node*)malloc(sizeof(Node));
		tree->root->x=newValue;
		tree->root->left=NULL;
		tree->root->right=NULL;
		return tree;
	} 
	tree->root= insertHelper(tree->root, newValue);
	return tree;
}

Node * insertHelper(Node *node, unsigned short x) {
	if (node==NULL) {
		node=(Node*)malloc(sizeof(Node));
		node->x=x;
		node->left=NULL;
		node->right=NULL;
		return node;
	} else {
		if (x< node->x) 
			node->left= insertHelper(node->left, x);
		else node->right= insertHelper(node->right, x);
	}
	return node;
}

void traverseHelper(Node* node) {
		if (node==NULL) return;
		traverseHelper(node->left);
		printf("%d ", node->x);
		traverseHelper(node->right);
		return;
}

/* Prints all the nodes in the order (i.e. from smallest value in tree to the largest value in order). 
   Each value should be followed by a newline. */ 
void bst_traverseInOrder(BST * tree) {
	if (tree==NULL) return;
	traverseHelper(tree->root);
	printf("\n");
	return;
} 

/* returns "True" (i.e. 1) if findMe is located somewhere in the tree, otherwise "False" (i.e. 0). */ 
int bst_isValueInTree(BST * tree, unsigned short findMe) {
	if (tree==NULL) return 0;
	return searchHelper(tree->root, findMe);
	
}
int searchHelper(Node *node, unsigned short x) {
	if (node==NULL) return 0;
	if (node->x == x) return 1;
	else {
		if (x < node->x) 
			searchHelper(node->left, x);
		else searchHelper(node->right, x);
	}
	return 0;
}
