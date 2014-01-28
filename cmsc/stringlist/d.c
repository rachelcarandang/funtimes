#include <stdio.h>
#include <stdlib.h>
#include "checkit.h"

struct string_linked_list {
        char *s;
        struct string_linked_list *next;
};
      
typedef struct string_linked_list SLL;

int SLL_is_empty(SLL *list);
SLL *SLL_cons(char *s, SLL *list);
void SLL_free(SLL *list);
int SLL_length(SLL *list);
int SLL_totalChars(SLL * list, char ch);
SLL * SLL_replicate(SLL * list,int count);
SLL *insertOrder (SLL* node, SLL *list);
SLL * SLL_mergeAndOrder(SLL * list1, SLL * list2); 
int SLL_same(SLL *list1, SLL *list2);
/* checks that each node in a string-linked-list has the expected string value */
void SLLcheck(SLL *list, char* strArray[]);

int main(void) {
	// test SLL's and corresponding string arrays in order to 
	// check that the SLL's are in proper order
	SLL *L1, *L2, *L3, *L4, *L5, *L6 ;
	char 	*a1[3]= {"Start", "Hello", "World"},
		*a2[9]={"Start", "Start", "Start",
			"Hello", "Hello", "Hello",
			"World", "World", "World"},
		*a3[3]= {"Hello", "Start", "World"},
		*a4[3]= {"Hello", "Start", "World"},
		*a5[5]= {"a", "c", "d", "e", "f"};
	L1 = SLL_cons("f", NULL);
	L1 = SLL_cons("d", L1);
	L1 = SLL_cons("a", L1);
	// L1 = ("a") -> ("d") -> ("f")
	L2 = SLL_cons("e", NULL);
	L2= SLL_cons("c", L2);
	// L2 = ("c") -> ("e")
	L3= SLL_cons("World", NULL);
	L3= SLL_cons("Hello", L3);
	L3= SLL_cons("Start", L3);
	// L3 = ("Start") -> ("Hello") -> ("World")
	L4= SLL_cons("World", NULL);
	L4= SLL_cons("Hello", L4);
	L4= SLL_cons("Start", L4);
	// L4 = ("Start") -> ("Hello") -> ("World")
	
	/* Testing SLL_cons */
	SLLcheck(L3, a1);

	/* Testing SLL_length */
	checkit_int(SLL_length(NULL), 0);
	checkit_int(SLL_length(L2), 2);
	checkit_int(SLL_length(L3), 3);

	/* Testing SLL_totalChars */
	checkit_int(SLL_totalChars(NULL, 'a'), 0);
	checkit_int(SLL_totalChars(L3, 'y'), 0);
	checkit_int(SLL_totalChars(L3, 'l'), 3);

	/* Testing SLL_replicate */
	SLLcheck(SLL_replicate(L3, 0), a1);
	SLLcheck(SLL_replicate(L3, 2), a2);
	checkit_int((SLL_replicate(NULL, 2)==NULL), 1);

	/* Testing SLL_mergeAndOrder */
	//SLLcheck(SLL_mergeAndOrder(L3, NULL), a3);
	//SLLcheck(SLL_mergeAndOrder(NULL, L4), a4);
	SLLcheck(SLL_mergeAndOrder(L1, L2), a5);

	/* Testing SLL_same */
	checkit_int(SLL_same(L3, L4), 1);
	//checkit_int(SLL_same(NULL,NULL), 1);
	checkit_int(SLL_same(L1, L3), 0);
	
	return 0;
}

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

void SLL_free(SLL *list) {
	SLL *p;
		p=list->next;
		free(list->s);
		free(list);
		list=p;
	return;
}

int SLL_length(SLL *list){
	int len;
	SLL *p;
	for (p=list, len=0; 
			p!=NULL; 
			p=p->next, len++);
	return len;
}

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
	char *s, *newString; 
	SLL *newNode, *curr;
	for (curr=list; curr !=NULL; curr=curr->next) {
		for (i=0; i<count; i++) {
			s= curr->s;
			newNode = (SLL*)malloc(sizeof(SLL));
			newString = strdup(s);
			newNode->s = newString; 
			newNode->next = curr->next;
			curr->next = newNode;
			curr = newNode;
		}
	}
	return list;
}

SLL *insertOrder (SLL* node, SLL *list) {
	SLL *prev, *curr;
	for (curr=list, prev=NULL; 
		curr!=NULL && strcmp(node->s, curr->s) > 0;
		prev= curr, curr= curr->next) {
	}
	if (prev==NULL) {
		node->next= list;
		list= node;
	}
	else {
		node->next= curr;
		prev->next= node;
	}
	return list;
}

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

/* checks that each node in a string-linked-list has the expected string value */
void SLLcheck(SLL *list, char* strArray[]) {
	int i;
	SLL *p;
	for (	p=list, i=0;
		p!=NULL; 
		p=p->next, i++){
		printf("Check SLL item %d : ", i);
		checkit_string(p->s, strArray[i]);
		}
	return;	
}

