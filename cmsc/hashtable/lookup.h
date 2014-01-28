#ifndef LOOKUP_H
#define LOOKUP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkit.h"
#include "account.h"

typedef Account* ValueType;

struct entry {
	char *key;
	ValueType value;
	struct entry *next;
};

struct hashtable {
	int size;
	struct entry **table;
};

typedef struct entry Entry;
typedef struct hashtable Table;

Table * lookup_mkTable(void);
int lookup_contains(Table* t, char *key); 
int lookup_hash(char * key); 
ValueType lookup_get(Table * t, char *key); 
Table * lookup_set(Table * t, char *key, ValueType value); 
int lookup_size(Table *t); 
void lookup_printTable(Table *t);

#endif

