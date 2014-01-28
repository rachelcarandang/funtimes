/* Rachel Carandang, rcarandang */

#include<stdio.h>
#include<stdlib.h>
#include "checkit.h"
#include "bst.h"

unsigned short convertToShort(char * binString) ;
void treeFromFile (FILE *fp, BST *tree);


int main(int argc, char* argv[]) {
	FILE *fp= fopen(argv[1], "r");
	BST *mytree=NULL,*mytree2=NULL;
	char * binStr1 = "0000000000000110"; 
	char * binStr2 = "0000000000000000"; 
	checkit_int(convertToShort(binStr1),6);
	checkit_int(convertToShort(binStr2),0); 
	mytree= bst_insert(mytree, 8);
	mytree= bst_insert(mytree, 3);
	mytree= bst_insert(mytree, 10);
	mytree= bst_insert(mytree, 1);
	mytree= bst_insert(mytree, 6);
	mytree= bst_insert(mytree, 14);
	bst_traverseInOrder(mytree);
	checkit_int(bst_isValueInTree(mytree, 10), 0);
	checkit_int(bst_isValueInTree(mytree, 2), 0); 
	//treeFromFile(fp, mytree2);
	return 0;
}

unsigned short convertToShort(char * binString) {
	int i, num=0;
		for (i=0; i<16; i++) {
			if (binString[i]=='1') 
				num |= 1<<(15-i);
		}
	return num;
} 

void treeFromFile (FILE *fp, BST *tree) {
	int num;
	char* buffer = (char*)malloc(17*sizeof(char));
	while (!(feof(fp))) {
		fgets(buffer, 17, fp); printf("%s", buffer);
		num= convertToShort(buffer);
		tree= bst_insert(tree, num);
	}
	bst_traverseInOrder(tree);
	return;
}


