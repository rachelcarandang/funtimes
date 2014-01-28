/* Rachel Carandang, rcarandang */
/* CS152, Summer 2013 */
/* HW#1: Problem #3 */

#include <stdio.h>

/* The series of if statements are unnecessary. Using integer division
   rules you can do this without the if statements */

int main(void) {
	float init;
	int remSoFar;
	printf("Enter amount:");
	scanf("%f", &init);
	/* Converting given dollar amount (float) into cents (integer), so 
	we can begin integer division */
	remSoFar= init * 100;
	/* remSoFar represents the "remainder so far", aka the remaining
	portion of the money, in cents, that needs to broken up into
	bills and coins. It is updated each time the money is broken up. */
	/* Checking if remSoFar can be broken up into $100 bills*/
	if (remSoFar >= 10000) {
		/* Dividing remSoFar by 10000 and printing the whole 			
		number (integer) portion of the result, which represents
		the number of $100 bills needed, since we are working in
		cents. */
		printf("$100 bills: %d\n", remSoFar / 10000);
		/* Updating remSoFar. remSoFar, the remainder, now
		represents the remaining portion of the money that still
		needs to be broken up into bills and coins. */ 
		remSoFar %= 10000;
	}
	/* If remSoFar is less than 10000 cents, the program
	prints that no $100 bills are needed. */
	else 
		printf("$100 bills: 0\n");
	/* Continuing division by each bill and coin increment, in the
	same manner as above. At each if-statement below, remSoFar is 		
	updated. */
	if (remSoFar >= 5000) {
		printf("$50 bills: %d\n", remSoFar / 5000);
		remSoFar %= 5000;
	}
	else 
		printf("$50 bills: 0\n");
	if (remSoFar >= 2000) {

		printf("$20 bills: %d\n", remSoFar / 2000);
		remSoFar %= 2000;
	}
	else 
		printf("$20 bills: 0\n");
	if (remSoFar >= 1000) {
		printf("$10 bills: %d\n", remSoFar / 1000);
		remSoFar %= 1000;
	}
	else 
		printf("$10 bills: 0\n");
	if (remSoFar >= 500) {
		printf("$5 bills: %d\n", remSoFar / 500);
		remSoFar %= 500;
	}
	else 
		printf("$5 bills: 0\n");
	if (remSoFar >= 100) {
		printf("$1 bills: %d\n\n", remSoFar / 100);
		remSoFar %= 100;
	}
	else 
		printf("$1 bills: 0\n\n");
	if (remSoFar >= 25) {
		printf("$.25 cents: %d\n", remSoFar / 25);
		remSoFar %= 25;
	}
	else 
		printf("$.25 cents: 0\n");
	if (remSoFar >= 10) {
		printf("$.10 cents: %d\n", remSoFar / 10);
		remSoFar %= 10;
	}
	else 
		printf("$.10 cents: 0\n");
	if (remSoFar >= 5) {
		printf("$.05 cents: %d\n", remSoFar / 5);
		remSoFar %= 5;
	}
	else 
		printf("$.05 cents: 0\n");
	/* remSoFar must be between 0 and 5, so remSoFar is the number
	of pennies needed */
	printf("$.01 cents: %d\n", remSoFar);
   return 0;
}
