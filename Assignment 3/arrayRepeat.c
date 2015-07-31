/*  Assignment 3
 *  Name: Evan Laia
 *  Partner's name: 
 *  CS 1713 Summer 2015
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/*
 * input: integer array
 * output: none
 *
 * Read in 10 integers from the user and` store them in
 * the given array.
 */
void readArray(int data[])
{
    int i;
    //stores 10 integers in data[]
    printf("Hello! Please enter 10 integers. Press enter after each int:\n");
    for (i = 0; i <= 9; i++) {
        scanf("%d", &data[i]);
    }
    
    //prints the full array for user
    printf("Complete! Here is your array: \n");
    for (i = 0; i <= 9; i++){
        printf("%d ", data[i]);
    }
    
    return;
    
}

/*
 * input: integer array and integer
 * output: return the number of times that the integer
           value occurs in the array.
 */
int numOccurrences(int data[], int value)
{
    
    int i;
    int occCount = 1;
    //if data[i] is equal to the int value, increase the count
    for (i = 0; i <10; i++) {
        if (data[i] == value)
        occCount++;
    }
    
    return occCount;

}

/*
 * input: integer array
 * output: return index of first non-repeated element
 *         or -1 if there is no such element.
 */
int findNonRepeat(int data[]) {

    int i;
    int repCount;
    
    for (i = 0; i < 10; i++) {
        //calls function numOccurances, sets repCount = to the returned value of numOccurances
        repCount = numOccurrences(data, data[i]);
            //if a number occurs only once, return its index
            if (repCount == 2) //== 2 becuase it occurs once in the test and once in the array, so once 
                return i;
    }
    //if the function falls out of the for loop, return -1 (no nonrepeating value)
    return -1;
}
    
int main(void)
{
    int data[10];
    int repCount;
    //call readArray, save in data
    readArray(data);
    //call findNonRepeat, sets repCount returned value (index or -1)
    repCount = findNonRepeat(data);
    //if repCount is withing the number of indexs
    if (repCount >= 0 && repCount <=9) {
        
        printf("\nFirst non-repeating element: %d\n", data[repCount]); //repCount = index
    
    } else if (repCount == -1)
        
        printf("\nThere is no non-reapeating element\n"); //repCount = -1
    
    return 0;
}
