/*  Assignment 1
 *  Name: Evan Laia
 *  Partner's name: N/A
 *  CS 1713 Summer 2015
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* variable declaration */
    char tempScale;
    int morningTemp;
    int noonTemp;
    int eveningTemp;
    double tempAvg;
    double newTempAvg;
    
    /* get scale from user */
    printf("Please enter the temperature scale. c, C, f, F are acceptable answers: \n");
    scanf("%s", &tempScale);
    
    /* check if user entered illegal scale */
    if(tempScale == 'c' || tempScale == 'C' || tempScale == 'f' || tempScale == 'F')
    {
        printf("Thanks!\n");
        
    } else 
        exit(1);
    
    /* get morning temp from user */
    printf("Please enter the morning temperature as an integer: \n");
    scanf("%d", &morningTemp);
    
    /* get afternoon temp from user */
    printf("Please enter the afternoon temperature as an integer: \n");
    scanf("%d", &noonTemp);
    
    /* get evening temp from user */
    printf("Please enter the evening temperature as an integer: \n");
    scanf("%d", &eveningTemp);
    
    /* compute average */
    tempAvg = ((morningTemp + noonTemp + eveningTemp) / 3.0);
    
    /* print user entered temps and average */
    printf("Morning Temperature: %d%c\n", morningTemp, tempScale);
    printf("Afternoon Temperature: %d%c\n", noonTemp, tempScale);
    printf("Evening Temperature: %d%c\n", eveningTemp, tempScale);
    printf("Average Temperature: %.2lf%c\n", tempAvg, tempScale);

    /* convert average to other scale and print out */
    if (tempScale == 'c' || tempScale == 'C')
    {
        newTempAvg = tempAvg * 1.8 + 32;
        printf("Average Temperature in Fahrenheit: %.2lfF\n", newTempAvg);
    }
  
    else if (tempScale == 'f' || tempScale == 'F')
    {
        newTempAvg = (tempAvg - 32) / 1.8;
        printf("Average Temperature in Celsius: %.2lfC\n", newTempAvg);
    }

    return 0;
}