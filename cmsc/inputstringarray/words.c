/* Rachel Carandang, rcarandang */
/* CMSC 2 Summer 2013 */
/* Homework 6 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct entry {
	char * word;
	int *count;
	};

typedef struct entry Entry;

char* lowercase(char* str);


int main (int argc, char* argv[]) {
	int i; 
	char c;
	FILE *fp;
	for (i=1; i<argc; i++) {
		//printf("%s\n", argv[i]);
		fp= fopen(argv[i], "r");
		while (!feof(fp)) {
			fscanf(fp, " %c", &c);
			printf("%c", c);
		}
	fclose(fp);
	}
	return 0;
}
