/* Rachel Carandang, rcarandang */
/* CS152, Summer 2013 */
/* Homework 2 */

/* Problem 1-A  
sources: 
en.wikipedia.org/wiki/Greatest_common_divisor#Using_Euclid.27s_algorithm, 
www.proofwiki.org/wiki/GCD_with_Zero,
http://www.proofwiki.org/wiki/GCD_for_Negative_Integers*/ 

#include <stdio.h>
#include <math.h>

int gcd(int n, int m) {
	int oldM;
	/* gcd of negative numbers is the same gcd as its positive counterpart */ 
	n = abs (n);
	m = abs (m);
	if (n < m) {
		/* switching n and m so n is larger, so division will work*/
		oldM = m;
		m = n;
		n = oldM;
	}
	while (m > 0) {
		oldM = m;
		m = n % m;
		n = oldM;
	}
	return n;	
}

/* Problem 1-B */

void reduce (void) {
	int a, b, oldA;
	printf("Enter in a fraction: ");
	scanf ("%d/%d", &a, &b);
	oldA = a;
        //grader: Better to store the gcd than store a. The gcd needs to be
        //        recalculated which can take a while for larger numbers.
	a /= gcd (a, b);
	b /= gcd (oldA, b);
	if ((a == 0) || (b == 1))
		printf("Reduced form: %d\n", a);
	else
		printf("Reduced form: %d/%d\n", a, b); 	
	return; 
}

/* Problem 2 */

void getStats(void) {
	int i = 0;
	float num, min, max, sum = 0.0f;
	char go = 'y';
	while ((go == 'y') || (go == 'Y')) {
		printf ("Enter number #%d: ", ++i);
		scanf("%f", &num);
		if (i == 1) {
			min = num;
			max = num;
		}
		else if (num < min) 
			min = num;
		else if (num > max)
			max = num;
		sum += num;
		printf("Do you want to enter another number? ");
		scanf(" %c", &go);
		while ((go != 'y') && (go != 'Y') && (go != 'n') && 
			(go != 'N')) {
			printf ("error: must enter 'y', 'Y', 'n', or 'N'\n");
			printf ("Do you want to enter another number? ");
			scanf(" %c", &go);
		}
		
	}
	printf ("The smallest number is %f, and the largest number is %f\n", 			
			min, max);
	printf ("The average is %.2f\n", sum / (float)i);
	return;
}

/* Problem 3 */
unsigned int sumOfDigits(unsigned int x) {
	unsigned int digitSum = 0;	
	while (x != 0) {
		digitSum += (x % 10);
		x /= 10;
	}
	return digitSum;
}

/* Problem 4 */
int luhn(unsigned int y) {
	unsigned int checkDigit, checkSum = 0;
	/* storing one's digit */
	checkDigit = y % 10; 
	do {/* removing right-most digit */
		y /= 10;
		/* doubling new right-most digit, and taking digit-sum of result */
		checkSum += sumOfDigits(2 *(y % 10));
		/* removing the digit you just added to sum */
		y /= 10; 
		/* adding new right-most digit to sum */
		checkSum += y % 10;
	} while ((y / 10) > 0 );  
	/* Verifying check digit is correct */
	return ((10 - checkSum % 10) == checkDigit);
}

int main(void) {
	printf("gcd (-18, 48): %d\n", gcd(-18, 48));
	printf("gcd (18, -48): %d\n", gcd(18, -48));
	printf("gcd (-18, -48): %d\n", gcd(-18, -48));
	printf("gcd (0, -5): %d\n", gcd(0, -5));
	printf("gcd (0, 0): %d\n", gcd(0,0));
	int i = -18, j = -16, k = -534;
	printf("luhn(0): %d\n", luhn(0));
	printf("luhn(26): %d\n", luhn(26));
	printf("luhn(4): %d\n", luhn(4));
	printf("luhn(-158): %d\n", luhn(-158));
	printf("sum: %d\n", sumOfDigits(i));
	printf("sum: %d\n", sumOfDigits(j));
	printf("sum: %d\n", sumOfDigits(k));
	getStats();
	printf("gcd (5, 1): %d\n", gcd(5, 1));
   	return 0;
}

