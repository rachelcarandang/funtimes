/* Rachel Carandang, rcarandang */
/* CS152, Summer 2013 */
/* HW#1: Problem #1 */

#include <stdio.h>

/* negative imput should yield 0 tax */

int main(void) {
    float income;
    printf("Enter amount of taxable income: ");
    scanf("%f", &income);
    if (income <= 650.0f) income *= .02;
    else if (income <= 2375.0f) income = 45.36 + .03 * (income - 650);
    else if (income <= 3239.0f) income = 75.71 + .04 * (income - 2375);
    else if (income <= 6039.0f) income = 123.12 + .05 * (income - 3239);
    else if (income <= 8412.0f) income = 178.93 + .06 * (income - 6039);
    else income = 303.36 + .07 * (income - 8412);
    printf("Tax Due: $%.2f\n", income);
   return 0;
}
