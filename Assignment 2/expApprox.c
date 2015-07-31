/*  Assignment 2
 *  Name: Evan Laia
 *  Partner's name:
 *  CS 1713 Summer 2015
 *  DISCLAIMER:
 *  MUST BE COMPILED gcc expApprox.c -o expApprox -lm
 *  OR ELSE THE MATH LIBRARY WILL NOT BE RECOGNIZED
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
/*
 * input: integer n>=0
 * output: n! as a double
 */
double factorial(int n)
{
    //set initial resultF value to 1
    double resultF = 1;
    while (n>1)
    {
        //finds the factoral and decrements n
        resultF = resultF * n;
        n--;
    }
    //returns the result of the factoral
    return resultF;

}

/*
 * input: double x and integer n>=0
 * output: return approximation of e^x as a double
 *         quality of approximation increases with n
 */
double exponent(double x, int n)
{
    int i;
    
    //sets the intital value of the result to 1
    double resultE = 1;
    
    //so long as n>0, the function will continue to approximate
    while (n>0)
    {
        resultE = pow(x, n)/factorial(n) + resultE;
        n--;
    }
    return resultE;
}

int main(void)
{
    int n, i;
    double x;
    double exactValue;
    double resultAll = 0;
    
    //get value of n from user, keep asking until n>0
    do {
        printf("Please enter the value for the integer n: \n");
        scanf("%d", &n);
    } while ((n < 0)); {
    
    //to let the user know they entered a valid int    
    printf("Thanks!\n");
   
    }
    
    printf("Please enter the value for the double x: \n");
    scanf("%lf", &x);
    
    //header for the table
    printf("          i    Approximation        \n");
    printf("----------------------------------\n\n");
    
    /*calls the exponent function to continuiously approximate the value of
    the natural exponent*/
    for (i=0;i<=n;i++) {
        resultAll = exponent(x, i);
        printf("%11i    %.10lf\n", i, resultAll);    
    }
    
    //calculate the exact value of the natural exponent
    exactValue = exp(x);
    printf("         Exact Value: %lf", exactValue);
    return 0;
}
