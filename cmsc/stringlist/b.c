#include <stdio.h>
#include <stdlib.h>
#include "checkit.h"

struct string_linked_list {
        char *s;
        struct string_linked_list *next;
};
      
typedef struct string_linked_list SLL;


void SLLprint(SLL *list); // my own print function 
int SLL_is_empty(SLL *list);
SLL *SLL_cons(char *s, SLL *list);
void SLL_free(SLL *list);
int SLL_length(SLL *list);
int SLL_totalChars(SLL * list, char ch);
SLL * SLL_replicate(SLL * list,int count);
SLL * SLL_mergeAndOrder(SLL * list1, SLL * list2); 
int SLL_same(SLL *list1, SLL *list2);

int main(void) {
	int a[]={0, 1, 2, 3, 4};
	const char *myString= "A";
	SLL *myList, *myList2, *myList3, *myList4, *myList5, *myList6;
	myList2= NULL;
	myList= SLL_cons("Fred", NULL);
	myList= SLL_cons("Jane", myList);
	myList= SLL_cons("Bob", myList);
	SLLprint(myList);
	SLLprint(SLL_replicate(myList, 1));
	return 0;
}

/* return a quasi-boolean, indicating whether list is empty */
int SLL_is_empty(SLL *list) {
	if (list==NULL) 
		return 1;
	else return 0;
}

/* build a new list from string s and list, which points to another struct */
/* for the head of the list, copy the string to the heap (use strdup) */
//strdup returns a pointer to the storage space containing the copied string. 
//string functions take IN a string, which IS a pointer, so the string function should take in the pointer variable that IS the string.
SLL *SLL_cons(char *s, SLL *list) {
	char *newString = strdup(s); 
	SLL *newNode = (SLL*)malloc(sizeof(SLL));
	newNode->s = newString;
	newNode->next = list;
	return newNode;
}

/* free the string list and all the strings it points to as well */
void SLL_free(SLL *list) {
	SLL *p;
		p=list->next;
		printf("list->s = %s\n", list->s);
		free(list->s);
		printf("list->s = %s\n", list->s);
		free(list);
		list=p;
	printf("Executed SLL_free\n");
	return;
}

/* compute the length of the given list */
int SLL_length(SLL *list){
	int len;
	SLL *p;
	for (p=list, len=0; 
			p!=NULL; 
			p=p->next, len++);
	return len;
}

/* returns the total number of occurrences of the character ch in each string in list */ 

int SLL_totalChars(SLL * list, char ch) {
	int freq=0, i;
	SLL *p;
	char *currString;
	for (p=list; p!=NULL; p= p->next) {
		currString = p->s; 
		for (i=0; currString[i] != '\0'; i++) {
			printf("character= %c\n", currString[i]);
			if (currString[i]==ch) freq +=1;
		}			
	}
	return freq;
}


/* returns a new list of that nodes are replicated the number of times specified by parameter count */ 

SLL *SLL_replicate(SLL *list, int count) {
	int i;	
	char *s, *newString; 
	SLL *newNode, *lastNode, *curr, *newList=NULL;
	for (curr=list; curr !=NULL; curr=curr->next) {
		for (i=0; i<count+1; i++) {
			s= curr->s;
			newNode = (SLL*)malloc(sizeof(SLL));
			newString = strdup(s);
			newNode->s = newString; 
			if ((i==0)&&(strcmp(curr->s, list->s)==0)) 
				newList= newNode;
			else {
				lastNode->next=newNode;	
			}
			newNode->next=NULL;
			lastNode= newNode;
		}
	}
	return newList;
}

/*
SLL *copySLL (SLL*list) {
	char *s, *newString;
	SLL *p, *p2, *prev, *listcpy, *newNode;
	if (list==NULL) return NULL;
	else {
		listcpy=SLL_cons(list->s, NULL); 
		for (p=list->next; p!=NULL; p=p->next) {
			s= p->s;
			newString=(char*)malloc((strlen(s)+1)*sizeof(char));
			newNode=(SLL*)malloc(sizeof(SLL));
			newString= strdup(s);
			newNode->s = newString; 
			printf("newNode %s\n", newNode->s);
			for(p2=listcpy, prev=NULL; p2!=NULL; prev=p2, p2=p2->next);//skips to end 
			printf("previous %s\n", prev->s);
			prev->next=newNode;
			newNode->next=NULL;
		}
		return listcpy;
	}
}
*/

// inserts a copy of a single node into an ordered list
SLL *insertOrder (char* s, SLL *list) {
	char *newString=(char*)malloc((strlen(s)+1)*sizeof(char));
	SLL *p, *prev, *newNode=(SLL*)malloc(sizeof(SLL));
	newString= strdup(s);
	newNode->s = newString; 
	for (prev=NULL, p=list; 
		p!=NULL && strcmp(s, p->s) > 0;
		prev= p, p= p->next) {
		if (prev!=NULL) printf("prev at this point = %s\n", prev->s);
		printf("p at this point = %s\n", p->s);
	}
	if (prev==NULL) {
		newNode->next=list;
		list=newNode;
	}
	else if (p==NULL) {
		newNode->next=NULL;
		prev->next=newNode;
	}
	else {
		newNode->next=p;
		prev->next=newNode;
	}
	return list;
}
/* Create a new list that is an ordered union of the the two list. */ 
/* Use strcmp to determine which string is less/greater than the other string */
// strcmp (s1, s2) <0 means s1 < s2; strcmp(s1, s2) >0 means s1 > s2 

SLL *SLL_mergeAndOrder(SLL * list1, SLL * list2) {
	SLL *p1, *p2, *newList=NULL;
	for (p1=list1, p2=list2;
		p1 != NULL && p2 != NULL;
		p1= p1->next, p2= p2->next) {
		printf("p1 at this point=%s\n", p1->s);
		printf("p2 at this point=%s\n", p2->s);
		newList= insertOrder(p1->s, newList);
		newList= insertOrder(p2->s, newList);
	}
	if ((p1==NULL) && (p2!=NULL)) {
		for (; p2!=NULL; p2=p2->next) {
		newList= insertOrder(p2->s, newList);
		}
	}
	if ((p1!=NULL) && (p2==NULL)) {
		for (; p1!=NULL; p1=p1->next) {
		newList= insertOrder(p1->s, newList);
		}
	}
	return newList;
}

/* moves through each node of both lists, comparing the strings until at least one list terminates. The moment two strings being compared are not equal, returns false. If one list terminates before the other, returns false.  Otherwise, returns true. */
int SLL_same(SLL *list1, SLL *list2) {
	SLL *p1, *p2;
	for (p1=list1, p2=list2;
		p1 != NULL && p2 != NULL;
		p1= p1->next, p2= p2->next) {
			if (strcmp (p1->s, p2->s)!=0)
				return 0;
		}	
	if (!(p1==NULL && p2==NULL))
		return 0;
	else
		return 1;
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

/*
SLL *SLL_removeAllBut(SLL*list, char *str) {
	SLL *p, *temp, *lastFound=NULL;
	for (p=list; p!=NULL; p=temp) {
		temp=p->next;
		if (strcmp(p->s, str)==0) {
			if (lastFound==NULL) list=p; //if p is the first instance of str, reset head of list to p
			else lastFound->next= p; //otherwise take the last instance found and connect it to the current node
			lastFound=p;		
		}
		else { //need to free current node, p
		free(p->s);
		free(p);
		}
		
	}
	//at this point, p and temp are both pointing to end of list, NULL, 
	//connect lastFound to NULL
	if (lastFound!=NULL) {
		lastFound->next=NULL;
		return list;
	}
	else 
		return NULL;
	
}

*/


