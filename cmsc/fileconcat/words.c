/* Rachel Carandang, rcarandang */
/* CMSC 2, Summer 2013 */
/* Homework 6 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entry {
	char *word;
	int count;
	};

typedef struct entry Entry;

char *lowercase(char* str);
void lookup(char *str, Entry *array[], int *size);
void insert(char *str, Entry *array[], int *size);
int trueChar(char c); 

/* my program looks up each word in the document, determining
if the characters are words using trueChar. Then it checks to see
if the word is in an array of data structures. if the word is in
the array, it increases the structure's count value by one.
if the word is not in the array, it creates a new structure
containing the word and initalizes the count value to 1.  */

int main (int argc, char* argv[]) {
	int initSize=0, *size=&initSize, i=0;
	char c, *newWord;
	FILE *fp= fopen(argv[1], "r+");
	Entry *array[99]; /*wanted to implement something so that when 
size gets to zero, array size is reallocated to fit 100 more characters,
 but it didn't work*/
	newWord=(char*)malloc(50*sizeof(char));
	while (!feof(fp)) {
		fscanf(fp, "%c", &c);
		if (trueChar(c)) {
			while ((trueChar(c))&&(i<50)) {
				i++;
				//printf("current char=%c \n ", c);
				//printf("space?=%d \n ", (c==' '));
				newWord[i-1]=c;
				fscanf(fp, "%c", &c);
				
			} ;
			i++;
			newWord[i-1]='\0';
			printf("current word= %s\n", newWord);
			lookup(newWord, array, size);
			i=0;
		}
	};
	fclose(fp);
	for (i=0; i<*size; i++) {
	printf("Word: %s - Count: %d\n", array[i]->word, array[i]->count);
	}
	return 0;
}

char* lowercase(char* str) {
	int i, asciiNum;
	for (i=0; i<((int)strlen(str)); i++) {
		asciiNum=(int)str[i];
		// if character is uppercase
		if ((asciiNum >= 65)&&(asciiNum <= 90)) {
			//convert to lowercase
			asciiNum+= 32;
			str[i]=(char)asciiNum;
		}
	}
	return str;
} 

/* Returns 1 if character is 0-9, A-Z, a-z */
int trueChar(char c){
	int x= (int)c;
	if (((x>47)&&(x<91))||
		((x>96)&&(x<123))) return 1; 
	else return 0;
}

/* finds word and increases count by one, otherwise
inserts word */
void lookup(char *str, Entry *array[], int *size) {
	int i;
	str= lowercase(str);
	for (i=0; i<*size; i++) {
	 	if (strcmp(array[i]->word, str)==0) {
			array[i]->count +=1;
			return;
		}
	}
	insert(str, array, size);
	return;
}

/*inserts lowercase version of word */
void insert(char *str, Entry *array[], int *size) {
	char *newWord= strdup(str);
	Entry *newEntry= (Entry*)malloc(sizeof(Entry));
	newEntry->word= str;
	newEntry->count= 1;
	*size +=1;
	array[*size-1]=newEntry;
	return;
}
