/* Rachel Carandang, rcarandang */
/* CMSC 2, Summer 2013 */
/* Homework 5*/

#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#endif

