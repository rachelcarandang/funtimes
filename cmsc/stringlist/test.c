

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkit.h"
#include "lookup.h"


char* nextMessage(FILE *inputStream) {
	char currentChar;	
	char *currentLine="";
	while (currentChar != '\n') {
		fscanf(" %c", currentChar);
		sprintf(currentLine, "%s %c", currentLine, currentChar);
	}
	if (!(feof(inputStream)) return currentLine;
	else return NULL;
}


int main(int argc, char*argv[]) {
	char *command, *name, *action, *other, *currentLine;
	FILE *fp = fopen(argv[1], "r");
	currentLine= nextMessage(fp);
	sscanf(currentLine, "%s %s %s", name, action, other);
	printf("name=%s\n action=%s\n other=%s\n", name, action, other);  

return 0;
}

