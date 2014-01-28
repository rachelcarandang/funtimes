/* Rachel Carandang, rcarandang */
/* CMSC 2, Summer 2013 */
/* Homework 5*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkit.h"
#include "sll.h"

int main(void) {
	// test SLL's and corresponding string arrays in order to 
	// check that the SLL's are in proper order
	SLL *L1, *L2, *L3, *L4, *L5, *L6, *L7 ;
	char 	*a1[3]= {"Start", "Hello", "World"},
		*a2[9]={"Start", "Start", "Start",
			"Hello", "Hello", "Hello",
			"World", "World", "World"},
		*a3[3]= {"a", "d", "d"},
		*a4[5]= {"a", "c", "d", "e", "f"},
		*a5[1]= {"k"},
		*a6[3]= {"a", "k", "z"};
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
	L5= SLL_cons ("d", NULL);
	L5 = SLL_cons("a", L5);
	L5= SLL_cons("d", L5);
	// L5 = ("d") -> ("a") -> ("d")
	L6= SLL_cons ("z", NULL);
	L6= SLL_cons ("a", NULL);
	// L6 = ("a") -> ("z")
	L7= SLL_cons("k", NULL);
	// L7 = ("k") 
	
	/* Testing SLL_cons */
	SLLcheck(L3, a1);
	
	/* Testing SLL_same */
	checkit_int(SLL_same(NULL,NULL), 1);
	checkit_int(SLL_same(L3, L4), 1);
	checkit_int(SLL_same(L1, L3), 0);

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

	/* Testing insertOrder */
	SLLcheck(L7, a5);
	SLLcheck(insertOrder(L7, NULL), a5);
	SLLcheck(insertOrder(L7, L6), a6); 

	/* Testing SLL_mergeAndOrder */
	SLLcheck(SLL_mergeAndOrder(NULL, L5), a3);
	SLLcheck(SLL_mergeAndOrder(L1, L2), a4);

	/* SLL_same is up top ^^ */

	return 0;
}
