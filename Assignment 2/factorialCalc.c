/*  Assignment 2
 *  Name: Evan Laia
 *  Partner's name:
 *  CS 1713 Summer 2015
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double factorial(int);
int main(void)
{
    int n;
    printf("Please enter an integer greater than or equal to 0: \n");
    scanf("%d", &n);
    if (n >= 0) {
        printf("Thanks!\n");
        printf("%d! = %.10f\n", n, factorial(n));
    
    } else {
    printf("Error invalid input!");
    exit(1);
    }
    
}

/*
 * input: integer n>=0
 * output: n! as a double
 */
double factorial(int n)
{
int i;
long resultF = 1;

    for (i = 1;i <= n;i++) {
        resultF = resultF * i;
    }
    /*printf("The factorial of %d = %d\n", n, factorial);*/
    return resultF;
}


/*
 * input: double x and integer n>=0
 * output: return approximation of e^x as a double
 *         quality of approximation increases with n
 */
/*double exponent(double x, int n)
{

}*/


