/* Rachel Carandang, rcarandang */
/* CS152, Summer 2013 */
/* HW#1: Problem #2 */

#include <stdio.h>

int main(void) {
	int m1, d1, y1, m2, d2, y2;
	printf("Enter first date (mm/dd/yy):");
	scanf("%d/%d/%d", &m1, &d1, &y1);
	printf("Enter second date (mm/dd/yy):");
	scanf("%d/%d/%d", &m2, &d2, &y2);
	if (y1==y2 && m1==m2 && d1==d2)
		printf("%02d/%02d/%02d and %02d/%02d/%02d are the same date\n",
			m1, d1, y1, m2, d2, y2);
	/* The three logical expressions below are the only three cases 	
	in which the first date is less than the second date */
	else if (y1 < y2 || y1==y2 && m1 < m2 || y1==y2 && m1==m2 && d1 < d2)
		printf("%02d/%02d/%02d is earlier than %02d/%02d/%02d\n", 
			m1, d1, y1, m2, d2, y2);
	/* In all remaining cases, the second date must be earlier than 	
	the first date */
	else 
		printf("%02d/%02d/%02d is earlier than %02d/%02d/%02d\n", 
			m2, d2, y2, m1, d1, y1);
   return 0;
}
