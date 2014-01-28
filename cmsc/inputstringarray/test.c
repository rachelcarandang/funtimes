#include <stdio.h>

int countChar(char * str, char x);

int main(void) {
	int i=2;
	while (i < 5) {
		switch (++i) { 
			case 3: printf("a");
			case 4: printf("b");
			case 5: printf("c");
			default: printf("d");
		}
	}
	printf("%d\n",countChar("Hello World!", 'l'));
	return 0;

}

int countChar(char * str, char x) {
	int i=0, freq=0;
	if (str[i]=='\0') freq=0;
	if (str[i]==x) {
		freq+=1;	
		countChar(str[++i], x);
	} else if {
		countChar(str[++i], x);
	}
	return freq;

}
