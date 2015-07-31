/*  Assignment 4
 *  Name: Evan Laia
 *  Partner's name: Cordan W.
 *  CS 1713 Summer 2015
 */

 /* Questions:
    1) What difference did you notice in the addresses between the different types (int, char, and double)?
    (hint: The addresses are printed in hexidecimal.  You can convert these to decimal numbers using an online
    converter and then compare them)
    
    Well all addresses started with 1407346312220. The addresses of the integers increased by 4 (bytes?) each time,
    the characters by 1, and the doubles by 8.  

    2) Why do you think this difference occurs?
    
    This represents what I believe to be the default memory size of different values. An iteger is 4 bytes or 
    whatever small value this happened to be, a double is double that, at 8, and  a character is 1. Different
    values have different memory sizes.

  */

#include <stdio.h>

/*
`*  create an array of 5 integers and print the addresses of its elements
 */
void intAddress(void)
{
    int intArray[5] = {1, 2, 3, 4, 5};
    int i;
    
    for (i=0;i<=4;i++) {
        printf("The position of %d is %p.\n", intArray[i], &intArray[i]);
    }
}

/*
`*  create an array of 5 characters and print the addresses of its elements
 */
void charAddress(void)
{
    char charArray[5] = {'a', 'b', 'c', 'd', 'e'};
    int i;
    for (i=0;i<=4;i++) {
        printf("The position of %c is %p.\n", charArray[i], &charArray[i]);
    }
}

/*
`*  create an array of 5 doubles and print the addresses of its elements
 */
void doubleAddress(void)
{
    double doubleArray[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int i; 
    for (i=0;i<=4;i++) {
        printf("The position of %f is %p.\n", doubleArray[i], &doubleArray[i]);
    }
}

/*
`*  Do not modify this code.
 */
int main(void)
{
    printf("Int array addresses:\n");
    intAddress();

    printf("\n\nChar array addresses:\n");
    charAddress();

    printf("\n\nDouble array addresses:\n");
    doubleAddress();

    return 0;
}
