/* Rachel Carandang, rcarandang */
/* CMSC 2, Summer 2013 */
/* Homework 7 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkit.h"
#include "lookup.h"

void join(Table *t, char *name, char *status);
void deposit(Table *t, char *name, int amount);
void withdraw(Table *t, char *name, int amount);
void print(Table *t, char *name);
char *nextMessage(FILE* inputStream);

/*other is either "trusted/untrusted" or a number */
int main(int argc, char*argv[]) {
	char *buffer=(char*)malloc(50*sizeof(char)), 
		*name=(char*)malloc(15*sizeof(char)), 
		*action=(char*)malloc(15*sizeof(char)), 
		*other=(char*)malloc(15*sizeof(char)); 
	FILE *fp = fopen(argv[1], "r");
	if (fp==NULL) {
		printf("error opening file");
		return 1;
	}
	Table *t= lookup_mkTable(); 
	while ((buffer=nextMessage(fp))!=NULL) {
		sscanf(buffer, " %s %s %s", name, action, other);
		if (strcmp(action, "joins")==0) 
				join(t, name, other);
		if (strcmp(action, "deposits")==0)
			deposit(t, name, atoi(other));
		if (strcmp(action, "withdraws")==0)
			withdraw(t, name, atoi(other));
		if (strcmp(action, "print")==0)
			print(t, name);
	} 
	return 0;
}

void join(Table *t, char *name, char *status) {
	Account* newAccount=(Account*)malloc(sizeof(Account)); 
	newAccount->amount=0;
	if (strcmp("trusted", status)==0) newAccount->status=1; 
	if (strcmp("untrusted", status)==0) newAccount->status=0;
	lookup_set(t, name, newAccount);
	return;
}

void deposit(Table *t, char *name, int deposit){
	Account* currentAccount;
	currentAccount= lookup_get(t, name);
	currentAccount->amount += deposit;
	return;
}
	
void withdraw(Table *t, char *name, int withdrawal){
	Account* currentAccount;
	currentAccount= lookup_get(t, name);
	if ((currentAccount->status==0)&&
		(currentAccount->amount - withdrawal >=0)) {
		currentAccount->amount -= withdrawal;
	}
	else if ((currentAccount->status==1)&&
		(currentAccount->amount- withdrawal>= -1000)) {
		currentAccount->amount -= withdrawal;
	}
	else printf("Transaction for %s fails\n", name);
	return;
}
	
void print(Table *t, char *name) {
	Account* currentAccount;
	currentAccount= lookup_get(t, name);
	printf("%s:\t $ %d\n", name, currentAccount->amount);
	return;
}

char* nextMessage(FILE *inputStream) {
	char *buffer=(char*)malloc(50*sizeof(char));
		fgets(buffer, 50, inputStream);
		if (feof(inputStream)) return NULL;
		else return buffer;
}





