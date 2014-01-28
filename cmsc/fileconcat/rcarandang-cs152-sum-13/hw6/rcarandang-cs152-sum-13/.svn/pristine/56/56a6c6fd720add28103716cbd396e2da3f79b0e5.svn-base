/* Rachel Carandang, rcarandang */
/* CMSC 2, Summer 2013 */
/* Lab 4 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkit.h"
#include "sll.h"

int SLL_is_empty(SLL *list) {
	if (list==NULL) 
		return 1;
	else return 0;
}


SLL *SLL_cons(char *s, SLL *list) {
	char *newString = strdup(s); 
	SLL *newNode = (SLL*)malloc(sizeof(SLL));
	newNode->s = newString;
	newNode->next = list;
	return newNode;
}

/* Note: temp stores the address of the next value in the list so that when 
each item of the list is freed, you don't lose the list trail */
void SLL_free(SLL *list) {
	SLL *p, *temp;
	for (p=list; p!=NULL; p=temp) {
		temp= p->next;		
		free(p->s);
		free(p);	
	}
	return;
}


int SLL_length(SLL *list){
	int len;
	SLL *p;
	for (	p=list, len=0; 
		p!=NULL; 
		p=p->next, len++); /*each time p moves to the next value 
		in the list, len increases by 1, until p=NULL */
	return len;
}

/* For each item in the list, the function points currString to
that item's string value. Then it iterates through each character
in currString until the null character, increasing freq by 1
each time it finds the given character. Then it moves on to the next
item in the list and repeats this procedure. */
int SLL_totalChars(SLL * list, char ch) {
	int freq=0, i;
	SLL *p;
	char *currString;
	for (p=list; p!=NULL; p= p->next) {
		currString = p->s; 
		for (i=0; currString[i] != '\0'; i++) {
			if (currString[i]==ch) freq +=1;
		}			
	}
	return freq;
}


SLL *SLL_replicate(SLL *list, int count) {
	int i;	
	char *newString; 
	SLL *newNode, *curr;
	for (curr=list; curr !=NULL; curr=curr->next) {
		/* For each item of the list, the following loop creates the 
		given number of duplicate nodes. The newest node created is 
		always the current node, so that when the functions jumps out
		of the loop, it moves to the next distinct node on the list,
		and repeats the process. */
		for (i=0; i<count; i++) {
			newNode = (SLL*)malloc(sizeof(SLL));
			newString = strdup(curr->s);
			newNode->s = newString; 
			newNode->next = curr->next;
			curr->next = newNode;
			curr = newNode;
		}
	}
	return list;
}

/* insertOrder takes a node and an ordered list and inserts 
the node in the correct place in the list.   */
SLL *insertOrder (SLL* node, SLL *list) {
	SLL *prev, *curr;
	/* The pointers prev and curr iterate through the list until
	 the string-value of node->s is less than or equal to curr->s. */
	for (curr=list, prev=NULL; 
		curr!=NULL && strcmp(node->s, curr->s) > 0;
		prev= curr, curr= curr->next);
	/* prev==NULL indicates that either list is NULL,
	or (node->s) <= (list->s), the string-value of the first 
	item of list. In both cases the node belongs at the head of the 
	list. */
	if (prev==NULL) {
		node->next= list;
		list= node;
	}
	/* Otherwise the node is inserted between prev and curr.
	This clause also covers the case when the node goes at the very
	end of the list, when curr is NULL */
	else {
		node->next= curr;
		prev->next= node;
	}
	return list;
}

/* mergeAndOrder inserts each item of list1, in order, into 
"list", starting with list=NULL. The function ensures that the 
second argument of insertOrder is always an ordered list, according 
to the contract of insertOrder. Then it inserts each item of list2. */
SLL *SLL_mergeAndOrder(SLL * list1, SLL * list2) {
	SLL *p, *temp, *list=NULL;
	for (p=list1; p!=NULL; p= temp) {
		temp= p->next;
		list= insertOrder(p, list);
		}
	for (p=list2; p!=NULL; p=temp) {
		temp=p->next;
		list= insertOrder(p, list);
		p= temp;
		}
	return list;
}

