/* Rachel Carandang, rcarandang */
/* CMSC 2, Summer 2013 */
/* Homework 6 */
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
	int i; 
	char c;
	FILE *fp;
	for (i=1; i<argc; i++) {
		//printf("%s\n", argv[i]);
		fp= fopen(argv[i], "r+");
		while (!feof(fp)) {
			fscanf(fp, "s", &s);
			printf("%s", s);
		}
	fclose(fp);
	}
	return 0;
}
