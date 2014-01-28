#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void readIn(char* text[], int *m);
//void insert(char**text, int *m);
//void printTxt(char**text, int *m);

int main(int arc, char *argv[]) {
	printf("begin\n");
	int rows=0;
	char strArray[][1]={""};
	printf("before calling readIn\n");
	readIn(strArray, &rows);
	printf("finished calling readIn\n");
	printf("rows=%d\n", rows);
	printf("strArray[0]=%s\n", strArray[0]);
	//insert(strArray, &rows);
	//printf("finished insert\n");
	//printTxt(strArray, &rows);
	//printf("finished print\n");
	return 0;
}

void readIn(char* text[], int*m) {
	int n=0;
	char x, *word=NULL;
	// Each of the following is read as a separate string into an array 
	// of strings called **text:  periods, exclamation pts, question marks,
	// tabs, spaces, and words. This allows for modifications to words only,
	// tabs only, etc. 
	printf("called readIn\n");
	text=NULL;
	*m=0;
	x=getchar();	
	while(x!=EOF) {
		if ((x != '.')&&(x != '!')&&(x != '?')&&(x != '\t')&&(x != ' ')) {
			// putting characters into the array until it is broken by a special
			// character		
			// n is the number of characters in the character array
			do {
				n++; // printf("got to first realloc\n"); 
				word= (char*)realloc(word, n*sizeof(char));
				word[n-1]= x; 
				x= getchar();
			} while ((x != '.')&&(x != '!')&&(x != '?')&&(x != '\t')&&(x != ' ')&&(x!=EOF));
			// making the character array a string		
			n++;
			word= (char*)realloc(word, n*sizeof(char));
			word[n-1] = '\0';
			// adding the string to an array of strings
			// m is the number of strings in the string array
			*m=*m+1; //printf("m=%d\n", *m);
			text = (char**)realloc(text, (*m)*sizeof(char*));
			text[*m-1]=(char*)malloc(n*sizeof(char*));
			memcpy(text[*m-1], word, n); 
			n=0;
		}
		// putting special characters such as periods, tabs, and spaces  
		// into the array as strings
		
		if (x!=EOF) {
			word= (char*)malloc(2*sizeof(char));
			word[0]= x;
			word[1]= '\0';		
			*m=*m+1;  //printf("m=%d\n", *m);
			text = (char**)realloc(text, (*m)*sizeof(char*));
			text[*m-1]=(char*)malloc(2*sizeof(char*));
			memcpy(text[*m-1], word, 2);
			x= getchar();
		}
		
	}
	free(word);
	printf("Read in->text[0], first string=%s\n", text[0]);
	return;
}
/*
void insert(char**text, int *m) {
	int j, M;
	char *buffer, *word;
	// if first character of the string in each 
	// text row is '.' '!' or '?', append string of 
	// four spaces to that end of that row.
	for (j=0; j<M; j++) {
		// using word as a character pointer. 
		word = text[j];
		if ((word[0]=='.')||(word[0]=='!')||
		(word[0]=='?')) {	
			text[j]=(char*)realloc(text[j],
			  (strlen(text[j])+5)*sizeof(char));
			strcat(text[j], "    ");	
		}
	}
	// inserting four spaces before first word of 
	// input file with a buffer
	buffer= (char*)malloc
			((strlen(text[0])+5)*sizeof(char));
		memcpy(buffer, "    ", 5);
		strcat(buffer, text[0]);
		free(text[0]);
		text[0]=buffer;
	return;
}

*/
void printTxt(char** text, int *m) {
	printf("called printTxt\n");
	int j;
	printf("text[0], first string=%s\n", text[0]);
	/*for (j=0; j<5; j++) {
		printf("%s\n", text[j]);
	}*/
}