/* moves through each node of both lists, comparing the strings until at 
least one list terminates. The moment two strings being compared are not 
equal, returns false. If one list terminates before the other, returns
false.  Otherwise, returns true. */
int SLL_same(SLL *list1, SLL *list2) {
	SLL *p1, *p2;
	for (p1=list1, p2=list2;
		(p1 != NULL) && (p2 != NULL);
		p1= p1->next, p2= p2->next) {
			if (strcmp (p1->s, p2->s)!=0) return 0;
		}	
	if (!(p1==NULL && p2==NULL))
		return 0;
	else
		return 1;
}


SLL *SLL_reverse(SLL *list) {
	SLL *p, *temp;
	for (p=list, list=NULL; 
		p!=NULL; 
		p= temp) {
	temp= p->next;
	p->next=list;
	list=p;
	}
	return list;
}

SLL *SLL_keepAllBut(SLL*list, char *str) {
 	SLL *prev, *p;
	p=list;
	prev=NULL;
	while (p!=NULL) {
		if (strcmp(p->s, str)==0) {
/* prev==NULL indicates that the p to be deleted
is at the head of the list. deleting the head of
 the list is the only case in which the pointer 
"list" needs to be reassigned to the new head of the list. */
			if(prev== NULL) {
				list = p->next;
				free(p->s);
				free(p);
				p= list; 
			} else {
				prev->next=p->next;
				free(p->s);
				free(p);
				p= prev->next;	
			}
		} else {
			prev=p;
			p= p->next;
		}
	}
	return list;	
}

/* SLL_search tests to see if a string is in a SLL. I created this program
to avoid nested for loops in SLL_intersect and to make SLL_intersect 
more clear */
int SLL_search(char *str, SLL *list) {
	SLL *p;
	for (p=list; p!=NULL; p= p->next) {
		if (strcmp(str, p->s)==0) return 1;
	}
	return 0;
}



/* This program filters listToFilter of any items it finds in listToDump
using SLL_search. It then frees listToDump from memory. */
SLL *SLL_intersect(SLL *list, SLL *list2) {
	SLL *listToFilter, *listToDump, *prev=NULL, *p;
	/* idea of this top part is to save time by lessening the amount 
	of iterations of the while-loop of the program? not sure about 
	program time costs, though. */
	if (SLL_length(list)< SLL_length(list2)) {
		listToFilter= list;
		listToDump=list2;
	} else {
		listToFilter= list2;
		listToDump= list;
	}
	p= listToFilter; 
	while (p!=NULL) {
		if (SLL_search(p->s, listToDump)) {/*keep p*/ 
			prev=p;
			p= p->next; 			
		} else {
		/*In this clause we want to delete p. Again, prev==NULL 
indicates that the head of the list is to be deleted, so
this case reassigns the pointer listToFilter. Otherwise, deletion
occurs in the usual way. */
			if(prev==NULL){
				listToFilter = p->next;
				free(p->s);
				free(p);
				p= listToFilter;
			} else {
				prev->next=p->next;
				free(p->s);
				free(p);
				p= prev->next;
			}
		}
	} //end while loop
	SLL_free(listToDump);
	return listToFilter;
}


/* SLLcheck checks that each node in a string-linked-list against an
array of string */
void SLLcheck(SLL *list, char* strArray[]) {
	int i;
	SLL *p;
	for (	p=list, i=0;
		p!=NULL; 
		p=p->next, i++){
		printf("SLL check : ");
		checkit_string(p->s, strArray[i]);
		}
	/* if expected value is NULL, checks that argument evaluates
	to NULL */
	if (strArray==NULL) {
		printf("SLL check : ");
		checkit_int(1, (list==NULL)); 
	}
	return;	
}

void SLLprint(SLL *list) {
	int i;
	SLL *p;
	for (	p=list, i=0; 
		p!=NULL; 
		p=p->next, i++){
		printf("List item %d = %s\n", i, p->s);
		}
	printf("List item %d = NULL\n", i);
	return;
}

