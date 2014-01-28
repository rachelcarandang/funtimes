/* Rachel Carandang, rcarandang */
/* CMSC 2, Summer 2013 */
/* Homework 6 */

#include <stdio.h>
#include <stdlib.h>

int charNum(char c); 


/* This program works by reading only the characters representing
 numbers from the file (using the function charNum). It prints to 
 the file given in the command line and puts parenthesis every 
 three numbers, a dash every five numbers, 
 and a newline character every 9 numbers. */

int main (int argc, char *argv[]) {
	int count=0;
	char c;
	FILE *fpSrc= fopen(argv[1], "r"), *fpDest= fopen(argv[2], "w");
	while (!feof(fpSrc)) {
		if (count==10) count=0;
		fscanf(fpSrc, " %c", &c);
		//printf("[%c] ", c);
		if (charNum(c)) {
			switch(count) {
				case 0: fprintf(fpDest, "(%c", c);
				break;
				case 1: fprintf(fpDest, "%c", c);
				break;
				case 2: fprintf(fpDest, "%c) ", c);
				break;
				case 3: fprintf(fpDest, "%c", c);
				break;
				case 4: fprintf(fpDest, "%c", c);
				break;
				case 5: fprintf(fpDest, "%c-", c);
				break;
				case 6: fprintf(fpDest, "%c", c);
				break;
				case 7: fprintf(fpDest, "%c", c);
				break;
				case 8: fprintf(fpDest, "%c", c);
				break;
				case 9: fprintf(fpDest, "%c\n", c);
				break;
				default: printf("");
			} 	
		count++; 		
		}
		
	} 
	fclose(fpSrc);
	fclose(fpDest);
	return 0;
}

/* Returns true if the character represents 0-9 in ascii table*/
int charNum(char c) {
	if (((int)c>47)&&((int)c<58)) return 1; 
	else return 0;
}
