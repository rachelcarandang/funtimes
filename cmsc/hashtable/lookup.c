#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkit.h"
#include "lookup.h"

Table * lookup_mkTable(void) {
	int i;
	Table *htable;
	htable= (Table*)malloc(sizeof(Table));
	htable->table= (Entry**)malloc(100*sizeof(Entry*));
	for (i=0; i<100; i++) {
		htable->table[i]=NULL;
	}
	htable->size=100;
	return htable;
}

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

int lookup_hash(char * key) {
	int i, sum=0;
	for (i=0; i<strlen(key); i++) {
		sum= key[i] + sum;
	}
	return sum % 100; //mod out by the hash table size
}

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
}

Table * lookup_set(Table * t, char *key, ValueType value) {
	int i, hashCode= lookup_hash(key);
	Entry * entry, *prev, *newEntry;
	if (t!=NULL) {
		for (entry = t->table[hashCode], prev=NULL;
		     entry !=NULL;
		     prev=entry, entry= entry->next) {
			//sets value if key was found
			if (strcmp(key, entry->key)==0) {
				entry->value= value; 
				return t;
			}
		}
	}
	/* At this point either table=NULL; entry *=NULL and either previous 
	points to NULL or prev points to last entry in hash index.
	In all cases we need to make new Entry* structure */
	newEntry= (Entry*)malloc(sizeof(Entry));
	newEntry->key= strdup(key);
	newEntry->value= value;
	newEntry->next=NULL;
	// t==NULL case //	
	if (t==NULL) {
		t= lookup_mkTable(); 
		t->table[hashCode] = newEntry; 
	}
	// case where entry in the hashcode index was NULL //
	else if (prev ==NULL) t->table[hashCode] = newEntry;
	//normal case: add newEntry to end of entry linked list //
	else prev->next= newEntry;
	return t;
}

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

 /* Prints linked list at each hashcode index, including "NULL" entries */
void lookup_printTable(Table *t) {
	int i;
	Entry * entry;
	printf("----------------------------------\n HASH TABLE");
	printf(" \n---------------------------------\n");
	if (t==NULL) {
		printf("NULL hash table\n");
		return;
	}
	for (i=0; i<(t->size); i++) {
		printf("HASH INDEX %d:", i);
		for (entry=t->table[i]; entry!=NULL; entry=entry->next) {
			printf("\n     [Key: %s] -> \n", entry->key);
		} 
		printf("     NULL\n");	
	}
	printf("\n");
	return;
}
