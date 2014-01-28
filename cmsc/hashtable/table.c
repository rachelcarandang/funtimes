#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkit.h"

struct entry {
	char *key;
	int value;
	struct entry *next;
};
typedef struct entry Entry;

struct hashtable {
	int size;
	Entry **table;
};
typedef struct hashtable Table;

typedef int ValueType;

Table * lookup_mkTable(int size);
int lookup_contains(Table* t, char *key); 
int lookup_hash(char * key); 
ValueType lookup_get(Table * t, char *key); 
Table * lookup_set(Table * t, char *key, ValueType value); 
int lookup_size(Table *t); 
void lookup_printTable(Table *t);

int main(void) {
	Table *nullHtable=lookup_mkTable(0), *myHtable=lookup_mkTable(10);
	lookup_printTable(nullHtable);
	myHtable= lookup_set(myHtable, "Alice", 0);
	myHtable= lookup_set(myHtable, "Aaron", 2);   
	myHtable= lookup_set(myHtable, "Bob", 5); 
	myHtable= lookup_set(myHtable, "Benjamin", 3);  
	myHtable= lookup_set(myHtable, "Bradley", 2);   
	myHtable= lookup_set(myHtable, "John", 5); 
	myHtable= lookup_set(myHtable, "Benjamin", 25); 
	myHtable= lookup_set(myHtable, "Alice", 100);
	myHtable= lookup_set(myHtable, "Bradley", 0); 
	lookup_printTable(myHtable);
	checkit_int(6, lookup_size(myHtable));
	checkit_int(1, lookup_contains(myHtable, "Bradley"));
	checkit_int(0, lookup_contains(myHtable, "Banana"));
	checkit_int(25, lookup_get(myHtable, "Benjamin"));
	checkit_int(5, lookup_get(myHtable, "John"));
	return 0;
}

Table * lookup_mkTable(int size) {
	int i;
	Table *htable;
	if (size<1) return NULL;
	htable= (Table*)malloc(sizeof(Table));
	htable->table= (Entry**)malloc(size*sizeof(Entry*));
	for (i=0; i<size; i++) {
		htable->table[i]=NULL;
	}
	htable->size=size;
	return htable;
}

/* Does the table contain this key? */ 
int lookup_contains(Table* t, char *key) {
	int i;
	Entry *entry;
	if (t!=NULL) {
		for (i=0; i<(t->size); i++) {
			for (entry= t->table[i]; 
				entry!=NULL; 
				entry=entry->next) {
				if (strcmp(entry->key, key)==0) return 1;		
			}
		}
	}
	return 0;


}

/* returns the hash code for a key. Think about what could be a good hash function to use.. */ 
int lookup_hash(char * key) {
	return key[0]-65; //hash index 0=A.....26=Z
}

/* Get the account associated to key */
ValueType lookup_get(Table * t, char *key) {
	int i;
	Entry *entry;
	if (t!=NULL) {
		for (i=0; i<(t->size); i++) {
			for (entry= t->table[i]; 
				entry!=NULL; 
				entry=entry->next) {
				if (strcmp(entry->key, key)==0) return entry->value;		
			}
		}
	}
	return 0;


}

/* Sets the key to new value. Adds new key/value pair if necessary. Returns pointer to table. */ 
Table * lookup_set(Table * t, char *key, ValueType value) {
	int i, hashCode= lookup_hash(key);
	Entry * entry, *prev, *newEntry;
	if (t!=NULL) {
		for (entry = t->table[hashCode], prev=NULL;
			entry !=NULL;
			prev=entry, entry= entry->next) {
			if (strcmp(key, entry->key)==0) {
				entry->value= value; //sets value
				return t;
			}
		}
	}
	// At this point either table=NULL; entry *=NULL and either previous points to NULL or prev points to last entry in hash index
	/* in all cases we need to make new Entry * structure */
	newEntry= (Entry*)malloc(sizeof(Entry));
	newEntry->key= strdup(key);
	newEntry->value= value;
	newEntry->next=NULL;
	// *t==NULL case? //	
	if (t==NULL) {
		lookup_mkTable(10); 
		t->table[hashCode] = newEntry;
	}
	else if (prev ==NULL) t->table[hashCode] = newEntry;
	else prev->next= newEntry;
	return t;
}
/* How many elements are in the table? */
int lookup_size(Table *t) {
	int i, num=0;
	Entry *entry;
	if (t!=NULL) {
		for (i=0; i<(t->size); i++) {
			for (entry= t->table[i]; 
				entry!=NULL; 
				entry=entry->next) {
				num++;		
			}
		}
	}
	return num;
}

 /* Nicely print the table */
void lookup_printTable(Table *t) {
	int i;
	Entry * entry;
	printf("----------------------------------\n HASH TABLE \n---------------------------------\n");
	if (t==NULL) {
		printf("NULL hash table");
		return;
	}
	for (i=0; i<(t->size); i++) {
		printf("HASH INDEX %d: ", i);
		for (entry=t->table[i]; entry!=NULL; entry=entry->next) {
			printf("[Key: %s, Value: %d] -> ", entry->key, entry->value);
		} 
		printf("NULL\n");	
	}
	printf("\n");
	return;
}
