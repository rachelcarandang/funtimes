/* Rachel Carandang, rcarandang */
/* CMSC2, Summer 2013 */
/* Lab 4 */
/*

Instructions: keep sll.h and sll.c. make new main function. submit in repository under lab4 directory. the main function should test the three functions. 

SLL * SLL_reverse(SLL *list) -> reverses a linked list (no new allocation of memory)
ex: "john"->bob->cole ==> cole->bob->john 


SLL * SLL_keepAllBut(SLL*list, char * str) -> removes all the nodes in the list that contain string (use free)
ex: keepAllBut "a"; "a"->"a"->b->c => b->c;

SLL * SLL_intersect (SLL *list, SLL *list2) -> creates a new list that contains the nodes that are in both lists
ex: list= "a"->b->d
	list = "a"->d->e;
should return "a" -> d -> NULL 
should free/remove all the nodes that aren't in the intersection
if there are duplicates in both lists, just include 1


*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkit.h"
#include "sll.h"

int main(void) {
/* in general, my tests check regular lists, as well as lists of one element, ie. L3, and the NULL list*/
	SLL *L1, *L2, *L3, *L4, *L5, *L6;
	char 	*a1[3]= {"Start", "Hello", "World"},
		*a2[3]= {"World", "Hello", "Start"},
		*a3[1]= {"d"},
		*a4[2]={"b", "c"},
		*a5[2]={"b", "e"};

	L1= SLL_cons("World", NULL);
	L1= SLL_cons("Hello", L1);
	L1= SLL_cons("Start", L1);
	
	L2= SLL_cons("c", NULL);
	L2= SLL_cons("b", L2);
	L2= SLL_cons("a", L2);
	L2= SLL_cons("a", L2);
	
	L3= SLL_cons("d", NULL);

	L4= SLL_cons("d", NULL);
	L4= SLL_cons("e", L4);
	L4= SLL_cons("b", L4);

	L5= SLL_cons("f", NULL);
	L5= SLL_cons("b", L5);
	L5= SLL_cons("e", L5);
	L5= SLL_cons("a", L5);

	L6= SLL_cons("a", NULL);

	SLLcheck(L1, a1);
	SLLcheck(SLL_reverse(L1), a2);
	SLLprint(SLL_reverse(L1));

	SLLcheck(SLL_reverse(L3), a3);
	SLLcheck(SLL_reverse(NULL), NULL);
	
	SLLcheck(SLL_keepAllBut(L2, "a"), a4);
	SLLcheck(SLL_keepAllBut(L3, "d"), NULL);
	SLLcheck(SLL_keepAllBut(NULL, "d"), NULL);

	checkit_int(SLL_search("b", L4), 1);
	checkit_int(SLL_search("Bye", L1), 0);
	checkit_int(SLL_search("Hello", NULL), 0);
	
	SLLcheck(SLL_intersect(L4, L5), a5);
	SLLcheck(SLL_intersect(NULL, L6), NULL);

	return 0;
}


