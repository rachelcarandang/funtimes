/* Rachel Carandang, rcarandang */
/* CS152, Summer 2013 */
/* Lab 2 */

#include <stdio.h>
void menu(void);
void newMatrix(int a[][5], int n, int m);
void rowTotals(int a[][5], int n, int m);
void colTotals(int a[][5], int n, int m);
void repeated(int a[][5], int n, int m);

int main(void) {
	int a[5][5] = {0};
	menu();
   return 0;
}

void menu(void) {
	int option;
	static int a[5][5]={0};
	printf("\n\nWelcome to the Matrix Program\n");
	printf("(1): Read in a 5x5 matrix.\n");
	printf("(2): Print the row totals in a the matrix.\n");
	printf("(3): Print the column totals in the amtrix..\n");
	printf("(4): Find a repeated number.\n");
	printf("(5): Quit.\n");
do {printf("Option #: ");
	scanf("%d", &option);
	if (option == 1) newMatrix(a, 5, 5);
	if (option == 2) rowTotals(a, 5, 5);
	if (option == 3) colTotals(a, 5, 5);
	if (option == 4) repeated(a, 5, 5);
} while ((option < 1) || (option > 5));
return;
}

void newMatrix(int a[][5], int n, int m) {
	int i, j, x;
	for (i=0; i<n; i++) {
		printf("Enter row %d: ", i+1);
		for (j=0; j<m; j++) {
			scanf("%d", &x);
			a[i][j] = x;
		}
	}
	menu();
	return;
}

void rowTotals(int a[][5], int n, int m) {
	int i, j, x, rowSum;
	printf("Row Totals: ");
	for (i=0; i<n; i++) {
		rowSum=0;
		for (j=0; j<m; j++) 
			rowSum += a[i][j];
		printf("%d ", rowSum);
	}
	printf("\n");
	menu();
	return;
}

void colTotals(int a[][5], int n, int m) {
	int i, j, x, colSum;
	printf("Column Totals: ");
	for (j=0; j<m; j++) {
		colSum=0;
		for (i=0; i<n; i++) 
			colSum += a[i][j];
		printf("%d ", colSum);
	}
	printf("\n");
	menu();
	return;
}
	
		
void repeated(int a[][5], int n, int m) {
	int i, j, x, y, freq = 0;
	printf("Enter in a number: ");
	scanf("%d", &x);
	printf("Enter in the number of times the %d should occur in the matrix:", x);	
	scanf("%d", &y);
	for (i=0; i<n; i++) 
		for (j=0; j<m; j++) 
			freq += (x == a[i][j]);
	if (freq == y)
		printf("Found the number %d in the matrix %d times\n", x, y);
	else 
		printf("Did not find the number %d in the matrix %d times\n", x, y);
	menu();
	return;
}	
		




