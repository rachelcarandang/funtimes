#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
	int n=0,m=0, i, j, k, integer;
	char x, *word=NULL, **text=NULL, *buffer, *spacesBuffer, *nullBuffer;
	// Each of the following is read as a separate string into an array 
	// of strings called **text: periods, exclamation pts, question marks,
	// tabs, spaces, and words. This allows for modifications to words 
	// only, tabs only, etc. 
	x=getchar();	
	while(x!=EOF) {
		if ((x != '.')&&(x != '!')&&(x != '?')&&(x != '\t')&&
		(x != ' ')) {
			// putting characters into the array until it 
			// is broken by a special character		
			// n tracks the number of characters in the array
			do {
				n++; 
				word= (char*)realloc(word, n*sizeof(char));
				word[n-1]= x; 
				x= getchar();
			} while ((x != '.')&&(x != '!')&&(x != '?')
				&&(x != '\t')&&(x != ' ')&&(x!=EOF));
			// making the character array a string		
			n++;
			word= (char*)realloc(word, n*sizeof(char));
			word[n-1] = '\0';
			// adding the string to an array of strings
			// m tracks the number of strings in the string array
			m++; 
			text = (char**)realloc(text, m*sizeof(char*));
			text[m-1]=(char*)malloc(n*sizeof(char*));
			memcpy(text[m-1], word, n); 
			n=0;
		}
		// putting special characters such as periods, tabs,  
		// and spaces, into the array as strings
		if (x!=EOF) {
			word= (char*)malloc(2*sizeof(char));
			word[0]= x;
			word[1]= '\0';		
			m++;
			text = (char**)realloc(text, m*sizeof(char*));
			text[m-1]=(char*)malloc(2*sizeof(char*));
			memcpy(text[m-1], word, 2);
			x= getchar();
		}
	}
	//ending reading in input
	free(word);
	// begin gigantic for-loop of command line //
	for (i=1; i< argc; i++) {
		// adding spaces to beginning of sentences //
		if (strcmp(argv[i],"-i")==0) {
			// if first character of the string in each 
			// text row is '.' '!' or '?', append string of 
			// four spaces to that end of that row.
			for (j=0; j<m; j++) {
				// using word as a character pointer. 
				word = text[j];
				if ((word[0]=='.')||(word[0]=='!')||
				(word[0]=='?')) {	
					text[j]=(char*)realloc(text[j],
					  (strlen(text[j])+4)*sizeof(char));
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
		}
		// adding newline to beginning of sentences // 
		if (strcmp(argv[i],"-n")==0) {
			// if first character of the string in each 
			// text row is '.' '!' or '?', append  
			// "\n" to that end of that row.
			for (j=0; j<m; j++) {
				word = text[j];
				if ((word[0]=='.')||(word[0]=='!')||
				(word[0]=='?')) {
					text[j]=(char*)realloc(text[j], 
					  (strlen(text[j])+1)*sizeof(char));
					strcat(text[j], "\n");
				}
			}
		}
		// replacing tabs with spaces //
		if (strcmp(argv[i],"-t")==0) {
			integer= atoi(argv[i+1]); 
			for (j=0; j<m; j++) {
				if (strcmp(text[j],"\t")==0) {	
					spacesBuffer= (char*)malloc
						((integer + 1)*sizeof(char));			
					// filling a buffer with given amount 
					// of spaces, then repointing row to
					// this buffer
					if (integer > 1)	{
						for (k=0; k<integer; k++) {
							spacesBuffer[k]=' ';
						};	
					};  
						spacesBuffer[integer]='\0'; 
					free(text[j]);
					text[j]= spacesBuffer;
				}
			}
		}
		// removing words //
		if (strcmp(argv[i],"-w")==0) {
			word= argv[i+1]; 
			for (j=0; j<m; j++) {
				if (strcmp(text[j], word)==0) {
					// filling a buffer with empty string,
					// then repointing row to this buffer.
					// this method of deletion prevents
					// row indices from being changed. 
					nullBuffer=(char*)malloc(sizeof(char));
					nullBuffer="";
					free(text[j]); 
					text[j]=nullBuffer;
				}
			}
		}
	} //end command line loop
	for (j=0; j<m; j++) {
		printf("%s", text[j]);
	}
	printf("\n");
	free(text);
	return 0;
}

