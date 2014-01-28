/* Rachel Carandang, rcarandang */
/* CS 152, Summer 2013 */
/* Homework 3 */

#include<stdio.h>
#include<math.h>
#include"checkit.h"

float mean(float a[], int len);
float stdev(float a[], int n);
float zScores(float a[], float z[], int n);
int numOutliers(float a[], float z[], int n);
void outliers(float a[], float z[], int n);

int main(void) {
	int i;
	float a1[12] = {64, 98, 66, 60, 67, 64, 70, 73, 59, 75, 35, 75};
	float z1[12] = {0};
	/* expected z-scores */
	float testZ1[12] = {-0.219489, 2.137129, -0.080864, -0.496738, 
				 -0.011552, -0.219489, 0.196385, 0.404322,
				  -0.566050, 0.542946, -2.229545, 0.542946,};
	float a2[9] = {-1.1, -1.1, 1, 1, 1, 1, 1, 1, 4};
	float z2[9] = {0};
	/* expected z-scores */	
	float testZ2[9] = {-1.3236, -1.3236, .08974, .08974, .08974, 
				.08974, .08974, .08974, 2.10895};
	/* array of one element */
	float a3[1]={5};
	float z3[1]={0};

	/* Problem 1 tests */
	checkit_float(mean(a1, 12) , 67.166667);
	checkit_float(mean(a2, 9), 0.86667);

	/* Problem 2 tests */	
	checkit_float(stdev(a1, 12) , 14.427457);
	checkit_float(stdev(a2, 9), 1.4857);
	stdev(a3, 1);

	/* Problem 3 tests */
	zScores(a1, z1, 12);
	for (i = 0; i < 12; i++) {
		checkit_float(z1[i], testZ1[i]);	
	}
	zScores(a2, z2, 9);
	for (i = 0; i < 9; i++) {
		checkit_float(z2[i], testZ2[i]);	
	}
	/* testing if it outputs error message */
	zScores(a3, z3, 1);

	/* Problem 4-1 tests */
	checkit_int(numOutliers(a1, z1, 12), 2);
	checkit_int(numOutliers(a2, z2, 9), 1);
	
	/* Problem 4-2 tests */ 
	printf("Test : Expect 98.0, 35.0\n");
	outliers(a1 , z1 , 12);
	printf("Test : Expect 4.0\n");
	outliers(a2, z2, 9);
	return 0;
}

/* Problem 1 */

float mean(float a[], int len){
	int i;
	float sum = 0.0f;
	for(i = 0 ; i < len; i++) {
	sum += a[i];	
	}
return sum / ((float)len);
}

/* Problem 2 */

float stdev(float a[], int n) {
	int i;
	float sum = 0.0f;
	float mu = mean(a, n);
	if (n==1) {
		printf("error: cannot take std. dev. of one value\n");
		return 0;
	}
	else {
		for (i = 0; i < n; i++) {
		sum += (a[i] - mu)*(a[i]-mu);
		}
	return sqrtf(sum / ((float)n - 1));
	}
}

/* Problem 3 */

//grader: This should return void, not a float. -1
float zScores(float a[], float z[], int n) {
	int i;
	float mu = mean(a, n);
	float sigma = stdev(a, n);
	for (i = 0; i <n; i++) {
		z[i] = (a[i] - mu) / sigma;
	}
	return;
}

/* Problem 4-1 */

//grader: You should only take a, not z. You should create z in your function. -1 
int numOutliers(float a[], float z[], int n) {
	int i;	
	float sum = 0.0f;
	zScores(a, z, n);
	for (i = 0; i < n; i++) {
	    //grader: I guess this works but you really shouldn't try to add boolean
	    //        qualities. Just do an if statement and add if it's true. -1
		sum += ((z[i] > 2.0f)||(z[i] < -2.0f));
	}
	return sum;
}

/* Problem 4-2 */	

//grader: You should only take a, not z. You should create z in your function. -1 
void outliers(float a[], float z[], int n) {
	int i;
	zScores(a, z, n);
	printf("Outliers: ");
	for (i = 0; i < n; i++) {
		if ((z[i] > 2.0f )||(z[i] < -2.0f))
			printf(" %.1f ", a[i]);
	}
	printf("\n");
	return;
}
			


